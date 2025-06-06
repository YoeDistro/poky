SUMMARY = "An implementation of JSON Schema validation for Python"
HOMEPAGE = "https://github.com/python-jsonschema/jsonschema"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://COPYING;md5=7a60a81c146ec25599a3e1dabb8610a8 \
                    file://json/LICENSE;md5=9d4de43111d33570c8fe49b4cb0e01af"

SRC_URI[sha256sum] = "0b4e8069eb12aedfa881333004bccaec24ecef5a8a6a4b6df142b2cc9599d196"

inherit pypi python_hatchling

PACKAGES =+ "${PN}-tests"
FILES:${PN}-tests = "${libdir}/${PYTHON_DIR}/site-packages/jsonschema/tests"

DEPENDS += "python3-hatch-fancy-pypi-readme-native python3-hatch-vcs-native "

PACKAGECONFIG ??= "format"
PACKAGECONFIG[format] = ",,,\
    python3-idna \
    python3-jsonpointer \
    python3-webcolors \
    python3-rfc3987 \
    python3-rfc3339-validator \
"
PACKAGECONFIG[format-nongpl] = ",,,\
    python3-idna \
    python3-jsonpointer \
    python3-webcolors \
    python3-rfc3986-validator \
    python3-rfc3339-validator \
"

RDEPENDS:${PN} += " \
    python3-attrs \
    python3-core \
    python3-datetime \
    python3-io \
    python3-json \
    python3-jsonschema-specifications \
    python3-netclient \
    python3-numbers \
    python3-pprint \
    python3-pyrsistent \
    python3-referencing \
    python3-zipp \
"

RDEPENDS:${PN}-tests = "${PN}"

BBCLASSEXTEND = "native nativesdk"
