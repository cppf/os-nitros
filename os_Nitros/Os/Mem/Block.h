#ifndef _MEM_BLOCK_H_
#define _MEM_BLOCK_H_


// Functions
#define mem_Set			memset
#define mem_Compare		memcmp
#define mem_Copy		memcpy
#define mem_Move		memmove
#define mem_IndexOfChar	memchr
#define mem_FindChar	memchr


// Checks equality
#define	mem_Equals(mem1, mem2, size)	\
(!mem_Compare(mem1, mem2, size))


// Initialize
#define	mem_Init(dst, size)	\
mem_Set(dst, size, 0)


noInline uword mem_IndexOfF(byte* block, uword block_no, byte* data, uint data_sz);
uword mem_IndexOfF(byte* block, uword block_no, byte* data, uint data_sz)
{
	for(uword i=0; i < block_no; block+=data_sz, i++)
		if(mem_Compare(block, data, data_sz) == 0) return i;
	return (uword) -1;
}

#define mem_IndexOf(block, block_no, data, data_sz)	\
mem_IndexOfF((byte*)(block), (uword)(block_no), (byte*)(data), (uint)(data_sz))

#define mem_Find	\
mem_IndexOf


#endif /* _MEM_BLOCK_H_ */