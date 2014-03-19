#ifndef _DATA_QUEUE_HPP_
#define _DATA_QUEUE_HPP_


template <typename T, uword size>
class queue
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
	
	inline uword Pos(uword index)
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
	
	inline T PopFront()
	{
		Count--;
		T item = Item[Front];
		Front = (Front + 1) & (size - 1);
		return item;
	}
	
	inline T PopRear()
	{
		Count--;
		return Item[Rear()];
	}
	
	uword IndexOf(T item)
	{
		for(uword i=Front, n=Count; n>0; n--)
		{
			if(Item[i] == item) return i;
			i = (i + 1) & (size - 1);
		}
		return (uword) -1;
	}
	
	inline void InsertAt(uword index, T item)
	{
		PushFront(Item[index]);
		Item[index] = item;
	}
	
	inline void DeleteAt(uword index)
	{
		Item[index] = Item[Front];
		PopFront();
	}
	
	void Remove(T item)
	{
		uword index = IndexOf(item);
		if(index != (uword) -1) DeleteAt(index);
	}
};


#endif /* _DATA_QUEUE_HPP_ */