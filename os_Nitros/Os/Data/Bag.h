#ifndef _DATA_BAG_H_
#define _DATA_BAG_H_


// Define
#define	bag_Define(sz)	\
typedef struct _bag##sz	\
{	\
	uint	Max;	\
	uint	Front;	\
	uint	Count;	\
	byte	Value[sz];	\
}bag##sz


// Header
typedef struct _bagHeader
{
	uint	Max;
	uint	Count;
	uint	Size;
}bagHeader;


// Default
bag_Define(8);
bag_Define(16);
bag_Define(32);
bag_Define(64);
bag_Define(128);
bag_Define(256);
bag_Define(512);
bag_Define(1024);
bag_Define(2048);
bag_Define(4096);
bag_Define(8192);
bag_Define(16384);
typedef bag32 bag;


// Initialize
#define	bag_Init(bg)	\
macro_Begin	\
(bg).Front = 0;	\
(bg).Count = 0;	\
(bg).Max = sizeof(bg) - sizeof(bagHeader) - 1;	\
macro_End


// Clear / RemoveAll
#define	bag_Clear(bg)	\
((bg).Count = 0)
#define bag_RemoveAll	bag_Clear


// Count / Avail
#define	bag_Count(bg)	\
((bg).Count)
#define bag_Avail	bag_Count


// Free
#define	bag_Free(bg)	\
((bg).Max - (bg).Count)


// Add / Push
#define bag_AddToRear()	\
(bg).Value[(bg).Front + (bg).Count] = elem


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


#endif /* _DATA_LIST_H_ */