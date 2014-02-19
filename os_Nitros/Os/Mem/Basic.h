#ifndef _MEM_BASIC_H_
#define _MEM_BASIC_H_


#define mem(base, off)	\
(((char*)(base)) + (off))


// Swap
#define	swap3(a, b, temp)	\
macro_Begin		\
temp = a;	\
a = b;		\
b = temp;	\
macro_End

#define	swap2(a, b)	\
macro_Begin	\
a ^= b;	\
b ^= a;	\
a ^= b;	\
macro_End

#define	swap(...)	\
macro_Fn(macro_Fn3(__VA_ARGS__, mem_Swap3, mem_Swap2)(__VA_ARGS__))


#endif /* _MEM_BASIC_H_ */