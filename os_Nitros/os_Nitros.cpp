#include "nitros/nitros.hpp"
using namespace data;

struct bigone
{
	uword a;
};

list<bigone, 8> List;

int main(void)
{
    while(true)
    {
		bigone a;
		a.a = 10;
		List.Add(a);
		List.DeleteAt(0);
		*address(&List, 2) = 0;
	}
}
