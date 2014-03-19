#ifndef _CORE_TASK_HPP_
#define _CORE_TASK_HPP_


// Status
#define	task_DONE		0x00
#define	task_WAIT		0x10
#define	task_YIELD		0x20
#define task_BLOCK		0x30
#define task_RELEASE	0x40


// Priority
#define task_LOW_PRIORITY	0
#define task_MED_PRIORITY	1
#define task_HIGH_PRIORITY	2


class task
{
	public:
	void*	Fn;
	void*	Addr;
	void*	Data;
	void*	Block;
	uword	Status;
	uword	Priority;
	
	public:
	task(void* fn, void* data, uword priority)
	{
		Fn = fn;
		Data = data;
		Status = task_YIELD;
		Priority = priority;
	}
};


// Task function pointer
typedef uword (*taskFnPtr)(task*);


// Define Task function
#define	task_Fn(name)	\
uword name(task* task_Obj)


// Task prologue
#define task_Begin	\
if(task_Obj->Addr) goto task_Obj->Addr;


// Task epilogue
#define task_End	\
return task_DONE;


// Mark checkpoint
#define task_SaveNamed(name, ...)	\
macro_Begin	\
task_Obj->Addr = &&name;	\
mem_Write(__VA_ARGS__);	\
goto name##_skip;	\
name:	\
mem_Read(__VA_ARGS__);	\
name##_skip:	\
macro_End

#define task_Save(...)	\
task_SaveNamed(task_lbl_##__LINE__, __VA_ARGS__)


// Yield control
#define	task_Yield(...)	\
macro_Begin	\
task_Save(__VA_ARGS__);	\
return task_YIELD;	\
macro_End


// Wait while (active wait)
#define	task_WaitWhile(cond, ...)	\
macro_Begin	\
task_Save(__VA_ARGS__);	\
if(cond) return task_WAIT;	\
macro_End


// Wait until (active wait)
#define	task_WaitUntil(cond, ...)	\
task_WaitWhile(!(cond), __VA_ARGS__)


// Exit task
#define	task_Done()		return task_DONE;
#define task_Exit	task_Done


// Yield if blocked
#define task_Block()	\
if(task_Obj->Block) return


#endif /* _CORE_TASK_HPP_ */