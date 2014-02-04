#ifndef _CORE_TASK_H_
#define _CORE_TASK_H_


// Define
#define	task_Define(sz)	\
typedef	struct _Task##sz	\
{	\
	void*	Addr;	\
	uint	Data;	\
	uint	Line;	\
	int16*	Sync;	\
	uword	State;	\
	byte	Store[sz];	\
}Task##sz


// Header
typedef struct _task_Header
{
	void*	Addr;
	uint	Data;
	uint	Line;
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

task_QueueType	task_Ready;
task_BagType	task_Blocked;


// Status
#define task_unstarted			0x00
#define	task_completed			0xF0
#define task_sem_blocked		0x70
#define task_mutex_blocked		0x71
#define task_sem_released		0x60
#define task_mutex_released		0x61
#define	task_yielded			0x50
#define	task_waiting			0x40


// Initialize
#define task_InitF(tsk, addr, data)	\
macro_Begin	\
(tsk)->Addr = addr;	\
(tsk)->Data = data;	\
(tsk)->Line = 0;	\
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
	void name(Task* task_Obj)


// Begin a thread function
#define	task_Begin	\
	switch(task_Obj->Line)	\
	{	\
		case 0:


// End a thread function
#define	task_End	\
		}	\
	task_Obj->Line = 0;	\
	return task_completed;


// Save thread state to a buffer
#define	task_SaveState1(typ1, var1)	\
(*((typ1*)(task_Obj->Store)) = var1)

#define	task_SaveState2(typ1, var1, typ2, var2)	\
macro_Begin	\
*((typ1*)(task_Obj->Store)) = var1;	\
*((typ2*)((task_Obj->Store) + sizeof(typ1))) = var2;	\
macro_End

#define	task_SaveState3(typ1, var1, typ2, var2, typ3, var3)	\
macro_Begin	\
*((typ1*)(task_Obj->Store)) = var1;	\
*((typ2*)((task_Obj->Store) + sizeof(typ1))) = var2;	\
*((typ3*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2))) = var3;	\
macro_End

#define	task_SaveState4(typ1, var1, typ2, var2, typ3, var3, typ4, var4)	\
macro_Begin	\
*((typ1*)(task_Obj->Store)) = var1;	\
*((typ2*)((task_Obj->Store) + sizeof(typ1))) = var2;	\
*((typ3*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2))) = var3;	\
*((typ4*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3))) = var4;	\
macro_End

#define	task_SaveState5(typ1, var1, typ2, var2, typ3, var3, typ4, var4, typ5, var5)	\
macro_Begin	\
*((typ1*)(task_Obj->Store)) = var1;	\
*((typ2*)((task_Obj->Store) + sizeof(typ1))) = var2;	\
*((typ3*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2))) = var3;	\
*((typ4*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3))) = var4;	\
*((typ5*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4))) = var5;	\
macro_End

#define	task_SaveState6(typ1, var1, typ2, var2, typ3, var3, typ4, var4, typ5, var5, typ6, var6)	\
macro_Begin	\
*((typ1*)(task_Obj->Store)) = var1;	\
*((typ2*)((task_Obj->Store) + sizeof(typ1))) = var2;	\
*((typ3*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2))) = var3;	\
*((typ4*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3))) = var4;	\
*((typ5*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4))) = var5;	\
*((typ6*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4) + sizeof(typ5))) = var6;	\
macro_End

#define	task_SaveState7(typ1, var1, typ2, var2, typ3, var3, typ4, var4, typ5, var5, typ6, var6, typ7, var7)	\
macro_Begin	\
*((typ1*)(task_Obj->Store)) = var1;	\
*((typ2*)((task_Obj->Store) + sizeof(typ1))) = var2;	\
*((typ3*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2))) = var3;	\
*((typ4*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3))) = var4;	\
*((typ5*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4))) = var5;	\
*((typ6*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4) + sizeof(typ5))) = var6;	\
*((typ7*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4) + sizeof(typ5) + sizeof(typ6))) = var7;	\
macro_End

#define	task_SaveState8(typ1, var1, typ2, var2, typ3, var3, typ4, var4, typ5, var5, typ6, var6, typ7, var7, typ8, var8)	\
macro_Begin	\
*((typ1*)(task_Obj->Store)) = var1;	\
*((typ2*)((task_Obj->Store) + sizeof(typ1))) = var2;	\
*((typ3*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2))) = var3;	\
*((typ4*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3))) = var4;	\
*((typ5*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4))) = var5;	\
*((typ6*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4) + sizeof(typ5))) = var6;	\
*((typ7*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4) + sizeof(typ5) + sizeof(typ6))) = var7;	\
*((typ8*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4) + sizeof(typ5) + sizeof(typ6) + sizeof(typ7))) = var8;	\
macro_End

#define	task_SaveState(...)	\
macro_Fn(macro_Fn17(_0, __VA_ARGS__, task_SaveState8, _15, task_SaveState7, _13, task_SaveState6, _11, task_SaveState5, _9, task_SaveState4, _7, task_SaveState3, _5, task_SaveState2, _3, task_SaveState1, macro_FnE, macro_FnE)(__VA_ARGS__))

#define	task_Save	task_SaveState


// Load thread state from a buffer
#define	task_LoadState1(typ1, var1)	\
(var1 = *((typ1*)(task_Obj->Store)))

#define	task_LoadState2(typ1, var1, typ2, var2)	\
macro_Begin	\
var1 = *((typ1*)(task_Obj->Store));	\
var2 = *((typ2*)((task_Obj->Store) + sizeof(typ1)));	\
macro_End

#define	task_LoadState3(typ1, var1, typ2, var2, typ3, var3)	\
macro_Begin	\
var1 = *((typ1*)(task_Obj->Store));	\
var2 = *((typ2*)((task_Obj->Store) + sizeof(typ1)));	\
var3 = *((typ3*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2)));	\
macro_End

#define	task_LoadState4(typ1, var1, typ2, var2, typ3, var3, typ4, var4)	\
macro_Begin	\
var1 = *((typ1*)(task_Obj->Store));	\
var2 = *((typ2*)((task_Obj->Store) + sizeof(typ1)));	\
var3 = *((typ3*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2)));	\
var4 = *((typ4*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3)));	\
macro_End

#define	task_LoadState5(typ1, var1, typ2, var2, typ3, var3, typ4, var4, typ5, var5)	\
macro_Begin	\
var1 = *((typ1*)(task_Obj->Store));	\
var2 = *((typ2*)((task_Obj->Store) + sizeof(typ1)));	\
var3 = *((typ3*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2)));	\
var4 = *((typ4*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3)));	\
var5 = *((typ5*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4)));	\
macro_End

#define	task_LoadState6(typ1, var1, typ2, var2, typ3, var3, typ4, var4, typ5, var5, typ6, var6)	\
macro_Begin	\
var1 = *((typ1*)(task_Obj->Store));	\
var2 = *((typ2*)((task_Obj->Store) + sizeof(typ1)));	\
var3 = *((typ3*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2)));	\
var4 = *((typ4*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3)));	\
var5 = *((typ5*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4)));	\
var6 = *((typ6*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4) + sizeof(typ5)));	\
macro_End

#define	task_LoadState7(typ1, var1, typ2, var2, typ3, var3, typ4, var4, typ5, var5, typ6, var6, typ7, var7)	\
macro_Begin	\
var1 = *((typ1*)(task_Obj->Store));	\
var2 = *((typ2*)((task_Obj->Store) + sizeof(typ1)));	\
var3 = *((typ3*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2)));	\
var4 = *((typ4*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3)));	\
var5 = *((typ5*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4)));	\
var6 = *((typ6*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4) + sizeof(typ5)));	\
var7 = *((typ7*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4) + sizeof(typ5) + sizeof(typ6)));	\
macro_End

#define	task_LoadState8(typ1, var1, typ2, var2, typ3, var3, typ4, var4, typ5, var5, typ6, var6, typ7, var7, typ8, var8)	\
macro_Begin	\
var1 = *((typ1*)(task_Obj->Store));	\
var2 = *((typ2*)((task_Obj->Store) + sizeof(typ1)));	\
var3 = *((typ3*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2)));	\
var4 = *((typ4*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3)));	\
var5 = *((typ5*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4)));	\
var6 = *((typ6*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4) + sizeof(typ5)));	\
var7 = *((typ7*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4) + sizeof(typ5) + sizeof(typ6)));	\
var8 = *((typ8*)((task_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4) + sizeof(typ5) + sizeof(typ6) + sizeof(typ7)));	\
macro_End

#define	task_LoadState(...)	\
macro_Fn(macro_Fn17(_0, __VA_ARGS__, task_LoadState8, _15, task_LoadState7, _13, task_LoadState6, _11, task_LoadState5, _9, task_LoadState4, _7, task_LoadState3, _5, task_LoadState2, _3, task_LoadState1, macro_FnE, macro_FnE)(__VA_ARGS__))

#define	task_Load	task_LoadState


// Yields out of a thread
#define	task_Yield(...)	\
macro_Begin	\
task_Obj->Line = __LINE__;	\
task_SaveState(__VA_ARGS__);	\
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
task_Obj->Sync = (semptr);	\
task_Obj->Line = __LINE__;	\
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
	task_Obj->Sync = (semptr);	\
	task_Obj->Line = __LINE__;	\
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
	task_Obj->Sync = (mutexptr);	\
	task_Obj->Line = __LINE__;	\
	task_SaveState(__VA_ARGS__);	\
	return task_mutex_blocked;	\
	case __LINE__:	\
	task_LoadState(__VA_ARGS__);	\
}	\
*(mutexptr) = (Mutex) task_Obj;	\
macro_End

#define task_MutexTake	\
task_MutexWait

#define task_MutexLock	\
task_MutexWait


// Signal Mutex
#define	task_MutexSignal(mutexptr, ...)	\
macro_Begin	\
if(*(mutexptr) == (Mutex) task_Obj)	\
{	\
	task_Obj->Sync = (mutexptr);	\
	task_Obj->Line = __LINE__;	\
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


#endif /* _CORE_TASK_H_ */