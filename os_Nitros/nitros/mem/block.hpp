#ifndef _MEM_BLOCK_HPP_
#define _MEM_BLOCK_HPP_


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


#endif /* _MEM_BLOCK_HPP_ */