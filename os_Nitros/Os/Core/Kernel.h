#ifndef _TASK_KERNEL_H_
#define _TASK_KERNEL_H_


#define critSec_Begin()	\
	cli()

#define critSec_End()	\
	sei()


void core_Scheduler(void);
void core_Scheduler(void)
{
	task_FnPtr fn;
	uint data;
	while(true)
	{
		if(queue_HasAvail(&task_Queue))
		{
			fn = (task_FnPtr) queue_Remove(&task_Queue);
			data = (uint) queue_Remove(&task_Queue);
			fn(data);
			continue;
		}
		if(queue_HasAvail(&thread_ReadyQueue))
		{
			
			continue;
		}
		
	}
}


#endif /* _TASK_KERNEL_H_ */