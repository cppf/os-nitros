#ifndef _DATA_LIST_HPP_
#define _DATA_LIST_HPP_


// list definition
template <typename T, uword size>
class list
{
	public:
	uword	Count;
	uword	Size;
	T		Item[size];

	inline uword Avail()
	{
		return Count;
	}
	inline uword Free()
	{
		return Size - Count;
	}
	inline void Add(T item);
};


// list pointer
typedef list<uint, 8> listDef;
typedef listDef* listPtr;

// Obtain pointer to a list
#define list_Ptr(lst)	\
((listPtr)(&(lst)))


// Initialize a list
#define list_Init(lst)	\
((lst).Size = ((sizeof(lst) - 2) / sizeof(uint)))


// Available data
#define list_Avail(lst)	\
(lst).Count


// Free space
#define list_Free(lst)	\
((lst).Size - (lst).Count)


// Clear list
#define list_Clear(lst)	\
((lst).Count = (lst).Front = 0)


// Add item (at the end)
noInline void list_AddF(listPtr lst, uint item);
void list_AddF(listPtr lst, uint item)
{
	lst->Item[(lst)->Count++] = (item);
}
#define list_Add(lst, item)	\
list_AddF(list_Ptr(lst), (uint)(item))


// Index of an item
noInline uword list_IndexOfF(listPtr lst, uint item);
uword list_IndexOfF(listPtr lst, uint item)
{
	for(uword i=0, n=lst->Count; n>0; i++, n--)
	if(lst->Item[i] == item) return i;
	return (uword) -1;
}
#define list_IndexOf(lst, item)	\
list_IndexOfF(list_Ptr(lst), (uint)(item))


template <typename T, uword size>
inline void list<T, size>::Add(T item)
{
	list_Add(*this, item);
}

/*
#define	list_InsertAt(lst, indx, item)	\
macro_Begin	\
	list_Add(lst, (lst).Item[indx]);	\
	(lst).Item[indx] = (item);	\
macro_End

#define list_DeleteAt(lst, indx)	\
((lst).Item[indx] = (lst).Item[--(lst).Count])

noInline void list_RemoveF(listPtr lst, uint item);
void list_RemoveF(listPtr lst, uint item)
{
	uword indx = list_IndexOf(lst, item);
	if(indx != (uword) -1) list_DeleteAt(lst, indx);
}
#define list_Remove(lst, item)	\
list_RemoveF(list_Ptr(lst), (uint)(item))
*/
#endif /* _DATA_LIST_HPP_ */