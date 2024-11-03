SUMMARY = "Host SDK package for Clang cross canadian toolchain"
PN = "packagegroup-clang-cross-canadian-${MACHINE}"

inherit cross-canadian packagegroup

PACKAGEGROUP_DISABLE_COMPLEMENTARY = "1"

CLANG="clang-cross-canadian-${TRANSLATED_TARGET_ARCH}"

RDEPENDS:${PN} = " \
    ${@all_multilib_tune_values(d, 'CLANG')} \
    nativesdk-binutils \
    nativesdk-clang \
    nativesdk-glibc-dev \
    nativesdk-libgcc-dev \
    nativesdk-compiler-rt-dev \
    nativesdk-libcxx-dev \
"
