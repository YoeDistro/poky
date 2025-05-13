# inherit this class if you would like to use clang to compile the native
# version of your recipes instead of system compiler ( which is normally gcc )
# on build machines
# to use it add
#
# inherit clang-native
#
# to the concerned recipe via a bbappend or directly to recipe file
#
BUILD_CC = "${CCACHE}${BUILD_PREFIX}clang ${BUILD_CC_ARCH} -isysroot=${STAGING_DIR_NATIVE}"
BUILD_CXX = "${CCACHE}${BUILD_PREFIX}clang++ ${BUILD_CC_ARCH} -isysroot=${STAGING_DIR_NATIVE}"
BUILD_FC = "${BUILD_PREFIX}gfortran ${BUILD_CC_ARCH} -isysroot=${STAGING_DIR_NATIVE}"
BUILD_CPP = "${BUILD_PREFIX}clang ${BUILD_CC_ARCH} -isysroot=${STAGING_DIR_NATIVE} -E"
BUILD_LD = "${BUILD_PREFIX}ld ${BUILD_LD_ARCH}"
BUILD_CCLD = "${BUILD_PREFIX}clang ${BUILD_CC_ARCH}"
BUILD_AR = "${BUILD_PREFIX}llvm-ar"
BUILD_AS = "${BUILD_PREFIX}as ${BUILD_AS_ARCH}"
BUILD_RANLIB = "${BUILD_PREFIX}llvm-ranlib -D"
BUILD_STRIP = "${BUILD_PREFIX}llvm-strip"
BUILD_OBJCOPY = "${BUILD_PREFIX}llvm-objcopy"
BUILD_OBJDUMP = "${BUILD_PREFIX}llvm-objdump"
BUILD_NM = "${BUILD_PREFIX}llvn-nm"
BUILD_READELF = "${BUILD_PREFIX}readelf"
DEPENDS:append = " clang-native compiler-rt-native libcxx-native"
# Use libcxx headers for native parts
CXXFLAGS:append = " -stdlib=libc++"
LDFLAGS:append = " -stdlib=libc++ -rtlib=libgcc -unwindlib=libgcc"
BUILD_LDFLAGS:append = " -stdlib=libc++ -rtlib=libgcc -unwindlib=libgcc"
