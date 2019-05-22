Installation
============

This is the Partition-of-Unity Framework for Reservoir Simulation project. It utilizes the Trilinos Project for increase computational efficiency and is currently in development.


Requirements for PUFfRS
-----------------------

1. C++ Complier - version 5.4.0+
2. OpenMPI - version 1.10.2+
3. Trilinos - most recent version
4. Boost - please check Trilinos documentation
5. yaml-cpp - please check Trilinos documentation


Build instructions
------------------

**Build Only Required Packages**
This will install essential parts of Trilinos, Boost, yaml-cpp, and PUFfRS::

   cd puffrs_dir
   mkdir build
   cd build

   sudo cmake -DBUILD_ALL_TPS=ON ..
   sudo make
   sudo make install

**Build Using Pre-existing Packages**
This will install only PUFfRS::

   cd puffrs_dir
   mkdir build
   cd build

   cmake -DTrilinos_DIR=/path/to/trilinos/installation/ ..
   make
   make install

