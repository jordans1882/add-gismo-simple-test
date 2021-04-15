cmake_minimum_required(VERSION 3.0.0)
cmake_policy(SET CMP0077 NEW)
cmake_policy(SET CMP0011 NEW)
cmake_policy(SET CMP0042 NEW)
cmake_policy(SET CMP0048 NEW)
project(Simple LANGUAGES C CXX  VERSION 0.1.1)

if(POLICY CMP0048)# CMake 3.0
    cmake_policy(SET CMP0011 NEW)
    cmake_policy(SET CMP0042 NEW)
    cmake_policy(SET CMP0048 NEW)
endif()

if(POLICY CMP0054)# CMake 3.1
    cmake_policy(SET CMP0054 NEW)
endif()

if(POLICY CMP0053)# CMake 3.1.3
    cmake_policy(SET CMP0053 NEW)
endif()

if(POLICY CMP0063)# CMake 3.3
    cmake_policy(SET CMP0063 NEW)
endif()

if(POLICY CMP0074)# CMake 3.12
    cmake_policy(SET CMP0074 NEW)
endif()

if(POLICY CMP0077)# CMake 3.13
    cmake_policy(SET CMP0077 NEW)
endif()

if(POLICY CMP0048)# CMake 3.0
	project(Simple LANGUAGES C CXX  VERSION 0.1.1)
else()
	project(Simple C CXX)
endif()

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/") # Set module path
# include(gismoUse)
# include(gsConfig)
include(install_dependency) # include install_dependency

# set the build type.  Good values are debug or release
# set(CMAKE_BUILD_TYPE debug)
set(CMAKE_BUILD_TYPE Release)
# set(CMAKE_BUILD_TYPE RelWithDebInfo)

# setup dependencies
find_package(Boost)

if(Boost_FOUND)
  message("Boost was found")
endif()
find_package(gismo COMPONENTS Core Matrix HSplines Tensor)
if(gismo_FOUND)
  message("Gismo was found")
endif()

set(PLF_NANOTIMER_DIR "${CMAKE_BINARY_DIR}/plf_nanotimer-src")

enable_testing()
install_dependency("googletest")
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE) # fix settings on Windows (TODO: detect OS?)

# setup the build flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -O2")
include( gsConfig )
# include( CheckCCompilerFlag )
# include( CheckCXXCompilerFlag )
# include( CheckMicCXXCompilerFlag )
# include( CheckMicCCompilerFlag )
# include( AddCompilerFlag )
# include( OptimizeForArchitecture )

# setup the includes
set(SIMPLE_INCLUDE_DIR "./include")
include_directories(
    ${BOOST_INCLUDE_DIR}
    ${GISMO_INCLUDE_DIRS}
    ${PLF_NANOTIMER_DIR}
    ${SIMPLE_INCLUDE_DIR}
    #${GISMO_INCLUDE_DIR}
    )

# setup remainder of project
# add_subdirectory(ext/gismo)
add_subdirectory(test)
add_subdirectory(example)
