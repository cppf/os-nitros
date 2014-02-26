#ifndef _CORE_TASK_HPP_
#define _CORE_TASK_HPP_



// Status
#define task_unstarted			0x00
#define	task_completed			0xF0
#define task_blocked			0x70
#define task_released			0x60
#define	task_yielded			0x50
#define	task_waiting			0x40


class task
{
	public:
	void*	Addr;
	void*	Data;
	void*	Stack;
	uword	State;
	uword	Priority;
	
	public:
	inline uword IsBlocked()
	{
		return State == task_blocked;
	}
};


// Task function pointer
typedef void (*taskFnPtr)(task*);


// Initialize
#define task_InitF(tsk, addr, data)	\
macro_Begin	\
(tsk)->Addr = addr;	\
(tsk)->Data = data;	\
(tsk)->Block = null;	\
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
void name(task* task_Obj)


// Save task state to a buffer
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


// Load task state from a buffer
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
#define task_Checkpoint(name, ...)	\
macro_Begin	\
task_Current->Addr = &&name;	\
task_SaveState(__VA_ARGS__);	\
goto name##_skip_load;	\
name:	\
task_LoadState(__VA_ARGS__);	\
name##_skip_load:	\
macro_End


// Yields out of a task
#define	task_Yield(...)	\
macro_Begin	\
task_Checkpoint(task_label##__LINE__, __VA_ARGS__);	\
task_Current->State = task_yielded;	\
return;	\
macro_End


// Wait while a condition is satisfied (active wait)
#define	task_WaitWhile(wait_cond, ...)	\
macro_Begin	\
task_Checkpoint(task_label##__LINE__, __VA_ARGS__);	\
if(wait_cond)	\
{	\
	task_Current->State = task_waiting;	\
	return;	\
}	\
macro_End


// Wait until a condition is satisfied (active wait)
#define	task_WaitUntil(wait_cond, ...)	\
task_WaitWhile(!(wait_cond), __VA_ARGS__)


// Exit out of a task
#define	task_Complete()	\
macro_Begin	\
task_Current->State = task_completed;	\
return;	\
macro_End

#define task_Exit	\
task_Complete

#define task_End	\
task_Complete


// Yield if blocked
#define task_YieldIfBlocked()	\
if(task_Current->State == task_blocked) return


// Wait on semaphore
#define	task_SemWait(sem, ...)	\
macro_Begin	\
task_Checkpoint(task_label##__LINE__, __VA_ARGS__);	\
sem_Wait(sem);	\
task_YieldIfBlocked();	\
macro_End

#define task_SemTake	\
task_SemWait


// Signal semaphore
#define	task_SemSignal(semptr, ...)	\
sem_Signal(sem)

#define task_SemGive	\
task_SemSignal


// Begin a blocking call
#define task_BeginBlockingCall(...)	\
task_Checkpoint(task_label##__LINE__, __VA_ARGS__)


// End a blocking call
#define task_EndBlockingCall()	\
task_YieldIfBlocked()


// Internal function, called when a task
// is to be blocked due to a semaphore
inline void task_SemBlockF(Sem* sem);
inline void task_SemBlockF(Sem* sem)
{
	task_Current->Block = sem;
	task_Current->State = task_blocked;
}

#define task_SemBlock(sem)	\
task_SemBlockF((Sem*)(sem))


// Internal function, called when a task
// is to be released due to a semaphore
void task_SemReleaseF(Sem* sem);
void task_SemReleaseF(Sem* sem)
{
	Task* tsk = (Task*) task_Blocked.Value;
	for (uword i = 0; i < bag_GetAvail(&task_Blocked); i++, tsk++)
	{
		if(tsk->Block == sem)
		{
			bag_RemoveAt(&task_Blocked, i);
			tsk->Block = null;
			tsk->State = task_released;
			queue_Add(&task_Ready, tsk);
			return;
		}
	}
}

#define task_SemRelease(sem)	\
task_SemReleaseF((Sem*)(sem))


#endif /* _CORE_TASK_HPP_ */