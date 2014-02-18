#ifndef _MAKE_FUNCTION_H_
#define _MAKE_FUNCTION_H_


// Macros: typeOf
#if compiler_name != compiler_gcc
	#define typeOf(expr)	\
	decltype(expr)
#else
	#define typeOf(expr)	\
	typeof(expr)
#endif


// Convert a token to string
#define toString(a)	\
#a


// Mark unused variables
#define notUsed(var)	\
(void)(var)


// Apply memory barrier (prevents reordering)
#ifndef barrier
	#define barrier()	\
	asm volatile("" ::: "memory")
#endif


// Assembly coding
#define assembly	\
__asm__ __volatile__

#define line(text)	\
text "\n\t"


#endif /* _MAKE_FUNCTION_H_ */