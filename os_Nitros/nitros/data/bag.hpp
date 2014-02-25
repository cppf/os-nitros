#ifndef _DATA_BAG_HPP_
#define _DATA_BAG_HPP_


// Define
template <typename T, uword size>
class bag
{
	public:
	uword	Count;
	uword	Front;
	T		Item[size];
	
	public:
	inline uword Size()
	{
		return size;
	}
	
	inline uword Rear()
	{
		return (Front + Count) & (size - 1);
	}
	
	inline uword Avail()
	{
		return Count;
	}
	
	inline uword Free()
	{
		return size - Count;
	}
	
	inline uword Index(uword pos)
	{
		return (Front + pos) & (size - 1);
	}
	
	inline uword Position(uword index)
	{
		return (index - Front) & (size - 1);
	}
	
	inline void Clear()
	{
		Count = Front = 0;
	}
	
	inline void PushFront(T item)
	{
		Count++;
		Front = (Front - 1) & (size - 1);
		Item[Front] = item;
	}
	
	inline void PushRear(T item)
	{
		Item[Rear()] = item;
		Count++;
	}
	
	inline void PopFront()
	{
		Front = (Front + 1) & (size - 1);
		Count--;
	}
	
	inline void PopRear()
	{
		Count--;
	}
	
	uword IndexOf()
	{
		return 0;
	}
};



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


#endif /* _DATA_BAG_HPP_ */