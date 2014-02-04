#ifndef _CORE_SEM_H_
#define _CORE_SEM_H_


// Define
typedef word Sem;


// Initialize
#define sem_Init(sem, start)	\
(*(sem) = (start))


// Wait
#define sem_Wait(sem)	\
macro_Begin	\
*(sem)--;	\
if(*(sem) < 0) task_SemBlock(sem);	\
macro_End

#define sem_Take	\
sem_Wait


// Signal
#define sem_Signal(sem)	\
macro_Begin	\
*(sem)++;	\
if(*(sem) <= 0) task_SemRelease(sem);	\
macro_End

#define sem_Give	\
sem_Signal


// Check if free to use (Raw)
#define sem_IsFree(sem)	\
(*(sem) > 0)


#endif /* _CORE_SEM_H_ */