Required dependency:

https://github.com/rad1o/libopencm3

If you are using git, the preferred way to install libopencm3 is to use the
submodule:

$ git submodule init
$ git submodule update
$ cd libopencm3
$ make

To build blinky:

$ cd blinky
$ make
$ make program
