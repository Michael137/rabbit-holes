On older CPUs the _mm_pause() intrinsic should produce "rep nop" instructions.

On Clang and ICC the generated assembly outputs PAUSE correctly. When using GCC on the same machine "rep nop"s still get generated.

Why?

More strangeness: later versions of gcc generate REDUNDANT nops after a rep nop. See:
[gcc 10](https://godbolt.org/z/jobhEc) vs. [gcc 8.3](https://godbolt.org/z/sbhrEY)
