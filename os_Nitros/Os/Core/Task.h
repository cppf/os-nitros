#ifndef _CORE_TASK_H_
#define _CORE_TASK_H_


// Define
#define	task_Define(sz)	\
typedef	struct _Task##sz	\
{	\
	void*	Addr;	\
	uint	Data;	\
	uword*	Sync;	\
	uword	State;	\
	byte	Store[sz];	\
}Task##sz


// Header
typedef struct _task_Header
{
	void*	Addr;
	uint	Data;
	int16*	Sync;
	uword	State;
}task_Header;

typedef task_Header Task0;


// Default
task_Define(1);
task_Define(2);
task_Define(4);
task_Define(8);
task_Define(16);
task_Define(32);

#ifndef task_Default
#define	task_Default	Task2
#endif

typedef task_Default	Task;


// Task maintenance
#ifndef task_QueueType
#define task_QueueType	Queue16
#endif

#ifndef task_BagType
#define task_BagType	Bag16
#endif

Task*	task_Current;
task_QueueType	task_Ready;
task_BagType	task_Blocked;


// Status
#define task_unstarted			0x00
#define	task_completed			0xF0
#define task_blocked			0x70
#define task_released			0x60
#define	task_yielded			0x50
#define	task_waiting			0x40


// Initialize
#define task_InitF(tsk, addr, data)	\
macro_Begin	\
(tsk)->Addr = addr;	\
(tsk)->Data = data;	\
(tsk)->Sync = 0;	\
(tsk)->State = task_unstarted;	\
macro_End


// Get address of task
#define task_GetAddress(tsk)	\
((tsk)->Addr)


// Get data of task
#define task_GetData(tsk)	\
((tsk)->Data)


// Get state of a task
#define task_GetState(tsk)	\
((tsk)->State)


// Define a task function
#define	task_Fn(name)	\
void name(void);	\
void name(void)


// Save thread state to a buffer
#define	task_SaveState1(var1)	\
(*((__typeof__(var1)*)(task_Current->Store)) = var1)

#define	task_SaveState2(var1, var2)	\
macro_Begin	\
*((__typeof__(var1)*)(task_Current->Store)) = var1;	\
*((__typeof__(var2)*)((task_Current->Store) + sizeof(var1))) = var2;	\
macro_End

#define	task_SaveState3(var1, var2, var3)	\
macro_Begin	\
*((__typeof__(var1)*)(task_Current->Store)) = var1;	\
*((__typeof__(var2)*)((task_Current->Store) + sizeof(var1))) = var2;	\
*((__typeof__(var3)*)((task_Current->Store) + sizeof(var1) + sizeof(var2))) = var3;	\
macro_End

#define	task_SaveState4(var1, var2, var3, var4)	\
macro_Begin	\
*((__typeof__(var1)*)(task_Current->Store)) = var1;	\
*((__typeof__(var2)*)((task_Current->Store) + sizeof(var1))) = var2;	\
*((__typeof__(var3)*)((task_Current->Store) + sizeof(var1) + sizeof(var2))) = var3;	\
*((__typeof__(var4)*)((task_Current->Store) + sizeof(var1) + sizeof(var2) + sizeof(var3))) = var4;	\
macro_End

#define	task_SaveState5(var1, var2, var3, var4, var5)	\
macro_Begin	\
*((__typeof__(var1)*)(task_Current->Store)) = var1;	\
*((__typeof__(var2)*)((task_Current->Store) + sizeof(var1))) = var2;	\
*((__typeof__(var3)*)((task_Current->Store) + sizeof(var1) + sizeof(var2))) = var3;	\
*((__typeof__(var4)*)((task_Current->Store) + sizeof(var1) + sizeof(var2) + sizeof(var3))) = var4;	\
*((__typeof__(var5)*)((task_Current->Store) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4))) = var5;	\
macro_End

#define	task_SaveState6(var1, var2, var3, var4, var5, var6)	\
macro_Begin	\
*((__typeof__(var1)*)(task_Current->Store)) = var1;	\
*((__typeof__(var2)*)((task_Current->Store) + sizeof(var1))) = var2;	\
*((__typeof__(var3)*)((task_Current->Store) + sizeof(var1) + sizeof(var2))) = var3;	\
*((__typeof__(var4)*)((task_Current->Store) + sizeof(var1) + sizeof(var2) + sizeof(var3))) = var4;	\
*((__typeof__(var5)*)((task_Current->Store) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4))) = var5;	\
*((__typeof__(var6)*)((task_Current->Store) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5))) = var6;	\
macro_End

#define	task_SaveState7(var1, var2, var3, var4, var5, var6, var7)	\
macro_Begin	\
*((__typeof__(var1)*)(task_Current->Store)) = var1;	\
*((__typeof__(var2)*)((task_Current->Store) + sizeof(var1))) = var2;	\
*((__typeof__(var3)*)((task_Current->Store) + sizeof(var1) + sizeof(var2))) = var3;	\
*((__typeof__(var4)*)((task_Current->Store) + sizeof(var1) + sizeof(var2) + sizeof(var3))) = var4;	\
*((__typeof__(var5)*)((task_Current->Store) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4))) = var5;	\
*((__typeof__(var6)*)((task_Current->Store) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5))) = var6;	\
*((__typeof__(var7)*)((task_Current->Store) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5) + sizeof(var6))) = var7;	\
macro_End

#define	task_SaveState8(var1, var2, var3, var4, var5, var6, var7, var8)	\
macro_Begin	\
*((__typeof__(var1)*)(task_Current->Store)) = var1;	\
*((__typeof__(var2)*)((task_Current->Store) + sizeof(var1))) = var2;	\
*((__typeof__(var3)*)((task_Current->Store) + sizeof(var1) + sizeof(var2))) = var3;	\
*((__typeof__(var4)*)((task_Current->Store) + sizeof(var1) + sizeof(var2) + sizeof(var3))) = var4;	\
*((__typeof__(var5)*)((task_Current->Store) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4))) = var5;	\
*((__typeof__(var6)*)((task_Current->Store) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5))) = var6;	\
*((__typeof__(var7)*)((task_Current->Store) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5) + sizeof(var6))) = var7;	\
*((__typeof__(var8)*)((task_Current->Store) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5) + sizeof(var6) + sizeof(var7))) = var8;	\
macro_End

#define	task_SaveState(...)	\
macro_Fn(macro_Fn9(_0, __VA_ARGS__, task_SaveState8, task_SaveState7, task_SaveState6, task_SaveState5, task_SaveState4, task_SaveState3, task_SaveState2, task_SaveState1, macro_FnE, macro_FnE)(__VA_ARGS__))


// Load thread state from a buffer
#define	task_LoadState1(var1)	\
(var1 = *((__typeof__(var1)*)(task_Current->Store)))

#define	task_LoadState2(var1, var2)	\
macro_Begin	\
var1 = *((__typeof__(var1)*)(task_Current->Store));	\
var2 = *((__typeof__(var2)*)((task_Current->Store) + sizeof(var1)));	\
macro_End

#define	task_LoadState3(var1, var2, var3)	\
macro_Begin	\
var1 = *((__typeof__(var1)*)(task_Current->Store));	\
var2 = *((__typeof__(var2)*)((task_Current->Store) + sizeof(var1)));	\
var3 = *((__typeof__(var3)*)((task_Current->Store) + sizeof(var1) + sizeof(var2)));	\
macro_End

#define	task_LoadState4(var1, var2, var3, var4)	\
macro_Begin	\
var1 = *((__typeof__(var1)*)(task_Current->Store));	\
var2 = *((__typeof__(var2)*)((task_Current->Store) + sizeof(var1)));	\
var3 = *((__typeof__(var3)*)((task_Current->Store) + sizeof(var1) + sizeof(var2)));	\
var4 = *((__typeof__(var4)*)((task_Current->Store) + sizeof(var1) + sizeof(var2) + sizeof(var3)));	\
macro_End

#define	task_LoadState5(var1, var2, var3, var4, var5)	\
macro_Begin	\
var1 = *((__typeof__(var1)*)(task_Current->Store));	\
var2 = *((__typeof__(var2)*)((task_Current->Store) + sizeof(var1)));	\
var3 = *((__typeof__(var3)*)((task_Current->Store) + sizeof(var1) + sizeof(var2)));	\
var4 = *((__typeof__(var4)*)((task_Current->Store) + sizeof(var1) + sizeof(var2) + sizeof(var3)));	\
var5 = *((__typeof__(var5)*)((task_Current->Store) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4)));	\
macro_End

#define	task_LoadState6(var1, var2, var3, var4, var5, var6)	\
macro_Begin	\
var1 = *((__typeof__(var1)*)(task_Current->Store));	\
var2 = *((__typeof__(var2)*)((task_Current->Store) + sizeof(var1)));	\
var3 = *((__typeof__(var3)*)((task_Current->Store) + sizeof(var1) + sizeof(var2)));	\
var4 = *((__typeof__(var4)*)((task_Current->Store) + sizeof(var1) + sizeof(var2) + sizeof(var3)));	\
var5 = *((__typeof__(var5)*)((task_Current->Store) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4)));	\
var6 = *((__typeof__(var6)*)((task_Current->Store) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5)));	\
macro_End

#define	task_LoadState7(var1, var2, var3, var4, var5, var6, var7)	\
macro_Begin	\
var1 = *((__typeof__(var1)*)(task_Current->Store));	\
var2 = *((__typeof__(var2)*)((task_Current->Store) + sizeof(var1)));	\
var3 = *((__typeof__(var3)*)((task_Current->Store) + sizeof(var1) + sizeof(var2)));	\
var4 = *((__typeof__(var4)*)((task_Current->Store) + sizeof(var1) + sizeof(var2) + sizeof(var3)));	\
var5 = *((__typeof__(var5)*)((task_Current->Store) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4)));	\
var6 = *((__typeof__(var6)*)((task_Current->Store) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5)));	\
var7 = *((__typeof__(var7)*)((task_Current->Store) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5) + sizeof(var6)));	\
macro_End

#define	task_LoadState8(var1, var2, var3, var4, var5, var6, var7, var8)	\
macro_Begin	\
var1 = *((__typeof__(var1)*)(task_Current->Store));	\
var2 = *((__typeof__(var2)*)((task_Current->Store) + sizeof(var1)));	\
var3 = *((__typeof__(var3)*)((task_Current->Store) + sizeof(var1) + sizeof(var2)));	\
var4 = *((__typeof__(var4)*)((task_Current->Store) + sizeof(var1) + sizeof(var2) + sizeof(var3)));	\
var5 = *((__typeof__(var5)*)((task_Current->Store) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4)));	\
var6 = *((__typeof__(var6)*)((task_Current->Store) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5)));	\
var7 = *((__typeof__(var7)*)((task_Current->Store) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5) + sizeof(var6)));	\
var8 = *((__typeof__(var8)*)((task_Current->Store) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5) + sizeof(var6) + sizeof(var7)));	\
macro_End

#define	task_LoadState(...)	\
macro_Fn(macro_Fn9(_0, __VA_ARGS__, task_LoadState8, task_LoadState7, task_LoadState6, task_LoadState5, task_LoadState4, task_LoadState3, task_LoadState2, task_LoadState1, macro_FnE, macro_FnE)(__VA_ARGS__))


// Mark checkpoint in a task
// A task resumes from the last checkpoint
#define task_MarkCheckpoint(name, ...)	\
macro_Begin	\
task_Current->Addr = &&name;	\
task_SaveState(__VA_ARGS__);	\
name:	\
task_LoadState(__VA_ARGS__);	\
macro_End


// Yields out of a task
#define	task_Yield(...)	\
macro_Begin	\
task_Current->Addr = &&task_Label##__LINE__;	\
task_SaveState(__VA_ARGS__);	\
task_Current->State = task_yielded;

return task_yielded;	\
case __LINE__:	\
task_LoadState(__VA_ARGS__);	\
macro_End


// Wait while a condition is satisfied (active wait)
#define	task_WaitWhile(wait_cond, ...)	\
macro_Begin	\
task_line = __LINE__;	\
task_SaveState(__VA_ARGS__);	\
case __LINE__:	\
if(wait_cond) return task_waiting;	\
task_LoadState(__VA_ARGS__);	\
macro_End


// Wait until a condition is satisfied (active wait)
#define	task_WaitUntil(wait_cond, ...)	\
task_WaitWhile(!(wait_cond), __VA_ARGS__)


// Exit out of a thread
#define	task_Exit()	\
return task_exited


// Wait on semaphore
#define	task_SemWait(semptr, ...)	\
macro_Begin	\
*(semptr)--;	\
if(*(semptr) < 0)	\
{	\
task_Current->Sync = (semptr);	\
task_Current->Line = __LINE__;	\
task_SaveState(__VA_ARGS__);	\
return task_sem_blocked;	\
case __LINE__:	\
task_LoadState(__VA_ARGS__);	\
}	\
macro_End

#define task_SemTake	\
task_SemWait


// Signal semaphore
#define	task_SemSignal(semptr, ...)	\
macro_Begin	\
*(semptr)++;	\
if(*(semptr) <= 0)	\
{	\
	task_Current->Sync = (semptr);	\
	task_Current->Line = __LINE__;	\
	task_SaveState(__VA_ARGS__);	\
	return task_sem_released;	\
	case __LINE__:	\
	task_LoadState(__VA_ARGS__);	\
}	\
macro_End

#define task_SemGive	\
task_SemSignal


// Wait on Mutex
#define	task_MutexWait(mutexptr, ...)	\
macro_Begin	\
if(*(mutexptr) != null)	\
{	\
	task_Current->Sync = (mutexptr);	\
	task_Current->Line = __LINE__;	\
	task_SaveState(__VA_ARGS__);	\
	return task_mutex_blocked;	\
	case __LINE__:	\
	task_LoadState(__VA_ARGS__);	\
}	\
*(mutexptr) = (Mutex) task_Current;	\
macro_End

#define task_MutexTake	\
task_MutexWait

#define task_MutexLock	\
task_MutexWait


// Signal Mutex
#define	task_MutexSignal(mutexptr, ...)	\
macro_Begin	\
if(*(mutexptr) == (Mutex) task_Current)	\
{	\
	task_Current->Sync = (mutexptr);	\
	task_Current->Line = __LINE__;	\
	task_SaveState(__VA_ARGS__);	\
	return task_mutex_released;	\
	case __LINE__:	\
	task_LoadState(__VA_ARGS__);	\
}	\
macro_End

#define task_MutexGive	\
task_MutexSignal

#define task_MutexUnlock	\
task_MutexSignal



// Marks a task as completed
// Hence, the task exits permanently
#define	task_Complete()	\
macro_Begin	\
task_Current->State = task_completed;	\
return;



#endif /* _CORE_TASK_H_ */