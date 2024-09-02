# sKit

A framework and library agnostic personal toolkit for creative coding in C++.

## Dependencies

The only dependency **sKit** has is [GLM](https://github.com/g-truc/glm).

### Installing GLM on Linux
Use your respective package mangers to install.
```sh
# ubuntu
sudo apt install libglm-dev
# arch 
sudo pacman -S glm
```

### Installing GLM on Windows
The recommended way to install GLM on Windows is to use
[vcpkg](https://learn.microsoft.com/en-us/vcpkg/consume/classic-mode?tabs=msbuild%2Cbuild-MSBuild#3---install-dependencies).

```powershell
vcpkg install glm
```

## Building

### CMake on Linux

sKit can be built with the usual out of source CMake build steps. Requires CMake `>= 3.15` and a compiler that supports `C++20`.

```sh
git clone https://github.com/somecho/sKit
cd sKit
mkdir build && cd build
cmake ..
make
sudo make install
```

### CMake on Visual Studio

You will need the [C++ CMake tools for
Windows](https://learn.microsoft.com/en-us/cpp/build/cmake-projects-in-visual-studio?view=msvc-170).
You can then directly open the project folder in Visual Studio. You only need
to [update your
configuration](https://learn.microsoft.com/en-us/cpp/build/customize-cmake-settings?view=msvc-170)
to pass `CMAKE_TOOLCHAIN_FILE` to CMake during cache generation.

## Installing as a library

### On Linux

Running `sudo make install` will put `libsKit.a` in `/usr/local/lib/` and
`/usr/local/include/`.

