#ifndef _CORE_PROCESS_H_
#define _CORE_PROCESS_H_


// Define
#define process_Define(sz)	\
typedef struct _Process##sz	\
{	\
	void*	Fn;		\
	uint	Data;	\
	uint	Addr;	\
	int16*	Sync;	\
	uword	State;	\
	byte	Stack[sz];	\
}Process##sz;


// Header
typedef struct _process_Header
{
	void*	Fn;
	uint	Data;
	uint	Addr;
	int16*	Sync;
	uword	State;
}process_Header;


// Default
process_Define(35);
process_Define(40);
process_Define(45);
process_Define(50);
process_Define(55);

#ifndef process_Default
#define	process_Default	Process50
#endif

typedef process_Default	Process;


// Process maintenance
#ifndef process_QueueType
#define thread_QueueType	Queue16
#endif

#ifndef thread_BagType
#define thread_BagType		Bag16
#endif

thread_QueueType	thread_ReadyQueue;
thread_BagType		thread_BlockedBag;


#endif /* _CORE_PROCESS_H_ */