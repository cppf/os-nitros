#ifndef	_TYPE_PRIMITIVE_HPP_
#define	_TYPE_PRIMITIVE_HPP_


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
#ifndef word
#if cpu_word_size == 8
typedef	int8	word;
#elif cpu_word_size == 16
typedef	int16	word;
#endif
#endif
#ifndef uword
#if cpu_word_size == 8
typedef	uint8	uword;
#elif cpu_word_size == 16
typedef	uint16	uword;
#endif
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


#endif /* _TYPE_PRIMITIVE_HPP_ */