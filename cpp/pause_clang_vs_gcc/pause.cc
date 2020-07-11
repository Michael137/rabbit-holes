#include <emmintrin.h>

void test()
{
	while(true)
	{
		_mm_pause();
		_mm_pause();
		_mm_pause();
		_mm_pause();
		_mm_pause();

		asm volatile ("pause");
		asm volatile ("pause");
		asm volatile ("pause");
		asm volatile ("pause");
		asm volatile ("pause");
	}
}

int main()
{
	return 0;
}
