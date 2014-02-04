#ifndef _CORE_SEM_H_
#define _CORE_SEM_H_


// Define
typedef int16 Sem;


// Raw Wait (do not use directly)
#define sem_Wait(sem)	\
(sem--)

#define sem_Take	\
sem_Wait


// Signal (Raw)
#define sem_Signal(sem)	\
(sem++)

#define sem_Give	\
sem_Signal


// Check if free to use (Raw)
#define sem_IsFree(sem)	\
(sem > 0)


#endif /* _CORE_SEM_H_ */