goodies
=======

Common utility stuff for my c++ projects.

Clone this repo such way:
```
git clone https://github.com/susu/goodies
git submodule update --init
```

You can add this repo to your CMake project via ExternalProject. E.g.:
{{{
ExternalProject_Add(
    GOODIES
    GIT_REPOSITORY https://github.com/susu/goodies
    GIT_TAG v0.4
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/thirdparty/
    )
}}}

