#ifndef _DATA_LIST_HPP_
#define _DATA_LIST_HPP_


namespace data
{

template <typename T, uword size>
class list
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
		for(uword i=0, n=Count; n>0; i++, n--)
			if(Item[i] == item) return i;
		return (uword) -1;
	}
	
	inline void InsertAt(uword index, T item)
	{
		Add(Item[index]);
		Item[index] = item;
	}
	
	inline void DeleteAt(uword index)
	{
		Item[index] = Item[Count];
		Count--;
	}
	
	void Remove(T item)
	{
		uword index = IndexOf(item);
		if(index != (uword) -1) DeleteAt(index);
	}
};

} // end (namespace) data


#endif /* _DATA_LIST_HPP_ */