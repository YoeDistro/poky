require gdb-common.inc

DEPENDS = "expat-native gmp-native mpfr-native ncurses-native flex-native bison-native"

inherit python3native pkgconfig

PACKAGECONFIG[python] = "--with-python=${PYTHON},--without-python,python3-native"

do_compile:prepend() {
    export STAGING_LIBDIR="${STAGING_LIBDIR_NATIVE}"
    export STAGING_INCDIR="${STAGING_INCDIR_NATIVE}"
}

#EXTRA_OEMAKE += "LDFLAGS='${BUILD_LDFLAGS}'"

GDBPROPREFIX = ""

PN = "gdb-cross-${TARGET_ARCH}"
BPN = "gdb"

# Ignore how TARGET_ARCH is computed.
TARGET_ARCH[vardepvalue] = "${TARGET_ARCH}"

inherit cross
inherit gettext

datadir .= "/gdb-${TARGET_SYS}${TARGET_VENDOR}-${TARGET_OS}"
