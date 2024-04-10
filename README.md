### Goal of the repo

Reproducer for https://github.com/mesonbuild/meson/issues/7435:
OpenMP is not detected by Meson on OSX when installing OpenMP with brew and setting
compilation flags.

### To reproduce
```bash
# Install OpenMP with brew
brew install libomp

# Set compilation flags
export CC=/usr/bin/clang
export CPPFLAGS="-Xpreprocessor -fopenmp"
export CFLAGS="-I/usr/local/opt/libomp/include"
export LDFLAGS="-L/usr/local/opt/libomp/lib -lomp"

# Compile with meson
meson setup build
ninja -C build

# Run test program
./build/my-test
```

OpenMP is not detected in the `meson setup` output:
```
Run-time dependency OpenMP for c found: NO (tried system)
```

Full `meson setup` output:
```
The Meson build system
Version: 1.4.0
Source dir: /Users/ci/dev/meson-openmp-osx
Build dir: /Users/ci/dev/meson-openmp-osx/build
Build type: native build
Project name: my-test
Project version: 1.0.0
C compiler for the host machine: /usr/bin/clang (clang 11.0.3 "Apple clang version 11.0.3 (clang-1103.0.32.29)")
C linker for the host machine: /usr/bin/clang ld64 556.5
Host machine cpu family: x86_64
Host machine cpu: x86_64
Run-time dependency OpenMP for c found: NO (tried system)
Build targets in project: 1

Found ninja-1.11.1 at /Users/ci/mambaforge/envs/scikit-learn-dev/bin/ninja
```

OpenMP compilation actually works fine thanks to the environment variables and
also the program output shows that multiple threads are being used. Here is the
output on my OSX VM with 2 threads:

```
thread number: 0 / total number of threads: 2
thread number: 1 / total number of threads: 2
```
