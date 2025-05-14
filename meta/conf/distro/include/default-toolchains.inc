TOOLCHAIN:pn-gcc = "gcc"
TOOLCHAIN:pn-gcc-runtime = "gcc"
TOOLCHAIN:pn-gcc-sanitizers = "gcc"
TOOLCHAIN:pn-glibc = "gcc"
TOOLCHAIN:pn-glibc-initial = "gcc"
TOOLCHAIN:pn-glibc-locale = "gcc"
TOOLCHAIN:pn-glibc-mtrace = "gcc"
TOOLCHAIN:pn-glibc-scripts = "gcc"
TOOLCHAIN:pn-glibc-testsuite = "gcc"
TOOLCHAIN:pn-glibc-y2038-tests = "gcc"
TOOLCHAIN:pn-libgcc-initial = "gcc"
TOOLCHAIN:pn-libgcc = "gcc"
TOOLCHAIN:pn-libgfortran = "gcc"
TOOLCHAIN:pn-libssp-nonshared = "gcc"

# mix_neon.c:179:9: error: invalid operand in inline asm: 'vld1.s32 ${0:h}, [$2]
#      vld1.s32 ${1:h}, [$3] '
TOOLCHAIN:pn-pulseaudio:armv7ve = "gcc"
TOOLCHAIN:pn-pulseaudio:armv7a = "gcc"
