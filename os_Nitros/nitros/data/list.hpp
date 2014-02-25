#ifndef _DATA_LIST_HPP_
#define _DATA_LIST_HPP_



template <typename T, uword size>
class list
{
	public:
	uword	Count;
	uword	Front;
	T		Item[size];
	
	inline uword Size()
	{
		return size;
	}
	
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
		Count = Front = 0;
	}
	
	inline void Add(T item)
	{
		Item[Count] = item;
		Count++;
	}
	
	uword IndexOf(T item)
	{
		uword index = 0;
		uword count = Count;
		for(; count > 0; count--)
		{
			if(Item[index] == item) return index;
			index++;
		}
		return (uword) -1;
	}
	
	inline void InsertAt(uword index, T item)
	{
		Add(Item[index]);
		Item[index] = item;
	}
	
	inline void RemoveAt(uword index)
	{
		Item[index] = Item[Count];
		Count--;
	}
	
	inline void Remove(T item)
	{
		uword index = IndexOf(item);
		if(index != (uword) -1) RemoveAt(index);
	}
};


#endif /* _DATA_LIST_HPP_ */