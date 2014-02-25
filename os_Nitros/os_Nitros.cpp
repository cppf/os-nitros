#include "nitros/nitros.h"

bag_Define(int, 8);
bag_8int	Bag;

int main(void)
{
    while(1)
    {
		bag_Add(Bag, 1);
		bag_RemoveAt(Bag, 0);
        //TODO:: Please write your application code 
    }
}
