#----------------------------------------------------------------------------
# Setup the project
cmake_minimum_required(VERSION 3.16...3.27)

if (CMAKE_VERSION VERSION_GREATER_EQUAL 3.17)
	cmake_policy (SET CMP0100 NEW)
endif ()

project(topas_yezr)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
set (TOPAS_VERSION_MAJOR 3)
set (TOPAS_VERSION_MINOR 9)
set (TOPAS_VERSION_PATCH 1)

set (CMAKE_AUTOMOC ON)

if (NOT CMAKE_BUILD_TYPE OR 
	NOT CMAKE_BUILD_TYPE MATCHES "Debug|RelWithDebInfo|Release")
	set (CMAKE_BUILD_TYPE "Release")
	message (WARNING "Setting CMAKE_BUILD_TYPE=Release")
endif ()	

option (TOPAS_COVERAGE "Enable coverage analysis" OFF)
option (TOPAS_MT "Enable multithreading support" ON)
option (TOPAS_WITH_STATIC_GEANT4 "Link against static Geant4 libraries" OFF)
option (TOPAS_INSTALL_EXAMPLES "Install example TOPAS files" OFF)

set (TOPAS_TYPE "public" CACHE STRING "Choose release type: expanded, educational or public")
if (NOT "${TOPAS_TYPE}" MATCHES "^(expanded|educational|public)$")
	message (FATAL_ERROR "Unrecognized TOPAS_TYPE=${TOPAS_TYPE}")
endif ()

# if (NOT Geant4_Lib_DIR)
# 	set (Geant4_Lib_DIR "/opt/geant4-v11.2.1-install/lib" CACHE STRING "installed Geant4 lib dir")
# endif()

find_package(Geant4 REQUIRED)
include(${Geant4_USE_FILE})
include_directories(${Geant4_INCLUDE_DIR}/include)
message (STATUS "Geant4_INCLUDE_DIR:  ${Geant4_INCLUDE_DIR}")
include_directories(${PROJECT_SOURCE_DIR}/include)
if ((Geant4_VERSION_MAJOR VERSION_GREATER_EQUAL 10))
	include_directories (AFTER SYSTEM ${PTL_INCLUDE_DIR})
endif()

configure_file (
	"${CMAKE_CURRENT_SOURCE_DIR}/TsTopasConfig.hh.in"
	"${CMAKE_CURRENT_BINARY_DIR}/TsTopasConfig.hh")

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang") # using GCC || CLANG
	set (CMAKE_CXX_FLAGS_WARNINGS "-Wall -Wextra -Wpedantic")
	if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
		set (CMAKE_CXX_FLAGS_WARNINGS "${CMAKE_CXX_FLAGS_WARNINGS} -Wmaybe-uninitialized")
	endif ()
	if (APPLE)
		set (CMAKE_CXX_FLAGS_BASE "")
	else ()
		set (CMAKE_CXX_FLAGS_BASE "-Wl,--disable-new-dtags")
	endif ()
	set (CMAKE_CXX_FLAGS_DEBUG "-Og -g")
	set (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")
	set (CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -fno-trapping-math -ftree-vectorize -fno-math-errno")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel") # Intel ICC
	message (WARNING "We do not support the use of the Intel compiler collection. Use this at your own risk.")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC") # Microsoft VisualC(++)
	message (WARNING "We do not support the use of MSVC. Use this at your own risk.")
	set(CMAKE_CXX_FLAGS_WARNINGS "/W4") # Set warning level to 4 (the highest warning level in MSVC)
	set(CMAKE_CXX_FLAGS_BASE "/MP") # Enable multi-processor compilation for faster builds
	set(CMAKE_CXX_FLAGS_DEBUG "/Od /Zi /MTd /RTC1") # Set debug flags: /Od (disable optimization), /Zi (generate complete debugging information), /RTC1 (runtime checks)
	set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/O2 /Zi /DNDEBUG /MTd") # Set release with debug info flags: /O2 (optimize for speed), /Zi (generate complete debugging information), /DNDEBUG (disable assert)
	set(CMAKE_CXX_FLAGS_RELEASE "/O2 /DNDEBUG /MT /GL") # Set release flags: /O2 (optimize for speed), /DNDEBUG (disable assert), /GL (whole program optimization)
	set(CMAKE_EXE_LINKER_FLAGS_RELEASE "/LTCG") # Add /LTCG to the linker flags for release builds
	set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "/LTCG") # Add /LTCG to the linker flags for shared libraries in release builds
else ()
	message (WARNING "You are using an unknown compiler. Use this at your own risk.")
endif()

message (STATUS "Prepending the following flags to CXX_FLAGS = ${CMAKE_CXX_FLAGS}")
message (STATUS "(BASICS)   ${CMAKE_CXX_FLAGS_BASE}")
message (STATUS "(WARNINGS) ${CMAKE_CXX_FLAGS_WARNINGS}")

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_BASE} ${CMAKE_CXX_FLAGS_WARNINGS} ${CMAKE_CXX_FLAGS_DEBUG} ${CMAKE_CXX_FLAGS}")
	message (STATUS "(DEBUG)    ${CMAKE_CXX_FLAGS_DEBUG}")
elseif (CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_BASE} ${CMAKE_CXX_FLAGS_WARNINGS} ${CMAKE_CXX_FLAGS_RELWITHDEBINFO} ${CMAKE_CXX_FLAGS}")
	message (STATUS "(RELW/DEB) ${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")
else () # assume Release
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_BASE} ${CMAKE_CXX_FLAGS_WARNINGS} ${CMAKE_CXX_FLAGS_RELEASE} ${CMAKE_CXX_FLAGS}")
	message (STATUS "(RELEASE)  ${CMAKE_CXX_FLAGS_RELEASE}")
endif ()

if (TOPAS_COVERAGE)
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 --coverage")
	set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 --coverage")
	if (NOT CMAKE_BUILD_TYPE STREQUAL "Debug")
		message (WARNING "Using TOPAS_COVERAGE=${TOPAS_COVERAGE} with non-Debug build type. This can cause undocumented behavior.")
	endif()
endif()

include_directories (
	${CMAKE_CURRENT_BINARY_DIR}
	${PROJECT_SOURCE_DIR}/filtering
	${PROJECT_SOURCE_DIR}/geometry
	${PROJECT_SOURCE_DIR}/io
	${PROJECT_SOURCE_DIR}/main
	${PROJECT_SOURCE_DIR}/material
	${PROJECT_SOURCE_DIR}/parameter
	${PROJECT_SOURCE_DIR}/physics
	${PROJECT_SOURCE_DIR}/primary
	${PROJECT_SOURCE_DIR}/scoring
	${PROJECT_SOURCE_DIR}/sequence
	${PROJECT_SOURCE_DIR}/variance
	${PROJECT_SOURCE_DIR}/Geant4Headers
)
add_subdirectory (filtering)
add_subdirectory (geometry)
add_subdirectory (io)
add_subdirectory (main)
add_subdirectory (material)
add_subdirectory (parameter)
add_subdirectory (physics)
add_subdirectory (primary)
add_subdirectory (scoring)
add_subdirectory (sequence)
add_subdirectory (variance)

if (APPLE)
	set (CMAKE_INSTALL_RPATH "@executable_path/../Frameworks")
elseif (UNIX)
	set (CMAKE_INSTALL_RPATH "\$ORIGIN/../lib")
else ()
	message (AUTHOR_WARNING "Target platform is not UNIXoid, not setting RPATH automatically. Good luck!")
endif ()

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(LIB_EXT ".lib")
else()
    set(LIB_EXT ".a")
endif()

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        install (FILES
            ${CMAKE_CURRENT_BINARY_DIR}/filtering/Debug/filtering${LIB_EXT}
            ${CMAKE_CURRENT_BINARY_DIR}/geometry/Debug/geometry${LIB_EXT}
            ${CMAKE_CURRENT_BINARY_DIR}/io/Debug/io${LIB_EXT}
            ${CMAKE_CURRENT_BINARY_DIR}/main/Debug/main${LIB_EXT}
            ${CMAKE_CURRENT_BINARY_DIR}/material/Debug/material${LIB_EXT}
            ${CMAKE_CURRENT_BINARY_DIR}/parameter/Debug/parameter${LIB_EXT}
            ${CMAKE_CURRENT_BINARY_DIR}/physics/Debug/physics${LIB_EXT}
            ${CMAKE_CURRENT_BINARY_DIR}/primary/Debug/primary${LIB_EXT}
            ${CMAKE_CURRENT_BINARY_DIR}/scoring/Debug/scoring${LIB_EXT}
            ${CMAKE_CURRENT_BINARY_DIR}/sequence/Debug/sequence${LIB_EXT}
            ${CMAKE_CURRENT_BINARY_DIR}/variance/Debug/variance${LIB_EXT}
            DESTINATION bin)
    elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
        install (FILES
            ${CMAKE_CURRENT_BINARY_DIR}/filtering/Release/filtering${LIB_EXT}
            ${CMAKE_CURRENT_BINARY_DIR}/geometry/Release/geometry${LIB_EXT}
            ${CMAKE_CURRENT_BINARY_DIR}/io/Release/io${LIB_EXT}
            ${CMAKE_CURRENT_BINARY_DIR}/main/Release/main${LIB_EXT}
            ${CMAKE_CURRENT_BINARY_DIR}/material/Release/material${LIB_EXT}
            ${CMAKE_CURRENT_BINARY_DIR}/parameter/Release/parameter${LIB_EXT}
            ${CMAKE_CURRENT_BINARY_DIR}/physics/Release/physics${LIB_EXT}
            ${CMAKE_CURRENT_BINARY_DIR}/primary/Release/primary${LIB_EXT}
            ${CMAKE_CURRENT_BINARY_DIR}/scoring/Release/scoring${LIB_EXT}
            ${CMAKE_CURRENT_BINARY_DIR}/sequence/Release/sequence${LIB_EXT}
            ${CMAKE_CURRENT_BINARY_DIR}/variance/Release/variance${LIB_EXT}
            DESTINATION bin)
    endif()
else ()
    install (FILES
        ${CMAKE_CURRENT_BINARY_DIR}/filtering/libfiltering${LIB_EXT}
        ${CMAKE_CURRENT_BINARY_DIR}/geometry/libgeometry${LIB_EXT}
        ${CMAKE_CURRENT_BINARY_DIR}/io/libio${LIB_EXT}
        ${CMAKE_CURRENT_BINARY_DIR}/main/libmain${LIB_EXT}
        ${CMAKE_CURRENT_BINARY_DIR}/material/libmaterial${LIB_EXT}
        ${CMAKE_CURRENT_BINARY_DIR}/parameter/libparameter${LIB_EXT}
        ${CMAKE_CURRENT_BINARY_DIR}/physics/libphysics${LIB_EXT}
        ${CMAKE_CURRENT_BINARY_DIR}/primary/libprimary${LIB_EXT}
        ${CMAKE_CURRENT_BINARY_DIR}/scoring/libscoring${LIB_EXT}
        ${CMAKE_CURRENT_BINARY_DIR}/sequence/libsequence${LIB_EXT}
        ${CMAKE_CURRENT_BINARY_DIR}/variance/libvariance${LIB_EXT}
        DESTINATION lib)
endif()  

file (GLOB includesForEndUser
    "${CMAKE_CURRENT_BINARY_DIR}/TsTopasConfig.hh"
    "main/TsMain.hh"
    "parameter/TsParameterManager.hh"
    "filtering/TsVFilter.hh"
    "primary/TsPrimaryParticle.hh"
    "primary/TsSource.hh"
    "primary/TsVGenerator.hh"
    "io/TsVFile.hh"
    "io/TsVNtuple.hh"
    "scoring/TsVBinnedScorer.hh"
    "scoring/TsVNtupleScorer.hh"
    "scoring/TsVScorer.hh"
    "sequence/TsTrackInformation.hh")
    
install (FILES ${includesForEndUser} DESTINATION include)

message (STATUS "Geant4_DIR: ${Geant4_DIR}")
if (TOPAS_WITH_STATIC_GEANT4)
	if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
		file (GLOB geant4libs "${Geant4_DIR}/../../*.lib")
	else()
		file (GLOB geant4libs "${Geant4_DIR}/../*.a")
	endif()
else ()
	if (WIN32)
		file (GLOB geant4libs "${Geant4_DIR}/../../../bin/*.dll")
	elseif (APPLE)
		file (GLOB geant4libs "${Geant4_DIR}/../*.dylib")
	else()
		file (GLOB geant4libs "${Geant4_Lib_DIR}/*.so")
		message (STATUS "Geant4_Lib_DIR: ${Geant4_Lib_DIR}")
		if ((Geant4_VERSION_MAJOR VERSION_GREATER_EQUAL 10))
			file (GLOB geant4PTLlib "${Geant4_Lib_DIR}/libG4ptl.so.2.3.3")
		endif()
	endif()
endif ()

if (APPLE)
	file (GLOB expat "/usr/lib/libexpat.1.dylib")
	install (FILES
		${geant4libs}
		${expat}
		DESTINATION Frameworks)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	install (FILES ${geant4libs} DESTINATION bin)
	if ((Geant4_VERSION_MAJOR VERSION_GREATER_EQUAL 10))
		install (FILES ${geant4PTLlib} DESTINATION bin)
	endif()
else ()
    install (FILES
        ${geant4libs}
        DESTINATION lib)
	if ((Geant4_VERSION_MAJOR VERSION_GREATER_EQUAL 10))
		install (FILES ${geant4PTLlib} DESTINATION lib)
	endif()
endif ()

add_executable(topas_yezr topas.cc)
target_link_libraries (topas_yezr
	main
	parameter
	geometry
	material
	physics
	variance
	filtering
	scoring
	io
	sequence
	primary
	${Geant4_LIBRARIES}
)
message (STATUS "Geant4_LIBRARIES:  ${Geant4_LIBRARIES}")

install(FILES Test.txt DESTINATION bin)

# add_custom_target(B1 DEPENDS exampleB1)
install(TARGETS topas_yezr RUNTIME DESTINATION bin)
