#include "nitros/nitros.hpp"
using namespace data;

list<uword, 8> List;

int main(void)
{
    while(true)
    {
		List.Add(10);
		List.DeleteAt(0);
		*address(&List, 2) = 0;
	}
}
