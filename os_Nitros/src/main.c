#include "../Os/Os.h"
#include <asf.h>

//	void* b = &&label;
//	label:;
char buff[10];
string FirstName = "Subhajit";
string LastName = "Sahu";
int main (void)
{
	board_init();
	string_Copy(FirstName, LastName);
	mem_Copy(FirstName, LastName, 0xFF);
}

