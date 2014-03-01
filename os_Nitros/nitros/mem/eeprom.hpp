#ifndef _MEM_EEPROM_HPP_
#define _MEM_EEPROM_HPP_


namespace mem
{

// EEPROM Task
struct eeprom_task 
{
	void*	Dest;
	void*	Src;
	uint	Size;
};


// EEPROM Task Queue
queue<eeprom_task, 16> eeprom_TaskList;


// EEPROM Service Routines
void eeprom_Isr()
{
	eeprom_Handler();
}

void eeprom_Handler()
{
	
}


// EEPROM Read Data
void eeprom_Read(void* dest, void* src, uint size)
{
	// Check if queue is already full or not, if yes, block
	eeprom_TaskList.PushRear();
}


// EEPROM Write Data
void eeprom_Write(void* dest, void* src, uint size)
{
	
}
	
} // end (namespace) mem


#endif /* _MEM_EEPROM_HPP_ */