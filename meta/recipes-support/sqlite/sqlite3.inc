SUMMARY = "Embeddable SQL database engine"
DESCRIPTION = "A library that implements a small, fast, self-contained, high-reliability, full-featured, SQL database engine. SQLite is the most used database engine in the world. SQLite is built into all mobile phones and most computers and comes bundled inside countless other applications that people use every day"
HOMEPAGE = "http://www.sqlite.org"
SECTION = "libs"

PE = "3"

def sqlite_download_version(d):
    pvsplit = d.getVar('PV').split('.')
    if len(pvsplit) < 4:
        pvsplit.append('0')
    return pvsplit[0] + ''.join([part.rjust(2,'0') for part in pvsplit[1:]])

SQLITE_PV = "${@sqlite_download_version(d)}"

S = "${UNPACKDIR}/sqlite-autoconf-${SQLITE_PV}"

UPSTREAM_CHECK_URI = "http://www.sqlite.org/"
UPSTREAM_CHECK_REGEX = "releaselog/(?P<pver>(\d+[\.\-_]*)+)\.html"

CVE_PRODUCT = "sqlite"

inherit autotools pkgconfig siteinfo

# enable those which are enabled by default in configure
PACKAGECONFIG ?= "fts4 fts5 rtree dyn_ext"
PACKAGECONFIG:class-native ?= "fts4 fts5 rtree dyn_ext"

PACKAGECONFIG[editline] = "--enable-editline,--disable-editline,libedit"
PACKAGECONFIG[readline] = "--enable-readline,--disable-readline,readline ncurses"
PACKAGECONFIG[fts3] = "--enable-fts3,--disable-fts3"
PACKAGECONFIG[fts4] = "--enable-fts4,--disable-fts4"
PACKAGECONFIG[fts5] = "--enable-fts5,--disable-fts5"
PACKAGECONFIG[rtree] = "--enable-rtree,--disable-rtree"
PACKAGECONFIG[session] = "--enable-session,--disable-session"
PACKAGECONFIG[dyn_ext] = "--enable-dynamic-extensions,--disable-dynamic-extensions"
PACKAGECONFIG[zlib] = ",,zlib"

CACHED_CONFIGUREVARS += "${@bb.utils.contains('PACKAGECONFIG', 'zlib', '', 'ac_cv_search_deflate=no',d)}"

EXTRA_OECONF = " \
    --enable-shared \
    --enable-threadsafe \
    --disable-static-shell \
"

# pread() is in POSIX.1-2001 so any reasonable system must surely support it
CFLAGS += "-DUSE_PREAD"

# Provide column meta-data API
CFLAGS += "-DSQLITE_ENABLE_COLUMN_METADATA"

# Unless SQLITE_BYTEORDER is predefined, the code falls back to build time
# huristics, which are not always correct
CFLAGS += "${@oe.utils.conditional('SITEINFO_ENDIANNESS', 'le', '-DSQLITE_BYTEORDER=1234', '-DSQLITE_BYTEORDER=4321', d)}"

PACKAGES = "lib${BPN} lib${BPN}-dev lib${BPN}-doc ${PN}-dbg lib${BPN}-staticdev ${PN}"

FILES:${PN} = "${bindir}/*"
FILES:lib${BPN} = "${libdir}/*.so.*"
FILES:lib${BPN}-dev = "${libdir}/*.la ${libdir}/*.so \
                       ${libdir}/pkgconfig ${includedir}"
FILES:lib${BPN}-doc = "${docdir} ${mandir} ${infodir}"
FILES:lib${BPN}-staticdev = "${libdir}/lib*.a"

AUTO_LIBNAME_PKGS = "${MLPREFIX}lib${BPN}"

BBCLASSEXTEND = "native nativesdk"
