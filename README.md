# sKit

A framework and library agnostic personal toolkit for creative coding in C++.

## Using sKit

### Linux (CMake)

sKit can be built with the usual out of source CMake build steps. Requires CMake `>= 3.15` and a compiler that supports `C++20`.

```sh
git clone https://github.com/somecho/sKit
cd sKit
mkdir build && cd build
cmake ..
make
sudo make install 
```

Running `sudo make install` will put `libsKit.a` in `/usr/local/lib/` and
`/usr/local/include`.

