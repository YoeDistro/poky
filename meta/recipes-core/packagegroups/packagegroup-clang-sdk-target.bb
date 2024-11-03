#
# Copyright OpenEmbedded Contributors
#
# SPDX-License-Identifier: MIT
#

SUMMARY = "Target packages for the Clang SDK"

inherit packagegroup

RDEPENDS:${PN} = " \
    clang \
    libcxx \
    compiler-rt \
"
