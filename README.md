# PUFfRS

[![Build Status](https://travis-ci.org/johntfoster/PUFfRS.svg?branch=master)](https://travis-ci.org/johntfoster/PUFfRS) [![Coverage Status](https://coveralls.io/repos/github/johntfoster/PUFfRS/badge.svg?branch=master)](https://coveralls.io/github/johntfoster/PUFfRS?branch=master)

This is the **P**artition-of-**U**nity **F**ramework **f**or **R**eservoir **S**imulation project. It utilizes the Trilinos Project for increased computational efficiency and is currently in development.


## Requirements for PUFfRS

C++ Complier - version 5.4.0+  
OpenMPI - version 1.10.2+  
  
Trilinos:  
	Please apt install the following packages:  
	```sudo apt install libblas-dev libyaml-cpp-dev liblapack-dev```  
	Boost - please check Trilinos documentation  
	yaml-cpp - please check Trilinos documentation  


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
This will install only PUFfRS using an existing Trilinos installation:
```
cd puffrs_dir
mkdir build
cd build

cmake -DTrilinos_DIR=/path/to/trilinos/installation/ ..
make
make install
```

