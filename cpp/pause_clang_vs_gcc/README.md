On older CPUs the _mm_pause() intrinsic should produce "rep nop" instructions.

On Clang and ICC the generated assembly outputs PAUSE correctly. When using GCC on the same machine "rep nop"s still get generated.

Why?
