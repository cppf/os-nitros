#ifndef _RTOS_H_
#define _RTOS_H_


// Build Support
#include "build/macro.h"
#include "build/merge.h"
#include "build/constant.h"


// Compilation Options
#define platform_name		platform_avr
#define compiler_name		compiler_gcc
#define cpu_word_size		8
#define cpu_clock_freq		16000000


// Sizes of RAM, Flash
#define ram_size	(RAMEND + 1)
#define flash_size	(FLASHEND + 1)


// Platform Files
#if platform_name == platform_avr
#include <avr/io.h>
#include <avr/portpins.h>
#include <avr/interrupt.h>
#endif


// Include Files
#include "build/function.h"
#include "build/attribute.h"
#include "type/constant.h"
#include "type/primitive.h"
#include "type/char.h"
#include "type/range.h"
#include "type/buffer.h"
#include "type/string.h"
#include "math/concat.h"
#include "math/basic.h"
#include "math/bit.h"
#include "mem/basic.h"
#include "mem/block.h"
#include "mem/reg.h"
#include "data/bag.h"
#include "data/list.h"
#include "data/queue.h"
#include "core/sem.h"
#include "core/task.h"
#include "core/kernel.h"


#endif /* _RTOS_H_ */