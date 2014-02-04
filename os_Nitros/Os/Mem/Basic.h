#ifndef _MEM_BASIC_H_
#define _MEM_BASIC_H_


#define mem(base, addr)	\
(((char*)(base)) + (off))

inline byte mem_ReadBit(void* src, uint off, uint bit_no);
inline byte mem_ReadBit(void* src, uint off, uint bit_no)
{
	byte* addr = (byte*)src + off + (bit_no >> 3);
	return (*addr >> (bit_no & 7)) & 1;
}

inline byte mem_ReadNibble(void* src, uint off, uint nibl_no);
inline byte mem_ReadNibble(void* src, uint off, uint nibl_no)
{
	byte* addr = (byte*)src + off + (nibl_no >> 1);
	byte val = (nibl_no & 1)? *addr >> 4 : *addr;
	return val & 0xFF;
}

#define	mem_ReadType(type, src, off)	\
(*((type*)(((byte*)(src)) + (off))))

#define	mem_ReadInt8(src, off)	\
mem_ReadType(int8, src, off)

#define	mem_ReadUint8(src, off)	\
mem_ReadType(uint8, src, off)

#define	mem_ReadInt16(src, off)	\
mem_ReadType(int16, src, off)

#define	mem_ReadUint16(src, off)	\
mem_ReadType(uint16, src, off)

#define	mem_ReadInt32(src, off)	\
mem_ReadType(int32, src, off)

#define	mem_ReadUint32(src, off)	\
mem_ReadType(uint32, src, off)

#define	mem_ReadInt64(src, off)	\
mem_ReadType(int64, src, off)

#define	mem_ReadUint64(src, off)	\
mem_ReadType(uint64, src, off)

#define	mem_ReadInt(src, off)	\
mem_ReadType(int, src, off)

#define	mem_ReadUint(src, off)	\
mem_ReadType(uint, src, off)

#define	mem_ReadWord(src, off)	\
mem_ReadType(word, src, off)

#define	mem_ReadUword(src, off)	\
mem_ReadType(uword, src, off)

#define mem_ReadChar(src, off)	\
mem_ReadType(char, src, off)

#define mem_ReadByte(src, off)	\
mem_ReadType(byte, src, off)

#define mem_ReadUbyte(src, off)	\
mem_ReadType(ubyte, src, off)

#define mem_ReadSbyte(src, off)	\
mem_ReadType(sbyte, src, off)

#define mem_ReadBoolean(src, off)	\
(mem_ReadByte(src, off) != 0)

#define	mem_ReadBool(src, off)	\
mem_ReadBoolean(src, off)

#define	mem_ReadShort(src, off)	\
mem_ReadType(short, src, off)

#define	mem_ReadUshort(src, off)	\
mem_ReadType(ushort, src, off)

#define	mem_ReadLong(src, off)	\
mem_ReadType(long, src, off)

#define	mem_ReadUlong(src, off)	\
mem_ReadType(ulong, src, off)

#define	mem_ReadFloat(src, off)	\
mem_ReadType(float, src, off)

#define	mem_ReadDouble(src, off)	\
mem_ReadType(double, src, off)

inline void mem_WriteBit(void* dst, uint off, uint bit_no, uword bit_val);
inline void mem_WriteBit(void* dst, uint off, uint bit_no, uword bit_val)
{
	byte* addr = (byte*)dst + off + (bit_no >> (uword)3);
	byte flg = (uword)1 << (bit_no & (uword)7);
	*addr = (bit_val)? *addr | flg : *addr & (~flg);
}

inline void mem_WriteNibble(void* dst, uint off, uint nibl_no, byte nibl_val);
inline void mem_WriteNibble(void* dst, uint off, uint nibl_no, byte nibl_val)
{
	byte* addr = (byte*)dst + off + (nibl_no >> (uword)1);
	*addr = (nibl_no & (uword)1)? (*addr & (uword)0x0F) | (nibl_val << (uword)4) : (*addr & (uword)0xF0) | nibl_val;
}

#define	mem_WriteType(type, dst, off, val)	\
(*((type*)(((byte*)(dst)) + (off))) = (val))

#define	mem_WriteInt8(dst, off, val)	\
mem_WriteType(int8, dst, off, val)

#define	mem_WriteUint8(dst, off, val)	\
mem_WriteType(uint8, dst, off, val)

#define	mem_WriteInt16(dst, off, val)	\
mem_WriteType(int16, dst, off, val)

#define	mem_WriteUint16(dst, off, val)	\
mem_WriteType(uint16, dst, off, val)

#define	mem_WriteInt32(dst, off, val)	\
mem_WriteType(int32, dst, off, val)

#define	mem_WriteUint32(dst, off, val)	\
mem_WriteType(uint32, dst, off, val)

#define	mem_WriteInt64(dst, off, val)	\
mem_WriteType(int64, dst, off, val)

#define	mem_WriteUint64(dst, off, val)	\
mem_WriteType(uint64, dst, off, val)

#define	mem_WriteInt(dst, off, val)	\
mem_WriteType(int, dst, off, val)

#define	mem_WriteUint(dst, off, val)	\
mem_WriteType(uint, dst, off, val)

#define	mem_WriteInteger(dst, off, val)	\
mem_WriteType(integer, dst, off, val)

#define	mem_WriteUinteger(dst, off, val)	\
mem_WriteType(uinteger, dst, off, val)

#define mem_WriteChar(dst, off, val)	\
mem_WriteType(char, dst, off, val)

#define mem_WriteByte(dst, off, val)	\
mem_WriteType(byte, dst, off, val)

#define mem_WriteUbyte(dst, off, val)	\
mem_WriteType(ubyte, dst, off, val)

#define mem_WriteSbyte(dst, off, val)	\
mem_WriteType(sbyte, dst, off, val)

#define mem_WriteBoolean(dst, off, val)	\
mem_WriteByte(dst, off, ((val) != (uword)0))

#define	mem_WriteBool(dst, off, val)	\
mem_WriteBoolean(dst, off, val)

#define	mem_WriteShort(dst, off, val)	\
mem_WriteType(short, dst, off, val)

#define	mem_WriteUshort(dst, off, val)	\
mem_WriteType(ushort, dst, off, val)

#define	mem_WriteLong(dst, off, val)	\
mem_WriteType(long, dst, off, val)

#define	mem_WriteUlong(dst, off, val)	\
mem_WriteType(ulong, dst, off, val)

#define	mem_WriteFloat(dst, off, val)	\
mem_WriteType(float, dst, off, val)

#define	mem_WriteDouble(dst, off, val)	\
mem_WriteType(double, dst, off, val)


// Swap
#define	mem_Swap3(a, b, temp)	\
macro_Begin		\
temp = a;	\
a = b;		\
b = temp;	\
macro_End

#define	mem_Swap2(a, b)	\
macro_Begin	\
a ^= b;	\
b ^= a;	\
a ^= b;	\
macro_End

#define	mem_Swap(...)	\
macro_Fn(macro_Fn3(__VA_ARGS__, mem_Swap3, mem_Swap2)(__VA_ARGS__))


#endif /* _MEM_BASIC_H_ */