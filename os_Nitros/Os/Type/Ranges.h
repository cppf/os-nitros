#ifndef _TYPE_RANGES_H_
#define _TYPE_RANGES_H_


// Size-Specified Integers
#define int8_Min	(-0x80)
#define int8_Max	(0x7F)
#define int16_Min	(-0x8000)
#define int16_Max	(0x7FFF)
#define int32_Min	(-0x80000000L)
#define int32_Max	(0x7FFFFFFFL)
#define int64_Min	(-0x8000000000000000LL)
#define int64_Max	(0x7FFFFFFFFFFFFFFFLL)
#define uint8_Min	(0U)
#define uint8_Max	(0xFFU)
#define uint16_Min	(0U)
#define uint16_Max	(0xFFFFU)
#define uint32_Min	(0UL)
#define uint32_Max	(0xFFFFFFFFUL)
#define uint64_Min	(0ULL)
#define uint64_Max	(0xFFFFFFFFFFFFFFFFULL)


// CPU Word Size Integer
#if cpu_WordSize == 8
#define	int_Min		int16_Min
#define	int_Max		int16_Max
#define	uint_Min	uint16_Min
#define	uint_Max	uint16_Max
#define	word_Min	int8_Min
#define	word_Max	int8_Max
#define	uword_Min	uint8_Min
#define	uword_Max	uint8_Max
#elif cpu_WordSize == 16
#define	int_Min		int16_Min
#define	int_Max		int16_Max
#define	uint_Min	uint16_Min
#define	uint_Max	uint16_Max
#define	word_Min	int16_Min
#define	word_Max	int16_Max
#define	uword_Min	uint16_Min
#define	uword_Max	uint16_Max
#elif cpu_WordSize == 32
#define	int_Min		int32_Min
#define	int_Max		int32_Max
#define	uint_Min	uint32_Min
#define	uint_Max	uint32_Max
#define	word_Min	int32_Min
#define	word_Max	int32_Max
#define	uword_Min	uint32_Min
#define	uword_Max	uint32_Max
#elif cpu_WordSize == 64
#define	int_Min		int64_Min
#define	int_Max		int64_Max
#define	uint_Min	uint64_Min
#define	uint_Max	uint64_Max
#define	word_Min	int64_Min
#define	word_Max	int64_Max
#define	uword_Min	uint64_Min
#define	uword_Max	uint64_Max
#endif


// Named Types
#define char_Min	('\0')
#define char_Max	('\xFF')
#define byte_Min	uint8_Min
#define byte_Max	uint8_Max
#define ubyte_Min	uint8_Min
#define ubyte_Max	uint8_Max
#define sbyte_Min	int8_Min
#define sbyte_Max	int8_Max
#define short_Min	int16_Min
#define short_Max	int16_Max
#define ushort_Min	uint16_Min
#define ushort_Max	uint16_Max
#define long_Min	int32_Min
#define long_Max	int32_Max
#define	ulong_Min	uint32_Min
#define ulong_Max	uint32_Max


#endif /* RANGES_H_ */