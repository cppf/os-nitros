#ifndef _CORE_THREAD_H_
#define _CORE_THREAD_H_


// Define
#define	thread_Define(sz)	\
typedef	struct _Thread##sz	\
{	\
	void*	Fn;		\
	uint	Data;	\
	uint	Line;	\
	int16*	Sync;	\
	uword	State;	\
	byte	Store[sz];	\
}Thread##sz


// Header
typedef struct _thread_Header
{
	void*	Fn;
	uint	Data;
	uint	Line;
	int16*	Sync;
	uword	State;
}thread_Header;


// Default
thread_Define(1);
thread_Define(2);
thread_Define(4);
thread_Define(8);
thread_Define(16);
thread_Define(32);

#ifndef thread_Default
#define	thread_Default	Thread2
#endif

typedef thread_Default	Thread;


// Thread maintenance
#ifndef thread_QueueType
#define thread_QueueType	Queue16
#endif

#ifndef thread_BagType
#define thread_BagType		Bag16
#endif

thread_QueueType	thread_ReadyQueue;
thread_BagType		thread_BlockedBag;


// Status
#define thread_not_started		0x00
#define	thread_exited			0xF0
#define thread_sem_blocked		0x70
#define thread_mutex_blocked	0x71
#define thread_sem_released		0x60
#define thread_mutex_released	0x61
#define	thread_yielded			0x50
#define	thread_waiting			0x40


// Initialize
void thread_InitF(Thread* thd, void* fn, uint data);
void thread_InitF(Thread* thd, void* fn, uint data)
{
	(thd)->Fn = fn;
	(thd)->Data = data;
	(thd)->Line = 0;
	(thd)->Sync = 0;
	(thd)->State = thread_not_started;
}

#define thread_Init(thd, fn, data)	\
thread_InitF((Thread*)(thd), (void*)(fn), (uint)(data))


// Define a thread function
#define	thread_Fn(name)	\
	uword name(Thread* thread_Obj)


// Begin a thread function
#define	thread_Begin	\
	switch(thread_Obj->Line)	\
	{	\
		case 0:


// End a thread function
#define	thread_End	\
		}	\
	thread_Obj->Line = 0;	\
	return thread_exited;


// Save thread state to a buffer
#define	thread_SaveState1(typ1, var1)	\
	(*((typ1*)(thread_Obj->Store)) = var1)

#define	thread_SaveState2(typ1, var1, typ2, var2)	\
	macro_Begin	\
	*((typ1*)(thread_Obj->Store)) = var1;	\
	*((typ2*)((thread_Obj->Store) + sizeof(typ1))) = var2;	\
	macro_End

#define	thread_SaveState3(typ1, var1, typ2, var2, typ3, var3)	\
	macro_Begin	\
	*((typ1*)(thread_Obj->Store)) = var1;	\
	*((typ2*)((thread_Obj->Store) + sizeof(typ1))) = var2;	\
	*((typ3*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2))) = var3;	\
	macro_End

#define	thread_SaveState4(typ1, var1, typ2, var2, typ3, var3, typ4, var4)	\
	macro_Begin	\
	*((typ1*)(thread_Obj->Store)) = var1;	\
	*((typ2*)((thread_Obj->Store) + sizeof(typ1))) = var2;	\
	*((typ3*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2))) = var3;	\
	*((typ4*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3))) = var4;	\
	macro_End

#define	thread_SaveState5(typ1, var1, typ2, var2, typ3, var3, typ4, var4, typ5, var5)	\
	macro_Begin	\
	*((typ1*)(thread_Obj->Store)) = var1;	\
	*((typ2*)((thread_Obj->Store) + sizeof(typ1))) = var2;	\
	*((typ3*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2))) = var3;	\
	*((typ4*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3))) = var4;	\
	*((typ5*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4))) = var5;	\
	macro_End

#define	thread_SaveState6(typ1, var1, typ2, var2, typ3, var3, typ4, var4, typ5, var5, typ6, var6)	\
	macro_Begin	\
	*((typ1*)(thread_Obj->Store)) = var1;	\
	*((typ2*)((thread_Obj->Store) + sizeof(typ1))) = var2;	\
	*((typ3*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2))) = var3;	\
	*((typ4*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3))) = var4;	\
	*((typ5*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4))) = var5;	\
	*((typ6*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4) + sizeof(typ5))) = var6;	\
	macro_End

#define	thread_SaveState7(typ1, var1, typ2, var2, typ3, var3, typ4, var4, typ5, var5, typ6, var6, typ7, var7)	\
	macro_Begin	\
	*((typ1*)(thread_Obj->Store)) = var1;	\
	*((typ2*)((thread_Obj->Store) + sizeof(typ1))) = var2;	\
	*((typ3*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2))) = var3;	\
	*((typ4*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3))) = var4;	\
	*((typ5*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4))) = var5;	\
	*((typ6*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4) + sizeof(typ5))) = var6;	\
	*((typ7*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4) + sizeof(typ5) + sizeof(typ6))) = var7;	\
	macro_End

#define	thread_SaveState8(typ1, var1, typ2, var2, typ3, var3, typ4, var4, typ5, var5, typ6, var6, typ7, var7, typ8, var8)	\
	macro_Begin	\
	*((typ1*)(thread_Obj->Store)) = var1;	\
	*((typ2*)((thread_Obj->Store) + sizeof(typ1))) = var2;	\
	*((typ3*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2))) = var3;	\
	*((typ4*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3))) = var4;	\
	*((typ5*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4))) = var5;	\
	*((typ6*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4) + sizeof(typ5))) = var6;	\
	*((typ7*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4) + sizeof(typ5) + sizeof(typ6))) = var7;	\
	*((typ8*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4) + sizeof(typ5) + sizeof(typ6) + sizeof(typ7))) = var8;	\
	macro_End

#define	thread_SaveState(...)	\
	macro_Fn(macro_Fn17(_0, __VA_ARGS__, thread_SaveState8, _15, thread_SaveState7, _13, thread_SaveState6, _11, thread_SaveState5, _9, thread_SaveState4, _7, thread_SaveState3, _5, thread_SaveState2, _3, thread_SaveState1, macro_FnE, macro_FnE)(__VA_ARGS__))

#define	thread_Save	thread_SaveState


// Load thread state from a buffer
#define	thread_LoadState1(typ1, var1)	\
	(var1 = *((typ1*)(thread_Obj->Store)))

#define	thread_LoadState2(typ1, var1, typ2, var2)	\
	macro_Begin	\
	var1 = *((typ1*)(thread_Obj->Store));	\
	var2 = *((typ2*)((thread_Obj->Store) + sizeof(typ1)));	\
	macro_End

#define	thread_LoadState3(typ1, var1, typ2, var2, typ3, var3)	\
	macro_Begin	\
	var1 = *((typ1*)(thread_Obj->Store));	\
	var2 = *((typ2*)((thread_Obj->Store) + sizeof(typ1)));	\
	var3 = *((typ3*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2)));	\
	macro_End

#define	thread_LoadState4(typ1, var1, typ2, var2, typ3, var3, typ4, var4)	\
	macro_Begin	\
	var1 = *((typ1*)(thread_Obj->Store));	\
	var2 = *((typ2*)((thread_Obj->Store) + sizeof(typ1)));	\
	var3 = *((typ3*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2)));	\
	var4 = *((typ4*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3)));	\
	macro_End

#define	thread_LoadState5(typ1, var1, typ2, var2, typ3, var3, typ4, var4, typ5, var5)	\
	macro_Begin	\
	var1 = *((typ1*)(thread_Obj->Store));	\
	var2 = *((typ2*)((thread_Obj->Store) + sizeof(typ1)));	\
	var3 = *((typ3*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2)));	\
	var4 = *((typ4*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3)));	\
	var5 = *((typ5*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4)));	\
	macro_End

#define	thread_LoadState6(typ1, var1, typ2, var2, typ3, var3, typ4, var4, typ5, var5, typ6, var6)	\
	macro_Begin	\
	var1 = *((typ1*)(thread_Obj->Store));	\
	var2 = *((typ2*)((thread_Obj->Store) + sizeof(typ1)));	\
	var3 = *((typ3*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2)));	\
	var4 = *((typ4*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3)));	\
	var5 = *((typ5*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4)));	\
	var6 = *((typ6*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4) + sizeof(typ5)));	\
	macro_End

#define	thread_LoadState7(typ1, var1, typ2, var2, typ3, var3, typ4, var4, typ5, var5, typ6, var6, typ7, var7)	\
	macro_Begin	\
	var1 = *((typ1*)(thread_Obj->Store));	\
	var2 = *((typ2*)((thread_Obj->Store) + sizeof(typ1)));	\
	var3 = *((typ3*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2)));	\
	var4 = *((typ4*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3)));	\
	var5 = *((typ5*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4)));	\
	var6 = *((typ6*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4) + sizeof(typ5)));	\
	var7 = *((typ7*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4) + sizeof(typ5) + sizeof(typ6)));	\
	macro_End

#define	thread_LoadState8(typ1, var1, typ2, var2, typ3, var3, typ4, var4, typ5, var5, typ6, var6, typ7, var7, typ8, var8)	\
	macro_Begin	\
	var1 = *((typ1*)(thread_Obj->Store));	\
	var2 = *((typ2*)((thread_Obj->Store) + sizeof(typ1)));	\
	var3 = *((typ3*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2)));	\
	var4 = *((typ4*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3)));	\
	var5 = *((typ5*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4)));	\
	var6 = *((typ6*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4) + sizeof(typ5)));	\
	var7 = *((typ7*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4) + sizeof(typ5) + sizeof(typ6)));	\
	var8 = *((typ8*)((thread_Obj->Store) + sizeof(typ1) + sizeof(typ2) + sizeof(typ3) + sizeof(typ4) + sizeof(typ5) + sizeof(typ6) + sizeof(typ7)));	\
	macro_End

#define	thread_LoadState(...)	\
	macro_Fn(macro_Fn17(_0, __VA_ARGS__, thread_LoadState8, _15, thread_LoadState7, _13, thread_LoadState6, _11, thread_LoadState5, _9, thread_LoadState4, _7, thread_LoadState3, _5, thread_LoadState2, _3, thread_LoadState1, macro_FnE, macro_FnE)(__VA_ARGS__))

#define	thread_Load	thread_LoadState


// Yields out of a thread
#define	thread_Yield(...)	\
macro_Begin	\
thread_Obj->Line = __LINE__;	\
thread_SaveState(__VA_ARGS__);	\
return thread_yielded;	\
case __LINE__:	\
thread_LoadState(__VA_ARGS__);	\
macro_End


// Wait while a condition is satisfied (active wait)
#define	thread_WaitWhile(wait_cond, ...)	\
macro_Begin	\
thread_line = __LINE__;	\
thread_SaveState(__VA_ARGS__);	\
case __LINE__:	\
if(wait_cond) return thread_waiting;	\
thread_LoadState(__VA_ARGS__);	\
macro_End


// Wait until a condition is satisfied (active wait)
#define	thread_WaitUntil(wait_cond, ...)	\
thread_WaitWhile(!(wait_cond), __VA_ARGS__)


// Exit out of a thread
#define	thread_Exit()	\
return thread_exited


// Wait on semaphore
#define	thread_SemWait(semptr, ...)	\
macro_Begin	\
*(semptr)--;	\
if(*(semptr) < 0)	\
{	\
thread_Obj->Sync = (semptr);	\
thread_Obj->Line = __LINE__;	\
thread_SaveState(__VA_ARGS__);	\
return thread_sem_blocked;	\
case __LINE__:	\
thread_LoadState(__VA_ARGS__);	\
}	\
macro_End

#define thread_SemTake	\
thread_SemWait


// Signal semaphore
#define	thread_SemSignal(semptr, ...)	\
macro_Begin	\
*(semptr)++;	\
if(*(semptr) <= 0)	\
{	\
	thread_Obj->Sync = (semptr);	\
	thread_Obj->Line = __LINE__;	\
	thread_SaveState(__VA_ARGS__);	\
	return thread_sem_released;	\
	case __LINE__:	\
	thread_LoadState(__VA_ARGS__);	\
}	\
macro_End

#define thread_SemGive	\
thread_SemSignal


// Wait on Mutex
#define	thread_MutexWait(mutexptr, ...)	\
macro_Begin	\
if(*(mutexptr) != null)	\
{	\
	thread_Obj->Sync = (mutexptr);	\
	thread_Obj->Line = __LINE__;	\
	thread_SaveState(__VA_ARGS__);	\
	return thread_mutex_blocked;	\
	case __LINE__:	\
	thread_LoadState(__VA_ARGS__);	\
}	\
*(mutexptr) = (Mutex) thread_Obj;	\
macro_End

#define thread_MutexTake	\
thread_MutexWait

#define thread_MutexLock	\
thread_MutexWait


// Signal Mutex
#define	thread_MutexSignal(mutexptr, ...)	\
macro_Begin	\
if(*(mutexptr) == (Mutex) thread_Obj)	\
{	\
	thread_Obj->Sync = (mutexptr);	\
	thread_Obj->Line = __LINE__;	\
	thread_SaveState(__VA_ARGS__);	\
	return thread_mutex_released;	\
	case __LINE__:	\
	thread_LoadState(__VA_ARGS__);	\
}	\
macro_End

#define thread_MutexGive	\
thread_MutexSignal

#define thread_MutexUnlock	\
thread_MutexSignal


#endif /* _CORE_THREAD_H_ */