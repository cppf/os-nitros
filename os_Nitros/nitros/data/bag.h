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
#define bag_IndexRearPos(bg, pos)	bag_Limit(bg, (bg).Rear - (pos))
#define bag_IndexBackPos(bg, pos)	bag_Limit(bg, (bg).Rear - 1 - (pos))
#define bag_IndexFrontPos(bg, pos)	bag_Limit(bg, (bg).Rear - (bg).Count + (pos))
#define bag_Index					bag_IndexFrontPos
#define bag_RearPos(bg, indx)		bag_Limit(bg, (indx) - (bg).Rear)
#define bag_BackPos(bg, indx)		bag_Limit(bg, (indx) - (bg).Rear + 1)
#define bag_FrontPos(bg, indx)		bag_Limit(bg, (indx) - (bg).Rear + (bg).Count)
#define bag_Pos						bag_FrontPos
#define bag_RearPtr(bg)				((bg).Item + bag_Rear(bg))
#define bag_BackPtr(bg)				((bg).Item + bag_Back(bg))
#define bag_FrontPtr(bg)			((bg).Item + bag_Front(bg))
#define bag_MidPtrRearPos(bg, pos)	((bg).Item + bag_IndexRearPos(bg, pos))
#define bag_MidPtrBackPos(bg, pos)	((bg).Item + bag_IndexBackPos(bg, pos))
#define bag_MidPtrFrontPos(bg, pos)	((bg).Item + bag_IndexFrontPos(bg, pos))
#define bag_MidPtr					bag_MidPtrFrontPos


// Peek
#define bag_PeekRear(bg)				(*bag_RearPtr(bg))
#define bag_PeekBack(bg)				(*bag_BackPtr(bg))
#define bag_PeekFront(bg)				(*bag_FrontPtr(bg))
#define bag_PeekMidRearPos(bg, pos)		(*bag_MidPtrRearPos(bg, pos))
#define bag_PeekMidBackPos(bg, pos)		(*bag_MidPtrBackPos(bg, pos))
#define bag_PeekMidFrontPos(bg, pos)	(*bag_MidPtrFrontPos(bg, pos))
#define bag_PeekMid						bag_PeekMidFrontPos
#define bag_Peek						bag_PeekMidFrontPos


// Clear / Init / RemoveAll
#define	bag_Clear(bg)		((bg).Rear = (bg).Count = 0)
#define bag_RemoveAll		bag_Clear
#define	bag_Init			bag_Clear


// Push / AddTo / Add
#define bag_PushFront(bg, item)	\
macro_Begin	\
(bg).Count++;	\
*bag_FrontPtr(bg) = (item);	\
macro_End
#define bag_AddToFront	bag_PushFront

#define bag_PushRear(bg, item)	\
macro_Begin	\
(bg).Count++;	\
*bag_RearPtr(bg) = (item);	\
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
uword indx = bag_Back(bg);	\
for(; i > 0; indx=bag_Limit(bg, indx-1), i--)	\
if((bg).Item[indx] == (item)) break;	\
indx = (i > 0)? indx : (uword) -1;	\
macro_Return(indx);	\
macro_End
#define bag_Find					bag_IndexOf


// InsertAt / Insert / PushMid
#define bag_InsertAt(bg, indx, item)	\
macro_Begin	\
bag_Push(bg, (bg).Item[indx]);	\
(bg).Item[indx] = (item);	\
macro_End
#define bag_Insert		bag_InsertAt
#define bag_PushMid		bag_InsertAt


// DeleteAt / Delete / RemoveAt / PopMid
#define bag_DeleteAt(bg, indx)	\
macro_Begin	\
(bg).Item[indx] = bag_PeekFront(bg);	\
bag_PopFront(bg);	\
macro_End
#define bag_Delete		bag_DeleteAt
#define bag_RemoveAt	bag_DeleteAt
#define bag_PopMid		bag_DeleteAt


// InsertAtOrder / InsertOrder / PushMidOrder
#define bag_InsertAtOrder(bg, indx, item)	\
macro_Begin	\
(bg).Count++;	\
if(bag_Back(bg) < (indx))	\
mem_Move((bg).Item, (bg).Item+1, (bg).Rear*bag_ItemSize(bg));	\
if(bag_Rear(bg) < (indx))	\
(bg).Item[0] = (bg).Item[bag_Size(bg) - 1];	\
if((indx) < bag_Size(bg)-1)	\
mem_Move((bg).Item+(indx), (bg).Item+(indx)+1, bag_Size(bg)-(indx)-1);	\
(bg).Item[indx] = (item);	\
(bg).Rear = bag_Limit(bg, (bg).Rear + 1);	\
macro_End
#define bag_InsertOrder		bag_InsertAtOrder
#define bag_PushMidOrder	bag_InsertAtOrder


// DeleteAtOrder / DeleteOrder / RemoveAtOrder / PopMidOrder
#define bag_DeleteAtOrder(bg, indx)	\
macro_Begin	\
(bg).Count--;	\
if((indx) < bag_Size(bg)-1)	\
mem_Move((bg).Item+(indx), (bg).Item+(indx)+1, bag_Size(bg)-(indx)-1);	\
if(bag_Back(bg) < (indx))	\
(bg).Item[bag_Size(bg) - 1] = (bg).Item[0];	\
if((bag_Back(bg) < (indx)) && (bag_Back(bg) > 0))	\
mem_Move((bg).Item, (bg).Item+1, bag_Back(bg) * bag_ItemSize(bg));	\
(bg).Rear = bag_Limit(bg, (bg).Rear - 1);	\
macro_End
#define bag_DeleteOrder		bag_DeleteAtOrder
#define bag_RemoveAtOrder	bag_DeleteAtOrder
#define bag_PopMidOrder		bag_DeleteAtOrder


// Remove
#define bag_Remove(bg, item)	\
macro_Begin	\
uword indx = bag_IndexOf(bg, item);	\
if(indx < (bg).Count) bag_RemoveAt(bg, indx);	\
macro_End


// RemoveOrder
#define bag_RemoveOrder(bg, item)	\
macro_Begin	\
uword indx = bag_IndexOf(bg, item);	\
if(indx < (bg).Count) bag_RemoveAtOrder(bg, indx);	\
macro_End


#endif /* _DATA_BAG_H_ */