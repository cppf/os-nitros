#ifndef _MEM_BLOCK_H_
#define _MEM_BLOCK_H_


// Initialize memory
void mem_InitVF(byte* dst, uint size, byte val);
void mem_InitVF(byte* dst, uint size, byte val)
{
	while(size)
	{
		*dst = val;
		dst++;
		size--;
	}
}
#define mem_InitV(dst, size, val)	\
mem_InitVF((byte*)(dst), size, val)

#define	mem_InitZ(dst, size)	\
mem_InitV(dst, size, 0)

#define	mem_Init(...)	\
macro_Fn(macro_Fn4(__VA_ARGS__, mem_InitV, mem_InitZ)(__VA_ARGS__))


// Compare
byte mem_CompareF(byte* src1, byte* src2, uint size);
byte mem_CompareF(byte* src1, byte* src2, uint size)
{
	byte diff;
	while(size)
	{
		diff = *src1 - *src2;
		if(diff) return diff;
		src1++;
		src2++;
		size--;
	}
	return 0;
}

#define	mem_Compare(src1, src2, size)	\
mem_CompareF((byte*)(src1), (byte*)(src2), size)


// Copy
void mem_CopyF(byte* dst, byte* src, uint size);
void mem_CopyF(byte* dst, byte* src, uint size)
{
	if(dst < src)
	{
		while(size)
		{
			*dst = *src;
			dst++;
			src++;
			size--;
		}
	}
	else
	{
		dst += size - 1;
		src += size - 1;
		while(size)
		{
			*dst = *src;
			dst--;
			src--;
			size--;
		}
	}
}

#define	mem_Copy(dst, src, size)	\
mem_CopyF(((byte*)(dst)), ((byte*)(src)), (size))


// Reverse
void mem_ReverseF(byte* src, uint size);
void mem_ReverseF(byte* src, uint size)
{
	byte byt, *end;
	for(end=src+size-1; src<end; src++, end--)
	{
		byt = *src;
		*src = *end;
		*end = byt;
	}
}

#define	mem_Reverse(src, size)	\
mem_ReverseF((byte*)(src), (size))


#endif /* _MEM_BLOCK_H_ */