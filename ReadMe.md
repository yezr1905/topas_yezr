# TOPAS_yezr

This project builds upon the highly efficient and user-friendly [TOPAS](https://www.topasmc.org/) framework, originally designed for Monte Carlo simulations in medical physics and powered by the Geant4 toolkit. *Visit [TOPAS official website](https://www.topasmc.org/) for more information about the original platform.*

Recognizing the need for broader compatibility and updated features, this version of TOPAS has been modified to support the latest [Geant4](https://geant4.web.cern.ch/download/11.2.1.html) version (11.2.1), and to ensure compilation and operation on Windows platforms.

*(This project is not officially associated with the original TOPAS development team but is an independent initiative to extend its capabilities and reach. For any questions or contributions, please feel free to open an issue or submit a pull request.)*

## Features

- **support for the latest version of Geant4**
- **support for installation on Windows system**
- **easy customization**
- **lean structure**
- **without graphics, use TOPAS instead**

## Benchmark

**It is strongly recommended to run large simulations on Linux system!**

| System              | Compiler    | CPU                                     | CPU Threads | CPU Usage | Physics List | Particle histories | Time (s)  | Ratio  |  Mark   |
| ------------------- | ----------- | --------------------------------------- | ----------- | --------- | ------------ | ------------------ | --------- | ------ | :-----: |
| Ubuntu 22.04        | g++ 11.3.0  | Dual Intel Xeon CPU E5-2698 v4 2.20 GHz | 80          | 3827.1%   | FTFP_BERT    | alpha 100 MeV 5e6  | 13.2989 s | 1.5495 | 23617*2 |
| Ubuntu 22.04        | g++ 11.4.0  | Dual AMD EPYC 7763 2.45 GHz             | 256         | 2934.8%   | FTFP_BERT    | alpha 100 MeV 5e6  | 16.1188 s | 1.2784 | 85202*2 |
| Windows 10          | VS2022 v143 | Intel Core i7-12700 2.10 GHz            | 16          | 1402.8%   | FTFP_BERT    | alpha 100 MeV 5e6  | 20.6061 s | 1      |  30834  |
| Windows 10          | VS2022 v143 | Intel Core i5-12400F 2.5 GHz            | 12          | 1029.5%   | FTFP_BERT    | alpha 100 MeV 5e6  | 24.5835 s | 0.8382 |  19430  |
| Windows Server 2022 | VS2022 v143 | Dual AMD EPYC 7763 2.45 GHz             | 256         | 3092.6%   | FTFP_BERT    | alpha 100 MeV 5e6  | 170.127 s | 0.1211 | 85202*2 |
| Windows Server 2022 | VS2022 v143 | Dual Intel Xeon E5-2696 v3 2.30 GHz     | 72          | 3545.7%   | FTFP_BERT    | alpha 100 MeV 5e6  | 75.2194 s | 0.2739 | 22371*2 |
| Windows Server 2022 | VS2022 v143 | Dual Intel Xeon E5-2678 v3 2.50 GHz     | 48          | 4644.8%   | FTFP_BERT    | alpha 100 MeV 5e6  | 118.635 s | 0.1737 | 14675*2 |

*i:Ts/NumberOfThreads =0*

*CPU Mark from: [PassMark Intel vs AMD CPU Benchmarks - High End](https://www.cpubenchmark.net/high_end_cpus.html)*

## Konwn issues

- When running solely on the Windows system, support for the modular physics list is unavailable.
  - **Error Location**: Found in `void TsModularPhysicsList::ConstructProcess()` within `\physics\TsModularPhysicsList.cc` at `G4MT_physicsVector->begin()`

## Installing

### Windows

Build and Install from Source

- Install Geant4 v11.2.1 first, *without OpenGL or Qt*
- Install TOPAS_yezr
  - Configure CMake, usually only edit `CMAKE_INSTALL_PREFIX`
  - Build in Visual Studio, `ALL_BUILD` first, then `INSTALL`
  - The build type (Release, RelWithDebInfo and Debug) of TOPAS_yezr should be the same as that of Geant4

### Linux

```shell
>>>> Ubuntu22 Docker container
Ubuntu 22.04
Geant4 v11.2.1
remove libs: extensions outcome chemistry graphics
remove functions: GDCM (DICOM XIO) ROOT (root outcome)
use official topas for graphics function (only G4Data for Geant4 v11.2.1)



apt update
apt install -y libexpat1-dev
apt install -y libgl1-mesa-dev
apt install -y libglu1-mesa-dev
apt install -y libxt-dev
apt install -y xorg-dev
apt install -y build-essential
apt install -y libharfbuzz-dev
apt install -y unzip cmake
apt install -y openssh-server g++ gdb make ninja-build rsync zip

cd /opt
# wget https://gitlab.cern.ch/geant4/geant4/-/archive/v11.2.1/geant4-v11.2.1.zip
unzip geant4-v11.2.1.zip

rm -rf /opt/geant4-v11.2.1-install
rm -rf /opt/geant4-v11.2.1-build
mkdir /opt/geant4-v11.2.1-build
cd /opt/geant4-v11.2.1-build
cmake /opt/geant4-v11.2.1 -DGEANT4_INSTALL_DATA=OFF -DGEANT4_BUILD_MULTITHREADED=ON -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/opt/geant4-v11.2.1-install -DGEANT4_INSTALL_DATADIR=/opt/G4Data
make -j200
make install

cd /opt
rm -rf /opt/geant4-v11.2.1-build
rm -rf topas_yezr
unzip topas_yezr.zip

rm -rf /opt/topas_yezr-install
rm -rf /opt/topas_yezr-build
mkdir /opt/topas_yezr-build
cd /opt/topas_yezr-build
export Geant4_DIR=/opt/geant4-v11.2.1-install
cmake /opt/topas_yezr -DTOPAS_TYPE=public -DCMAKE_INSTALL_PREFIX=/opt/topas_yezr-install -DGeant4_Lib_DIR=/opt/geant4-v11.2.1-install/lib -DCMAKE_PREFIX_PATH=/opt/geant4-v11.2.1-install/lib
make -j200
make install

cd /opt/topas_yezr-install/lib

rm libG4ptl.so
ln -s libG4ptl.so.2.3.3 libG4ptl.so.2
ln -s libG4ptl.so.2 libG4ptl.so

cd /opt
rm -r topas_yezr-build
rm topas_yezr.zip

tar -pczf topas_yezr_ubuntu22.tar.gz topas_yezr-install

>>> Test in new terminal window:
vim /etc/profile.d/topas.sh

export TOPAS_G4_DATA_DIR=/opt/G4Data
export PATH=/opt/topas_yezr-install/bin:/opt/topas/bin:$PATH

mkdir /opt/G4Data
cd /opt/G4Data
# copy database for Geant4 v11.2.1
ls *.tar.gz |xargs -n1 tar -zxvf
rm *.tar.gz
source /etc/profile.d/topas.sh

cd /opt
rm -rf topas
# Download topas_yezr_ubuntu22.tar.gz and topas topas_3_9_debian9.tar.gz.part_*
tar -zxf topas_yezr_ubuntu22.tar.gz
cat topas_3_9_debian9.tar.gz.part_* > topas_3_9_debian9.tar.gz
tar -zxvf topas_3_9_debian9.tar.gz
rm topas_3_9_debian9*

topas_yezr /opt/Test.txt
topas /opt/QtTest.txt

>>>> Debug in Visual Studio remotely
apt install -y openssh-server g++ gdb make ninja-build rsync zip
# xauth -f ~root/.Xauthority list|tail -1
# export DISPLAY=localhost:$(xauth -f ~root/.Xauthority list | tail -1 | awk -F 'unix:' '{print $2}' | awk '{print $1}')

# lauch.vs.json
{
    "version": "0.2.1",
    "defaults": {},
    "configurations": [
      {
        "type": "cppgdb",
        "name": "topas_yezr",
        "project": "CMakeLists.txt",
        "projectTarget": "topas_yezr",
        "comment": "\u4E86\u89E3\u5982\u4F55\u914D\u7F6E\u8FDC\u7A0B\u8C03\u8BD5\u3002\u6709\u5173\u8BE6\u7EC6\u4FE1\u606F\uFF0C\u8BF7\u53C2\u9605 http://aka.ms/vslinuxdebug",
        "debuggerConfiguration": "gdb",
        "MIMode": "gdb",
        "args": [
            "/opt/Test.txt"
          ],
          "env": {}
      }
    ]
  }
```

## Future development

- support for nonhomogeneous phantoms from DICOM CT files
  - Read `.mha` or `.nii` or binary files instead of DICOM CT files
  - Read binary files to get the list of materials
- Fix bugs

## Updates in Geant4 v11

[Geant4 11.0 Release Notes (cern.ch)](https://geant4.web.cern.ch/download/release-notes/notes-v11.0.0.html)

[Geant4 11.1 Release Notes (cern.ch)](https://geant4.web.cern.ch/download/release-notes/notes-v11.1.0.html)

[Geant4 11.2 Release Notes (cern.ch)](https://geant4.web.cern.ch/download/release-notes/notes-v11.2.0.html)

