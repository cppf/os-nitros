#ifndef _TASK_KERNEL_H_
#define _TASK_KERNEL_H_


// Begin a critical section
#define critSec_Begin()	\
cli()


// End a critical section
#define critSec_End()	\
sei()



void core_Scheduler(void);
void core_Scheduler(void)
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


#endif /* _TASK_KERNEL_H_ */