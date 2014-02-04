#ifndef _DATA_LIST_H_
#define _DATA_LIST_H_


// Define
#define	list_Define(sz)	\
typedef struct _List##sz	\
{	\
	uword	Count;		\
	uword	Size;		\
	uint	Value[sz];	\
}List##sz


// Header
#define list_Header	\
bag_Header


// Default List
list_Define(2);
list_Define(4);
list_Define(8);
list_Define(16);
list_Define(32);
list_Define(64);
list_Define(128);
list_Define(256);

#ifndef list_Default
#define	list_Default	List16
#endif

typedef list_Default	List;


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
void list_RemoveAtF(List* lst, uword indx);
void list_RemoveAtF(List* lst, uword indx)
{
	lst->Count--;
	uint moveBytes = (lst->Count - indx) << 1;
	if(moveBytes) mem_Copy(lst->Value + indx, lst->Value + indx + 1, moveBytes);
}

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