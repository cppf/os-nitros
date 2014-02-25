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
		if(queue_HasAvail(&task_Ready))
		{
			task_Current = (Task*) queue_Remove(&task_Ready);
			((task_FnPtr) task_Current->Addr)();
			if(task_Current->State == task_blocked) bag_Add(&task_Blocked, task_Current);
			else queue_Add(&task_Ready, task_Current);
		}
	}
}


#endif /* _CORE_KERNEL_HPP_ */