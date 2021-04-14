# add-gismo-simple-test

# Description
A simple test to embed the [Gismo](https://gismo.github.io/index.html) library into another C++ project using CMake.

# Tested on
- Arch Linux
- Ubuntu 20.04

## Dependencies
- [CMake](https://cmake.org) (tested with 3.11.0)

obtained with:
```
sudo apt install cmake
```
- [Google Test](https://github.com/google/googletest) (tested with 1.8.0) - Imported with CMake
- [PLF Nanotimer](https://github.com/mattreecebentley/plf_nanotimer) (tested with commit 8c42255) - Imported with CMake

## Error

Current error when running executable:

double free or corruption (out)
Aborted (core dumped)

When running valgrind:

==129898== Invalid free() / delete / delete[] / realloc()
==129898==    at 0x483F9AB: free (vg_replace_malloc.c:538)
==129898==    by 0x113AF3: main (in /home/jordan/git_repos/add-gismo-simple-test/build/example/build-simple-tensor-product-bspline)
==129898==  Address 0x5716e40 is 32 bytes inside a block of size 432 alloc'd
==129898==    at 0x483E77F: malloc (vg_replace_malloc.c:307)
==129898==    by 0x500E019: gismo::gsTensorBasis<2, double>::anchors_into(gismo::gsMatrix<double, -1, -1, 0>&) const (in /usr/lib/libgismo.so.20.12.0)
==129898==    by 0x113AE6: main (in /home/jordan/git_repos/add-gismo-simple-test/build/example/build-simple-tensor-product-bspline)
==129898== 
==129898== 
==129898== HEAP SUMMARY:
==129898==     in use at exit: 432 bytes in 1 blocks
==129898==   total heap usage: 17 allocs, 17 frees, 76,912 bytes allocated
==129898== 
==129898== LEAK SUMMARY:
==129898==    definitely lost: 432 bytes in 1 blocks
==129898==    indirectly lost: 0 bytes in 0 blocks
==129898==      possibly lost: 0 bytes in 0 blocks
==129898==    still reachable: 0 bytes in 0 blocks
==129898==         suppressed: 0 bytes in 0 blocks
==129898== Rerun with --leak-check=full to see details of leaked memory
==129898== 
==129898== For lists of detected and suppressed errors, rerun with: -s
==129898== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

It seems that the anchors_into function is freeing memory that has already been freed.

# Setting up environment to recreate error:
1. Install CMake
Ubuntu:
```
sudo apt get install cmake
```

Arch Linux:
```
sudo pacman -S cmake
```

Once CMake is installed, install gismo by building from source:

Ubuntu:
```
mkdir $HOME/git_repos
cd $HOME/git_repos
git clone git@github.com:gismo/gismo.git
# or if you don't have ssh set up...
# git clone https://github.com/gismo/gismo.git
cd gismo
mkdir build
cd build
cmake ..
make -j10 # or replace 10 with some number of threads you have available
sudo make install
```

Arch Linux:
```
mkdir $HOME/git_repos
cd $HOME/git_repos
git clone git@github.com:gismo/gismo.git
# or if you don't have ssh set up...
git clone https://github.com/gismo/gismo.git
cd gismo
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/usr
make -j10 # or replace 10 with some number of threads you have available
sudo make install
```

Now clone and build this repo:

```
cd $HOME/git_repos
git clone git@github.com:jordans1882/add-gismo-simple-test.git
# or if you don't have ssh set up...
# git clone https://github.com/jordans1882/add-gismo-simple-test.git
cd add-gismo-simple-test
mkdir build
cd build
cmake ..
make
./example/build-simple-tensor-product-bspline
valgrind ./example/build-simple-tensor-product-bspline
# if you don't have valgrind:
# Ubuntu:
# sudo apt install valgrind
# Arch Linux:
# sudo pacman -S valgrind
```
