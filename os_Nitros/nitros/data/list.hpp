#ifndef _DATA_LIST_HPP_
#define _DATA_LIST_HPP_


// generic list definition
template <typename T, uword size>
class list
{
	public:
	uword	Count;
	uword	Size;
	T		Item[size];

	public:
	inline uword Avail()
	{
		return Count;
	}
	inline uword Free()
	{
		return size - Count;
	}
	inline void Clear()
	{
		Count = 0;
	}
	noInline void Add(T item)
	{
		Item[Count++] = item;
	}
	noInline uword IndexOf(T item)
	{
		for(uword i=0, n=Count; n>0; i++, n--)
			if(Item[i] == item) return i;
		return (uword) -1;
	}
	noInline void InsertAt(uword indx, T item)
	{
		Item[Count++] = Item[indx];
		Item[indx] = item;
	}
	noInline void DeleteAt(uword indx)
	{
		Item[indx] = Item[--Count];
	}
	noInline void Remove(T item)
	{
		uword indx = IndexOf(item);
		if(indx != (uword) -1) DeleteAt(indx);
	}
};

typedef list<uint8, 8> list8_uint8;
typedef list<uint16, 8> list8_uint16;


// 8-bit list definition
template <typename T, uword size>
class list8
{
	public:
	uword	Count;
	uword	Size;
	T		Item[size];

	public:
	inline uword Avail()
	{
		return Count;
	}
	inline uword Free()
	{
		return size - Count;
	}
	inline void Clear()
	{
		Count = 0;
	}
	inline void Add(T item)
	{
		((list8_uint8*)this)->Add((uint8)item);
	}
	inline uword IndexOf(T item)
	{
		return ((list8_uint8*)this)->IndexOf((uint8)item);
	}
	inline void InsertAt(uword indx, T item)
	{
		((list8_uint8*)this)->InsertAt(indx, (uint8)item);
	}
	inline void DeleteAt(uword indx)
	{
		((list8_uint8*)this)->DeleteAt(indx);
	}
	inline void Remove(T item)
	{
		((list8_uint8*)this)->Remove((uint8)item);
	}
};


// 16-bit list definition
template <typename T, uword size>
class list16
{
	public:
	uword	Count;
	uword	Size;
	T		Item[size];

	public:
	inline uword Avail()
	{
		return Count;
	}
	inline uword Free()
	{
		return size - Count;
	}
	inline void Clear()
	{
		Count = 0;
	}
	inline void Add(T item)
	{
		((list8_uint16*)this)->Add((uint16)item);
	}
	inline uword IndexOf(T item)
	{
		return ((list8_uint16*)this)->IndexOf((uint16)item);
	}
	inline void InsertAt(uword indx, T item)
	{
		((list8_uint16*)this)->InsertAt(indx, (uint16)item);
	}
	inline void DeleteAt(uword indx)
	{
		((list8_uint16*)this)->DeleteAt(indx);
	}
	inline void Remove(T item)
	{
		((list8_uint16*)this)->Remove((uint16)item);
	}
};

// initialize a list
#define list_Init(lst)	\
((lst).Size = ((sizeof(lst) - 2) / sizeof(uint)))
/*
// list definition
template <typename T, uword size>
class listStd
{
	public:
	uword	Count;
	uword	Size;
	T		Item[size];

	inline uword Avail();
	inline uword Free();
	inline void Add(T item);
};


// list pointer
typedef listStd<uint, 8> listDef;
typedef listDef* listPtr;

// pointer to list
#define list_Ptr(lst)	\
((listPtr)(&(lst)))

// initialize a list
#define list_Init(lst)	\
((lst).Size = ((sizeof(lst) - 2) / sizeof(uint)))

// available data
#define list_Avail(lst)	\
(lst).Count

// free space
#define list_Free(lst)	\
((lst).Size - (lst).Count)

// clear list
#define list_Clear(lst)	\
((lst).Count = (lst).Front = 0)


// add item (at the end)
noInline void list_AddF(listPtr lst, uint item);
void list_AddF(listPtr lst, uint item)
{
	lst->Item[lst->Count++] = item;
}
#define list_Add(lst, item)	\
list_AddF(list_Ptr(lst), (uint)(item))


// index of an item
noInline uword list_IndexOfF(listPtr lst, uint item);
uword list_IndexOfF(listPtr lst, uint item)
{
	for(uword i=0, n=lst->Count; n>0; i++, n--)
	if(lst->Item[i] == item) return i;
	return (uword) -1;
}
#define list_IndexOf(lst, item)	\
list_IndexOfF(list_Ptr(lst), (uint)(item))


// insert item at specific index
noInline void list_InsertAtF(listPtr lst, uword indx, uint item);
void list_InsertAtF(listPtr lst, uword indx, uint item)
{
	lst->Item[lst->Count++] = lst->Item[indx];
	lst->Item[indx] = item;
}
#define	list_InsertAt(lst, indx, item)	\
list_InsertAtF(list_Ptr(lst), (uword)(indx), (uint)(item))


// delete item at a specific index
void list_DeleteAtF(listPtr lst, uword indx)
{
	lst->Item[indx] = lst->Item[--(lst->Count)];
}
#define list_DeleteAt(lst, indx)	\
list_DeleteAtF(list_Ptr(lst), (uword)(indx))


// remove item from list
noInline void list_RemoveF(listPtr lst, uint item);
void list_RemoveF(listPtr lst, uint item)
{
	uword indx = list_IndexOf(lst, item);
	if(indx != (uword) -1) list_DeleteAt(lst, indx);
}
#define list_Remove(lst, item)	\
list_RemoveF(list_Ptr(lst), (uint)(item))


// available data
template<typename T, uword size>
uword listStd<T, size>::Avail()
{
	return Count;
}

// free space
template<typename T, uword size>
uword listStd<T, size>::Free()
{
	return Size - Count;
}


// add item (at the end)
template <typename T, uword size>
void listStd<T, size>::Add(T item)
{
	list_Add(*this, item);
}
*/

#endif /* _DATA_LIST_HPP_ */