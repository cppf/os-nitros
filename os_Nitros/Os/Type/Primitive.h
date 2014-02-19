#ifndef	_TYPE_PRIMITIVE_H_
#define	_TYPE_PRIMITIVE_H_


// Size-Specified Integers
typedef	signed char			int8;
typedef	unsigned char		uint8;
typedef	short				int16;
typedef	unsigned short		uint16;
typedef	long				int32;
typedef	unsigned long		uint32;
typedef	long long			int64;
typedef	unsigned long long	uint64;


// CPU Word Size Integer
#if cpu_word_size == 8
#if platform_name != platform_arduino
typedef	int8	word;
#endif
typedef uint8	uword;
#elif cpu_word_size == 16
typedef	int16	word;
typedef uint16	uword;
#elif cpu_word_size == 64
typedef	int32	word;
typedef uint32	uword;
#elif cpu_word_size == 64
typedef	int64	word;
typedef uint64	uword;
#endif


// Named Types
#ifndef byte
typedef	unsigned char	byte;
#endif
typedef	unsigned char	ubyte;
typedef signed char		sbyte;
typedef unsigned short	ushort;
typedef unsigned int	uint;
typedef unsigned long	ulong;


#endif /* _TYPE_PRIMITIVE_H_ */