#include "nitros/nitros.hpp"
using namespace data;

struct bigone
{
	long a;
	long b;
	long c;
};

list<bigone, 8> List;

int main(void)
{
    while(true)
    {
		bigone a;
		a.a = 10;
		a.b = 11;
		a.c = 12;
		List.Add(a);
		List.DeleteAt(0);
		*address(&List, 2) = 0;
	}
}
