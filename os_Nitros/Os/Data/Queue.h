#ifndef _DATA_QUEUE_H_
#define _DATA_QUEUE_H_


// Define
#define	queue_Define(sz)	\
typedef struct _Queue##sz	\
{	\
	uword	Count;		\
	uword	Front;		\
	uword	Max;		\
	uint	Item[sz];	\
}Queue##sz


// Header
typedef struct _queue_Header
{
	uword	Count;
	uword	Front;
	uword	Max;
}queue_Header;


// Default Queue
queue_Define(2);
queue_Define(4);
queue_Define(8);
queue_Define(16);
queue_Define(32);
queue_Define(64);
queue_Define(128);
queue_Define(256);

#ifndef queue_Default
#define	queue_Default	Queue16
#endif

typedef queue_Default	Queue;


// Initialize
#define	queue_Init(que)	\
macro_Begin	\
(que)->Count = 0;	\
(que)->Front = 0;	\
(que)->Max = ((sizeof(que) - sizeof(queue_Header)) / sizeof((que).Value[0])) - 1;	\
macro_End


// Clear
#define queue_Clear(que)	\
((que)->Count = 0)


// GetAvail
#define	queue_GetAvail(que)	\
((que)->Count)


// HasAvail
#define	queue_HasAvail(que)	\
queue_GetAvail(que)


// GetFree
#define	queue_GetFree(que)	\
((que)->Max + 1 - queue_GetAvail(que))


// HasFree
#define queue_HasFree(que)	\
((que)->Count <= (que)->Max)


// Get Rear pointer
#define queue_Rear(que)	\
(((que)->Front + (que)->Count) & (que)->Max)


// Add
inline void queue_AddF(Queue* que, uint elem);
inline void queue_AddF(Queue* que, uint elem)
{
	que->Value[queue_Rear(que)] = elem;
	que->Count++;
}

#define queue_Add(que, elem)	\
queue_AddF((Queue*)(que), (uint)(elem))


// Peek
#define queue_Peek(que)	\
((que)->Value[(que)->Front])


// Remove
inline uint queue_RemoveF(Queue* que);
inline uint queue_RemoveF(Queue* que)
{
	que->Count--;
	return que->Value[que->Front++];
}

#define	queue_Remove(que)	\
queue_RemoveF((Queue*)(que))


#endif /* _DATA_QUEUE_H_ */