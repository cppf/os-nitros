#ifndef _MEM_BLOCK_H_
#define _MEM_BLOCK_H_


// Functions
#define mem_Compare		memcmp
#define mem_Copy		memcpy


// Set memory
void mem_SetF(byte* dst, uint size, byte val);
void mem_SetF(byte* dst, uint size, byte val)
{
	while(size)
	{
		*dst = val;
		dst++;
		size--;
	}
}
#define mem_Set(dst, size, val)	\
mem_SetF((byte*)(dst), size, val)


// Initialize
#define	mem_Init(dst, size)	\
mem_Set(dst, size, 0)


#endif /* _MEM_BLOCK_H_ */