#include "nitros/nitros.hpp"
using namespace data;

// async operation is complicated
struct bigone
{
	uint a;
	uint b;
	uint c;
};

list<bigone, 8> List;

int main(void)
{
    while(true)
    {
		bigone* a;
		a = List.New();
		a->a = 10;
		a->b = 11;
		a->c = 12;
		List.DeleteAt(0);
		*address(&List, 2) = 0;
	}
}
