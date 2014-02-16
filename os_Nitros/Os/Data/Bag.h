#ifndef _DATA_BAG_H_
#define _DATA_BAG_H_


// Define
#define	bag_Define(sz)	\
typedef struct _bag##sz	\
{	\
	uword	Count;		\
	uword	Size;		\
	uint	Value[sz];	\
}bag##sz


// Header
typedef struct _bagHeader
{
	uword	Count;
	uword	Size;
}bagHeader;


// Default
bag_Define(2);
bag_Define(4);
bag_Define(8);
bag_Define(16);
bag_Define(32);
bag_Define(64);
bag_Define(128);
bag_Define(256);

#ifndef bag_Default
#define	bag_Default	bag16
#endif

typedef bag_Default	bag;


// Initialize
#define	bag_Init(bg)	\
macro_Begin	\
(bg)->Count = 0;	\
(bg)->Size = (sizeof(bg) - sizeof(bagHeader)) / sizeof((bg).Value[0]);	\
macro_End


// Clear
#define	bag_Clear(bg)	\
((bg)->Count = 0)


// GetAvail
#define	bag_GetAvail(bg)	\
((bg)->Count)


// HasAvail
#define bag_HasAvail(bg)	\
bag_GetAvail(bg)


// GetFree
#define	bag_GetFree(bg)	\
((bg)->Size - (bg)->Count)


#define bag_HasFree(bg)	\
bag_GetFree(bg)


// IndexOf
uword bag_IndexOfF(Bag* bg, uint elem);
uword bag_IndexOfF(Bag* bg, uint elem)
{
	for(uword indx = 0; indx < bg->Count; indx++)
	{
		if(bg->Value[indx] == elem)
		return indx;
	}
	return -1;
}

#define	bag_IndexOf(bg, elem)	\
bag_IndexOfF((Bag*)(bg), (uint)(elem))


// Add
inline void bag_AddF(Bag* bg, uint elem);
inline void bag_AddF(Bag* bg, uint elem)
{
	bg->Value[bg->Count] = elem;
	bg->Count++;
}

#define bag_Add(bg, elem)	\
bag_AddF((Bag*)(bg), (uint)(elem))


// RemoveAt
inline void bag_RemoveAtF(Bag* bg, uword indx);
inline void bag_RemoveAtF(Bag* bg, uword indx)
{
	bg->Count--;
	bg->Value[indx] = bg->Value[bg->Count];
}

#define bag_RemoveAt(bg, indx)	\
bag_RemoveAtF((Bag*)(bg), (uint)(indx))


// Remove
uword bag_RemoveF(Bag* bg, uint elem);
uword bag_RemoveF(Bag* bg, uint elem)
{
	uword indx = bag_IndexOf(bg, elem);
	if(indx != (uword)-1) bag_RemoveAt(bg, indx);
	return indx;
}

#define	bag_Remove(bg, elem)	\
bag_RemoveF((Bag*)(bg), (uint)(elem))


#endif /* _DATA_BAG_H_ */