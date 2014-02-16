#ifndef _TYPE_RANGE_H_
#define _TYPE_RANGE_H_


// Size-Specified Integers
#define int8_min	(-0x80)
#define int8_max	(0x7F)
#define int16_min	(-0x8000)
#define int16_max	(0x7FFF)
#define int32_min	(-0x80000000L)
#define int32_max	(0x7FFFFFFFL)
#define int64_min	(-0x8000000000000000LL)
#define int64_max	(0x7FFFFFFFFFFFFFFFLL)
#define uint8_min	(0U)
#define uint8_max	(0xFFU)
#define uint16_min	(0U)
#define uint16_max	(0xFFFFU)
#define uint32_min	(0UL)
#define uint32_max	(0xFFFFFFFFUL)
#define uint64_min	(0ULL)
#define uint64_max	(0xFFFFFFFFFFFFFFFFULL)


// CPU Word Size Integer
#if cpu_word_size == 8
#define	int_min		int16_min
#define	int_max		int16_max
#define	uint_min	uint16_min
#define	uint_max	uint16_max
#define	word_min	int8_min
#define	word_max	int8_max
#define	uword_min	uint8_min
#define	uword_max	uint8_max
#elif cpu_word_size == 16
#define	int_min		int16_min
#define	int_max		int16_max
#define	uint_min	uint16_min
#define	uint_max	uint16_max
#define	word_min	int16_min
#define	word_max	int16_max
#define	uword_min	uint16_min
#define	uword_max	uint16_max
#elif cpu_word_size == 32
#define	int_min		int32_min
#define	int_max		int32_max
#define	uint_min	uint32_min
#define	uint_max	uint32_max
#define	word_min	int32_min
#define	word_max	int32_max
#define	uword_min	uint32_min
#define	uword_max	uint32_max
#elif cpu_word_size == 64
#define	int_min		int64_min
#define	int_max		int64_max
#define	uint_min	uint64_min
#define	uint_max	uint64_max
#define	word_min	int64_min
#define	word_max	int64_max
#define	uword_min	uint64_min
#define	uword_max	uint64_max
#endif


// Named Types
#define char_min	('\0')
#define char_max	('\xFF')
#define byte_min	uint8_min
#define byte_max	uint8_max
#define ubyte_min	uint8_min
#define ubyte_max	uint8_max
#define sbyte_min	int8_min
#define sbyte_max	int8_max
#define short_min	int16_min
#define short_max	int16_max
#define ushort_min	uint16_min
#define ushort_max	uint16_max
#define long_min	int32_min
#define long_max	int32_max
#define	ulong_min	uint32_min
#define ulong_max	uint32_max


#endif /* RANGE_H_ */