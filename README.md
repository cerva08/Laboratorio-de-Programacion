# Proyecto 1: Estructura de datos avanzada

Integrantes: 

Jose Pablo Laurent Chaves B63761

Maria Jesus Aguilar Esquivel B70120

Carolina Paniagua Penaranda B65268

Marisol Zeledon Cordoba B67969

Bryan Cervantes Ramirez B31726


## How to build the project
Create a build directory and run all targets there
```
>> mkdir build
>> cd build
>> cmake ..
>> make <target> (RBT or RBTtest)
```
## How to run the tests
Go to build and make RBTtest, then: 

1. Run all tests:
```
  ./test/RBTtest
```

## How to run the simulation
The simulation executable is located inside the build directory (src/RBT)
```
./RBT
```

### Dependencies
Make sure gtest is install:
```
sudo apt-get install libgtest-dev

sudo apt-get install cmake # install cmake
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
```
 
