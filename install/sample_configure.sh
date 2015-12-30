#!/bin/sh
##---------------------------------------------------------------------------##

# add this to get to compile. without this to force hpx on the link line we
# will get undefined hpx symbols. FIND_PACKAGE should put libhpx in the link line
# and this will be fixed.
#-Dtrihpx_EXTRA_LINK_FLAGS:STRING="-L/home/uy7/install/hpx/lib -lhpx" \

rm -rf CMakeCache.txt
rm -rf CMakeFiles

# SOURCE AND INSTALL
SOURCE=~/software/trihpx
INSTALL=~/install/trihpx

# BUILD OPTIONS
BUILD="DEBUG"

##---------------------------------------------------------------------------##

cmake \
-D CMAKE_BUILD_TYPE:STRING="$BUILD" \
-D CMAKE_INSTALL_PREFIX:PATH=$INSTALL \
\
-D TPL_ENABLE_MPI:BOOL=OFF \
\
-D TPL_ENABLE_Boost:BOOL=ON \
-D Boost_LIBRARY_DIRS:PATH=/home/uy7/install/boost_1_59_0/lib \
-D Boost_INCLUDE_DIRS:PATH=/home/uy7/install/boost_1_59_0/include \
\
-D TPL_ENABLE_HPX:BOOL=ON \
-D HPX_DIR:PATH=/home/uy7/install/hpx/lib/cmake \
-D HPX_IGNORE_COMPILER_COMPATIBILITY:BOOL=ON \
\
-Dtrihpx_ENABLE_CXX11:BOOL=ON \
-Dtrihpx_ASSERT_MISSING_PACKAGES:BOOL=OFF \
-Dtrihpx_ENABLE_FooPack:BOOL=ON \
-Dtrihpx_ENABLE_BarPack:BOOL=ON \
-Dtrihpx_ENABLE_Driver:BOOL=ON \
\
-DBUILD_SHARED_LIBS:BOOL=OFF \
\
${SOURCE}

##---------------------------------------------------------------------------##
