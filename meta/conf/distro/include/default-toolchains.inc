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

#| ./ports/linux/pseudo_wrappers.c:80:14: error: use of unknown builtin '__builtin_apply' [-Wimplicit-function-declaration]
#|         void *res = __builtin_apply((void (*)()) real_syscall, __builtin_apply_args(), sizeof(long) * 7);
#|                     ^
#| ./ports/linux/pseudo_wrappers.c:80:57: error: use of unknown builtin '__builtin_apply_args' [-Wimplicit-function-declaration]
#|         void *res = __builtin_apply((void (*)()) real_syscall, __builtin_apply_args(), sizeof(long) * 7);
TOOLCHAIN:pn-pseudo = "gcc"

# mix_neon.c:179:9: error: invalid operand in inline asm: 'vld1.s32 ${0:h}, [$2]
#      vld1.s32 ${1:h}, [$3] '
TOOLCHAIN:pn-pulseaudio:armv7ve = "gcc"
TOOLCHAIN:pn-pulseaudio:armv7a = "gcc"

# Clang results in a reproducibility issue
# https://github.com/llvm/llvm-project/issues/82541
TOOLCHAIN:pn-rpm = "gcc"

# Emits lot of warning which are treated as errors
# They must be looked into before disabling
TOOLCHAIN:pn-systemtap = "gcc"

# Valgrind needs intrinsics which are not provided by clang
# m_signals.c:2213:7: error: __builtin_longjmp is not supported for the current target
# 2213 |       VG_MINIMAL_LONGJMP(tst->sched_jmpbuf);
#      |       ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#
# It needs something like - https://bugs.kde.org/show_bug.cgi?id=369723
TOOLCHAIN:pn-valgrind:riscv64 = "gcc"

# Clang-20 issue - https://github.com/llvm/llvm-project/issues/132322
TOOLCHAIN:pn-webkitgtk:arm = "gcc"
