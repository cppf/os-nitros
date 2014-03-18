#ifndef _CORE_SEM_HPP_
#define _CORE_SEM_HPP_


// Define
typedef word sem;


// Initialize
#define sem_Init(semp, start)	\
(*(semp) = (start))


// Wait
#define sem_Wait(semp)	\
macro_Begin	\
*(semp)--;	\
if(*(semp) < 0) task_SemBlock(semp);	\
macro_End

#define sem_Take	\
sem_Wait


// Signal
#define sem_Signal(semp)	\
macro_Begin	\
*(semp)++;	\
if(*(semp) <= 0) task_SemRelease(semp);	\
macro_End

#define sem_Give	\
sem_Signal


// Check if free to use (Raw)
#define sem_IsFree(semp)	\
(*(semp) > 0)


#endif /* _CORE_SEM_HPP_ */