#ifndef _CORE_SEM_H_
#define _CORE_SEM_H_


// Semaphore type
#define sem_type	0


// Define
typedef struct _Sem
{
	uword	Type;
	word	Sync;
}Sem;


// Initialize
#define sem_Init(sem, start)	\
macro_Begin	\
(sem)->Type = sem_type;	\
(sem)->Sync = start;	\
macro_End


// Raw Wait (do not use directly)
#define sem_Wait(sem)	\
((sem)->Sync--)

#define sem_Take	\
sem_Wait


// Signal (Raw)
#define sem_Signal(sem)	\
((sem)->Sync++)

#define sem_Give	\
sem_Signal


// Check if free to use (Raw)
#define sem_IsFree(sem)	\
((sem)->Sync > 0)


#endif /* _CORE_SEM_H_ */