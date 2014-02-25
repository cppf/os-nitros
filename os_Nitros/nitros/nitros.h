#ifndef _NITROS_H_
#define _NITROS_H_


// Build Support
#include "make/macro.h"
#include "make/merge.h"
#include "make/constant.h"


// Compilation Options
#define platform_name		platform_avr
#define compiler_name		compiler_gcc
#define cpu_word_size		8
#define cpu_clock_freq		16000000


// Sizes of RAM, Flash
#define ram_size	(RAMEND + 1)
#define flash_size	(FLASHEND + 1)


// Platform Files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if platform_name == platform_avr || platform_name == platform_arduino
#include <avr/io.h>
#include <avr/portpins.h>
#include <avr/interrupt.h>
#endif
#if platform_name == platform_arduino
#include <Arduino.h>
#endif


// Include Files
#include "make/function.h"
#include "make/attribute.h"
#include "type/constant.h"
#include "type/primitive.h"
#include "type/char.h"
#include "type/range.h"
#include "type/buffer.h"
#include "type/string.h"
#include "math/concat.h"
#include "math/basic.h"
#include "math/bit.h"
#include "math/hash.h"
#include "mem/basic.h"
#include "mem/block.h"
#include "mem/reg.h"
#include "data/bag.h"
/*
#include "data/list.h"
#include "data/queue.h"
#include "core/sem.h"
#include "core/task.h"
#include "core/kernel.h"
*/

#endif /* _NITROS_H_ */