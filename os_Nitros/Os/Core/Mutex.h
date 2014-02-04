#ifndef _CORE_MUTEX_H_
#define _CORE_MUTEX_H_


// Define
typedef int16 Mutex;


// Raw Wait (do not use directly)
#define mutex_Wait(mutex, fn)	\
(mutex = (Mutex)(fn))

#define mutex_Take	\
mutex_Wait

#define mutex_Lock	\
mutex_Wait


// Signal (Raw)
#define mutex_Signal(mutex)	\
(mutex = 0)

#define mutex_Give	\
mutex_Signal

#define mutex_Unlock	\
mutex_Signal


// Check if free to use (Raw)
#define mutex_IsFree(mutex)	\
(mutex != 0)

#define mutex_IsUnlocked	\
mutex_IsFree


// Check if can signal (Raw)
#define mutex_CanSignal(mutex, fn)	\
(mutex == (Mutex)(fn))

#define mutex_CanGive	\
mutex_CanSignal

#define mutex_CanUnlock	\
mutex_CanSignal


#endif /* _CORE_MUTEX_H_ */