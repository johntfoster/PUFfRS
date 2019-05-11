# PUFfRS

[![Build Status](https://travis-ci.org/johntfoster/PUFfRS.svg?branch=master)](https://travis-ci.org/johntfoster/PUFfRS) [![Coverage Status](https://coveralls.io/repos/github/johntfoster/PUFfRS/badge.svg?branch=master)](https://coveralls.io/github/johntfoster/PUFfRS?branch=master)

This is the **P**artition-of-**U**nity **F**ramework **f**or **R**eservoir **S**imulation project. It utilizes the Trilinos Project for increase computational efficiency and is currently in development.


## Requirements for PUFfRS

C++ - version xx.xx
OpenMPI - version xx.xx
Trilinos - most recent version
Boost - version xx.xx
yaml-cpp - version xx.xx


## Build instructions

**Build Only Required Packages**
This will install essential parts of Trilinos, Boost, yaml-cpp, and PUFfRS:
```
cd puffrs_dir
mkdir build
cd build

sudo cmake -DBUILD_ALL_TPS=ON ..
sudo make
sudo make install
```

**Build Using Pre-existing Packages**
This will install only PUFfRS:
NEED COMMANDS FROM AKHIL
```
cd puffrs_dir
mkdir build
cd build

cmake -D
make
make install
```

