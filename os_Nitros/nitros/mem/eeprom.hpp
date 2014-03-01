#ifndef _MEM_EEPROM_HPP_
#define _MEM_EEPROM_HPP_


namespace mem
{

class eeprom
{
	struct task
	{
		void*	Dest;
		void*	Src;
		uint	Size;
	};
	
	private:
	queue<task, 16> Tasks;
	
	private:
	void eeprom_Isr()
	{
		eeprom_Handler();
	}
	
	void eeprom_Handler()
	{
	
	}
	
	public:
	void eeprom_Read(void* dest, void* src, uint size)
	{
		// Check if queue is already full or not, if yes, block
		eeprom_TaskList.PushRear();
	}
	
	void eeprom_Write(void* dest, void* src, uint size)
	{
	
	}
};

} // end (namespace) mem


#endif /* _MEM_EEPROM_HPP_ */