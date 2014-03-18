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
		List.DeleteAt(0);
		*address(&List, 2) = 0;
	}
}
