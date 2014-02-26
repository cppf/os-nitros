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
		T item = Item[Front];
		Front = (Front + 1) & (size - 1);
		Count--;
		return item;
	}
	
	inline void PopRear()
	{
		Count--;
		return Item[Rear()];
	}
	
	uword IndexOf(T item)
	{
		uword count = Count;
		uword index = Front;
		for(; count > 0; count--)
		{
			if(Item[index] == item) return index;
			index = (index + 1) & (size - 1);
		}
		return (uword) -1;
	}
	
	inline void InsertAt(uword index, T item)
	{
		PushFront(Item[index]);
		Item[index] = item;
	}
	
	inline void RemoveAt(uword index)
	{
		Item[index] = Item[Front];
		PopFront();
	}
	
	inline void Remove(T item)
	{
		uword index = IndexOf(item);
		if(index != (uword) -1) RemoveAt(index);
	}
};


#endif /* _DATA_QUEUE_HPP_ */