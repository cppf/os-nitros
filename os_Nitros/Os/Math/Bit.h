#ifndef _MATH_BIT_H_
#define _MATH_BIT_H_


// ValueByOnes
#define	bit_ValueByOnes1(b1)	\
(1 << (b1))

#define	bit_ValueByOnes2(b1, b2)	\
((1 << (b1)) | (1 << (b2)))

#define	bit_ValueByOnes3(b1, b2, b3)	\
((1 << (b1)) | (1 << (b2)) | (1 << (b3)))

#define	bit_ValueByOnes4(b1, b2, b3, b4)	\
((1 << (b1)) | (1 << (b2)) | (1 << (b3)) | (1 << (b4)))

#define	bit_ValueByOnes5(b1, b2, b3, b4, b5)	\
((1 << (b1)) | (1 << (b2)) | (1 << (b3)) | (1 << (b4)) | (1 << (b5)))

#define	bit_ValueByOnes6(b1, b2, b3, b4, b5, b6)	\
((1 << (b1)) | (1 << (b2)) | (1 << (b3)) | (1 << (b4)) | (1 << (b5)) | (1 << (b6)))

#define	bit_ValueByOnes7(b1, b2, b3, b4, b5, b6, b7)	\
((1 << (b1)) | (1 << (b2)) | (1 << (b3)) | (1 << (b4)) | (1 << (b5)) | (1 << (b6)) | (1 << (b7)))

#define	bit_ValueByOnes8(b1, b2, b3, b4, b5, b6, b7, b8)	\
((1 << (b1)) | (1 << (b2)) | (1 << (b3)) | (1 << (b4)) | (1 << (b5)) | (1 << (b6)) | (1 << (b7)) | (1 << (b8)))

#define	bit_ValueByOnes(...)	\
macro_Fn(macro_Fn8(__VA_ARGS__, bit_ValueByOnes8, bit_ValueByOnes7, bit_ValueByOnes6, bit_ValueByOnes5, bit_ValueByOnes4, bit_ValueByOnes3, bit_ValueByOnes2, bit_ValueByOnes1)(__VA_ARGS__))


// Read
#define	bit_Read(src, bit_no)	\
(((src) >> (bit_no)) & 1)

#define bit_Get	\
bit_Read


// Test
#define bit_Test(src, ...)	\
((src) & bit_ValueByOnes(__VA_ARGS__))


// Set
#define bit_Set(dst, ...)	\
((dst) |= bit_ValueByOnes(__VA_ARGS__))


// Clear
#define bit_Clear(dst, ...)	\
((dst) &= ~bit_ValueByOnes(__VA_ARGS__))


// Write
#define	bit_Write(dst, bit_no, bit_value)	\
((dst) = ((dst) & ~(1 << (bit_no))) | ((bit_value) << (bit_no)))

#define bit_Put	\
bit_Write


#endif /* _MATH_BIT_H_ */