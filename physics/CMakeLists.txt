file(GLOB TOPAS_PHYSICS_SRC CONFIGURE_DEPENDS
    "*.hh"
    "*.cc"
)

add_library(physics ${TOPAS_PHYSICS_SRC})
