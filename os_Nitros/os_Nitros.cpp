#include "nitros/nitros.hpp"

list16<uint, 8> ListU;
list16<int, 8> ListI;

int main(void)
{
	ListI.Init();
	ListU.Init();
	ListI.Add(3);
	ListI.Add(3);
	ListI.Add(3);
	ListU.Add(3);
	ListU.Add(3);
	ListU.Add(3);
/*
	list_AddF(list_Ptr(ListI), 3);
	list_AddF(list_Ptr(ListI), 3);
	list_AddF(list_Ptr(ListI), 3);
	list_AddF(&ListU, 3);
	list_AddF(&ListU, 3);
	list_AddF(&ListU, 3);
	*/
}
