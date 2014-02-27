#ifndef _CORE_KERNEL_HPP_
#define _CORE_KERNEL_HPP_


// Begin a critical section
#define critSec_Begin()	\
cli()


// End a critical section
#define critSec_End()	\
sei()



void kernel_Scheduler(void);
void kernel_Scheduler(void)
{
	while(true)
	{
		if(task_ReadyHigh.Avail()) task_Running = task_ReadyHigh.PopFront();
		else if(task_ReadyMed.Avail()) task_Running = task_ReadyMed.PopFront();
		else if(task_ReadyLow.Avail()) task_Running = task_ReadyLow.PopFront();
		
	}
}


#endif /* _CORE_KERNEL_HPP_ */