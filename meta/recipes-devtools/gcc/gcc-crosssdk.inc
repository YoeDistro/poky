inherit crosssdk

PN = "gcc-crosssdk-${SDK_SYS}"

SYSTEMHEADERS = "${SDKPATHNATIVE}${prefix_nativesdk}/include"
SYSTEMLIBS = "${SDKPATHNATIVE}${base_libdir_nativesdk}/"
SYSTEMLIBS1 = "${SDKPATHNATIVE}${libdir_nativesdk}/"

GCCMULTILIB = "--disable-multilib"

DEPENDS = "virtual/${TARGET_PREFIX}binutils gettext-native ${NATIVEDEPS}"
PROVIDES = "virtual/${TARGET_PREFIX}cc virtual/${TARGET_PREFIX}c++"

gcc_multilib_setup[vardepsexclude] = "MULTILIB_VARIANTS"
