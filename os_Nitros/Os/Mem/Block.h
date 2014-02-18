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


uword mem_IndexOfF(void* block, uint block_no, void* data, uint data_sz);
uword mem_IndexOfF(void* block, uint block_no, void* data, uint data_sz)
{
	return 0;
}

#define mem_IndexOf(block, block_no, data, data_sz)	\
mem_IndexOfF((void*)(block), (uint)(block_no), (void*)(data), (uint)(data_sz))

#define mem_Find	\
mem_IndexOf


#endif /* _MEM_BLOCK_H_ */