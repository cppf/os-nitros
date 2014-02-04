#include "../Os/Os.h"
#include <asf.h>

char buff[10];
int main (void)
{
	int a = 10;
	board_init();
	void* b = &&label;
	label:;
	*((int*)buff) = a;
}

