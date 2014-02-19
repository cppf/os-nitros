#ifndef _DATA_LIST_H_
#define _DATA_LIST_H_


// Define
#define	list_Define(type, sz)	\
typedef struct _list_##sz##type	\
{	\
	uword	Count;		\
	uword	Size;		\
	type	Value[sz];	\
}list_##sz##type


// Header
#define list_Header	\
bagHeader


// Initialize
#define list_Init(lst)	\
bag_Init(lst)

// Clear
#define	list_Clear(lst)	\
bag_Clear(lst)


// GetAvail
#define	list_GetAvail(lst)	\
bag_GetAvail(lst)


// HasAvail
#define list_HasAvail(lst)	\
bag_HasAvail(lst)


// GetFree
#define	list_GetFree(lst)	\
bag_GetFree(lst)


#define list_HasFree(lst)	\
bag_HasFree(lst)


// IndexOf
#define list_IndexOf(lst, elem)	\
bag_IndexOf(lst, elem)


// Add
#define list_Add(lst, elem)	\
bag_Add(lst, elem)


// RemoveAt
void list_RemoveAtF(list* lst, uword indx, uword sft);
void list_RemoveAtF(list* lst, uword indx, uword sft)
{
	lst->Count--;
	uint moveBytes = (lst->Count - indx) << sft;
	if(moveBytes) mem_Copy(lst->Value + indx, lst->Value + indx + 1, moveBytes);
}

#define list_RemoveAt(lst, indx)	\
macro_Begin	\
(lst).Count--;	\
uint moveBytes = ((lst).Count - (indx)) * sizeof((lst).Value[0]);	\
if(moveBytes) mem_Copy((lst).Value + (indx), (lst).Value + (indx) + 1, moveBytes);	\
macro_End

#define list_RemoveAt(lst, indx)	\
list_RemoveAtF((List*)(lst), (uint)(indx))


// Remove
uword list_RemoveF(List* lst, uint elem);
uword list_RemoveF(List* lst, uint elem)
{
	uword indx = list_IndexOf(lst, elem);
	if(indx != (uword)-1) list_RemoveAt(lst, indx);
	return indx;
}

#define	list_Remove(lst, elem)	\
list_RemoveF((List*)(lst), (uint)(elem))


#endif /* _DATA_LIST_H_ */