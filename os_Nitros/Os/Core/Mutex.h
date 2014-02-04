#ifndef _CORE_MUTEX_H_
#define _CORE_MUTEX_H_


// Mutex type
#define mutex_type	1


// Define
typedef struct _Mutex
{
	uword	Type;
	void*	Sync;
}Mutex;


// Initialize
#define mutex_Init(mtx)	\
macro_Begin	\
(mtx)->Type = mutex_type;	\
(mtx)->Sync = null;	\
macro_End


// Raw Wait (do not use directly)
#define mutex_Wait(mtx, addr)	\
((mtx)->Sync = (Mutex)(addr))

#define mutex_Take	\
mutex_Wait

#define mutex_Lock	\
mutex_Wait


// Signal (Raw)
#define mutex_Signal(mtx)	\
((mtx)->Sync = 0)

#define mutex_Give	\
mutex_Signal

#define mutex_Unlock	\
mutex_Signal


// Check if free to use (Raw)
#define mutex_IsFree(mtx)	\
((mtx)->Sync != 0)

#define mutex_IsUnlocked	\
mutex_IsFree


// Check if can signal (Raw)
#define mutex_CanSignal(mtx, addr)	\
((mtx)->Sync == (Mutex)(addr))

#define mutex_CanGive	\
mutex_CanSignal

#define mutex_CanUnlock	\
mutex_CanSignal


#endif /* _CORE_MUTEX_H_ */