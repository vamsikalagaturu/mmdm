# MMDM - RayCasting in C with SDL2

## Setup

### Prerequisites

- CMake
- C/C++ compiler
- [SDL2](https://wiki.libsdl.org/SDL2/Installation)

#### Optional

- check (unit testing framework)
- clang-format
- clang-tidy
- pre-commit

### Install prerequisites

``` bash
sudo apt-get install cmake libsdl2-*

# (optional)
sudo apt-get install check clang-format clang-tidy
pip install pre-commit
```

### Package setup

``` bash
mkdir ~/mmdm && cd ~/mmdm

# clone the repo
git clone git@github.com:vamsikalagaturu/mmdm.git .
```

## Building the package

1. Create a build directory for the package

    ``` bash
    mkdir ~/mmdm/build && cd ~/mmdm/build
    ```

2. Configure the cmake project

    ``` bash
    cmake .. -DCMAKE_BUILD_TYPE=Release
    ```

3. Build the package

    ``` bash
    make -j $(nproc)
    ```

## Run

1. From the `build` folder

    ```bash
    ./mmdm
    ```
