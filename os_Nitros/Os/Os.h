#ifndef _RTOS_H_
#define _RTOS_H_


// Build Support
#include "Build/Macro.h"
#include "Build/Merge.h"
#include "Build/Function.h"
#include "Build/Constants.h"
#include "Build/Attribute.h"


// Compilation Options
#define platform_Name		platform_Name_AVR
#define compiler_Name		compiler_Name_GCC
#define cpu_WordSize		8
#define cpu_ClockFreq		16000000


// Sizes of RAM, Flash
#define ram_Size	(RAMEND + 1)
#define flash_Size	(FLASHEND + 1)


// Platform Files
#if platform_Name == platform_Name_AVR
#include <avr/io.h>
#include <avr/portpins.h>
#include <avr/interrupt.h>
#endif


// Include Files
#include "Type/Constants.h"
#include "Type/Primitive.h"
#include "Type/Character.h"
#include "Type/Ranges.h"
#include "Type/Buffer.h"
#include "Type/String.h"
#include "Math/Concat.h"
#include "Math/Basic.h"
#include "Math/Bit.h"
#include "Mem/Basic.h"
#include "Mem/Block.h"
#include "Mem/Register.h"
#include "Data/Bag.h"
#include "Data/List.h"
#include "Data/Queue.h"
#include "Core/Sem.h"
#include "Core/Task.h"
#include "Core/Kernel.h"


#endif /* _RTOS_H_ */