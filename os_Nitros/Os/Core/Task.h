#ifndef _CORE_TASK_H_
#define _CORE_TASK_H_


// Task maintenance
#ifndef task_QueueType
#define task_QueueType	Queue32
#endif

task_QueueType	task_Queue;


// Define a task function
#define	task_Fn(name)	\
void name(uint task_Data)

typedef void (*task_FnPtr)(uint);


// Add a new task
void task_Add(void* fn, uint data);
void task_Add(void* fn, uint data)
{
	queue_Add(&task_Queue, fn);
	queue_Add(&task_Queue, data);
}


// Running tasks
#define task_Running()	\
((task_Queue->Count) >> 1)


// Is Empty
#define task_IsEmpty()	\
(task_Queue->Count)


#endif /* _CORE_TASK_H_ */