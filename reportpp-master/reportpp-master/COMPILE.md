Compiling instructions
======================

This project has CMake based compilation. This allows to build the library on a
wide range of environments, including Windows and Linux. The only prerequisite
for pure compilation is to have CMake (http://www.cmake.org) installed and
available.

For a successful compilation you also need the haru PDF library development
files. You can find them at http://libharu.org

If you build the library in a directory called `build` alongside this
documentation file you can use CMake also for compile tests, otherwise you have
to adapt linker paths according to your build directory.