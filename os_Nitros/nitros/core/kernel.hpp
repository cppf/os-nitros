#ifndef _CORE_KERNEL_HPP_
#define _CORE_KERNEL_HPP_


// Begin a critical section
#define critSec_Begin()	\
cli()


// End a critical section
#define critSec_End()	\
sei()


queue<task*, 16> kernel_ReadyHigh;
queue<task*, 16> kernel_ReadyMed;
queue<task*, 16> kernel_ReadyLow;
task* kernel_Running;


void kernel_Scheduler(void);
void kernel_Scheduler(void)
{
	while(true)
	{
		if(kernel_ReadyHigh.Avail()) kernel_Running = kernel_ReadyHigh.PopFront();
		else if(kernel_ReadyMed.Avail()) kernel_Running = kernel_ReadyMed.PopFront();
		else if(kernel_ReadyLow.Avail()) kernel_Running = kernel_ReadyLow.PopFront();
		
	}
}


#endif /* _CORE_KERNEL_HPP_ */