On older CPUs the _mm_pause() intrinsic should produce "rep nop" instructions.

On Clang and ICC the generated assembly outputs PAUSE correctly. When using GCC on the same machine "rep nop"s still get generated.

Why?

More strangeness: later versions of gcc generate REDUNDANT nops after a rep nop. See:
[gcc 10](https://godbolt.org/z/jobhEc) vs. [gcc 8.3](https://godbolt.org/z/sbhrEY)

# Notes
- gcc/config/i386/i386-expand.c
  - Codegen for `IX86_BUILTIN_TPAUSE` which gets bound to the builtin `__builtin_ia32_tpause` in `gcc/config/i386/i386-builtins.c`
- gcc/config/i386/i386-builtin.def
  - Defines builtin for `IX86_BUILTIN_PAUSE`
