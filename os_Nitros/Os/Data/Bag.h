#ifndef _DATA_BAG_H_
#define _DATA_BAG_H_


// Define
#define	bag_Define(type, sz)	\
typedef struct _bag_##sz##type	\
{	\
	uword	Count;		\
	uword	Size;		\
	type	Value[sz];	\
}bag_##sz##type


// Header
typedef struct _bagHeader
{
	uword	Count;
	uword	Size;
}bagHeader;


// Initialize
#define	bag_Init(bg)	\
macro_Begin	\
(bg).Count = 0;	\
(bg).Size = (sizeof(bg) - sizeof(bagHeader)) / sizeof((bg).Value[0]);	\
macro_End


// Clear
#define	bag_Clear(bg)	\
((bg).Count = 0)


// GetAvail
#define	bag_GetAvail(bg)	\
((bg).Count)


// HasAvail
#define bag_HasAvail(bg)	\
bag_GetAvail(bg)


// GetFree
#define	bag_GetFree(bg)	\
((bg).Size - (bg).Count)


#define bag_HasFree(bg)	\
bag_GetFree(bg)


// IndexOf
#define bag_IndexOf(bg, elem)	\
macro_Begin	\
for(uword indx = 0; indx < (bg).Count; indx++)	\
	if((bg).Value[indx] == (elem)) break;	\
macro_Return(indx);	\
macro_End


// Add
#define bag_Add(bg, elem)	\
((bg).Value[(bg).Count++] = elem)


// RemoveAt
#define bag_RemoveAt(bg, indx)	\
((bg).Value[indx] = (bg).Value[--(bg).Count])


// Remove
#define bag_Remove(bg, elem)	\
macro_Begin	\
uword indx = bag_IndexOf(bg, elem);	\
if(indx < (bg).Count) bag_RemoveAt(bg, indx);	\
macro_Return(indx);	\
macro_End


#endif /* _DATA_BAG_H_ */