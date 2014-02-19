#ifndef _DATA_BAG_H_
#define _DATA_BAG_H_


// Define
#define	bag_Define(typ, sz)	\
typedef struct _bag_##sz##typ	\
{	\
	uword	Count;	\
	uword	Rear;	\
	typ		Item[sz];	\
}bag_##sz##typ


// Header
typedef struct _bagHeader
{
	uword	Count;
	uword	Rear;
}bagHeader;


// Access
#define bag_ItemSize(bg)			(sizeof((bg).Item[0]))
#define bag_BuffSize(bg)			(sizeof(bg) - sizeof(bagHeader))
#define bag_Size(bg)				(bag_BuffSize(bg) / bag_ItemSize(bg))
#define bag_Max(bg)					(bag_Size(bg) - 1)
#define bag_Limit(bg, indx)			((indx) & bag_Max(bg))
#define	bag_Count(bg)				((bg).Count)
#define bag_Avail					bag_Count
#define bag_IsAvail					bag_Count
#define	bag_Free(bg)				(bag_Size(bg) - (bg).Count)
#define bag_IsFree					bag_Free
#define bag_Rear(bg)				((bg).Rear)
#define bag_Back(bg)				bag_Limit(bg, (bg).Rear - 1)
#define bag_Front(bg)				bag_Limit(bg, (bg).Rear - (bg).Count)
#define bag_MidRear(bg, indx)		bag_Limit(bg, (bg).Rear - indx)
#define bag_MidBack(bg, indx)		bag_Limit(bg, (bg).Rear - 1 - indx)
#define bag_MidFront(bg, indx)		bag_Limit(bg, (bg).Rear - (bg).Count + indx)
#define bag_Mid						bag_MidFront
#define bag_RearPtr(bg)				((bg).Item + bag_Rear(bg))
#define bag_BackPtr(bg)				((bg).Item + bag_Back(bg))
#define bag_FrontPtr(bg)			((bg).Item + bag_Front(bg))
#define bag_MidRearPtr(bg, indx)	((bg).Item + bag_MidRear(bg, indx))
#define bag_MidBackPtr(bg, indx)	((bg).Item + bag_MidBack(bg, indx))
#define bag_MidFrontPtr(bg, indx)	((bg).Item + bag_MidFront(bg, indx))
#define bag_MidPtr					bag_MidFront


// Peek
#define bag_PeekRear(bg)			(*bag_RearPtr(bg))
#define bag_PeekBack(bg)			(*bag_BackPtr(bg))
#define bag_PeekFront(bg)			(*bag_FrontPtr(bg))
#define bag_PeekMidRear(bg, indx)	(*bag_MidRearPtr(bg, indx))
#define bag_PeekMidBack(bg, indx)	(*bag_MidBackPtr(bg, indx))
#define bag_PeekMidFront(bg, indx)	(*bag_MidFrontPtr(bg, indx))
#define bag_PeekMid					bag_PeekMidFront
#define bag_Peek					bag_PeekMidFront


// Clear / Init / RemoveAll
#define	bag_Clear(bg)		((bg).Rear = (bg).Count = 0)
#define bag_RemoveAll		bag_Clear
#define	bag_Init			bag_Clear


// Push / AddTo / Add
#define bag_PushFront(bg, item)	\
macro_Begin	\
(bg).Count++;	\
*bag_FrontPtr(bg) = item;	\
macro_End
#define bag_AddToFront	bag_PushFront

#define bag_PushRear(bg, item)	\
macro_Begin	\
(bg).Count++;	\
*bag_RearPtr(bg) = item;	\
(bg).Rear = bag_Limit(bg, (bg).Rear + 1);	\
macro_End
#define bag_PushBack	bag_PushRear
#define bag_Push		bag_PushRear
#define bag_AddToRear	bag_PushRear
#define bag_AddToBack	bag_PushRear
#define bag_Add			bag_PushRear


// Pop / RemoveFrom
#define bag_PopFront(bg)	\
((bg).Count--)
#define bag_Pop				bag_PopFront
#define bag_RemoveFromFront	bag_PopFront

#define bag_PopRear(bg)	\
macro_Begin	\
(bg).Count--;	\
(bg).Rear = bag_Limit(bg, (bg).Rear - 1);	\
macro_End
#define bag_PopBack			bag_PopRear
#define bag_RemoveFromRear	bag_PopRear
#define bag_RemoveFromBack	bag_PopRear


// IndexOf / Find
#define bag_IndexOf(bg, item)	\
macro_Begin	\
uword i = bag_Count(bg);	\
uword indx = bag_Rear(bg);	\
for(; i > 0; indx=bag_Limit(bg, indx-1), i--)	\
if((bg).Item[indx] == (item)) break;	\
indx = (i > 0)? indx : (uword) -1;	\
macro_Return(indx);	\
macro_End
#define bag_Find	bag_IndexOf


// InsertAt / Insert / PushMid





// Remove
#define bag_Remove(bg, elem)	\
macro_Begin	\
uword indx = bag_IndexOf(bg, elem);	\
if(indx < (bg).Count) bag_RemoveAt(bg, indx);	\
macro_Return(indx);	\
macro_End


#endif /* _DATA_LIST_H_ */