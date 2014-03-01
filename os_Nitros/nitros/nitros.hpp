#ifndef _NITROS_HPP_
#define _NITROS_HPP_


// Build Support
#include "make/macro.hpp"
#include "make/merge.hpp"
#include "make/constant.hpp"


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
#include "make/function.hpp"
#include "make/attribute.hpp"
#include "type/constant.hpp"
#include "type/primitive.hpp"
#include "type/char.hpp"
#include "type/range.hpp"
#include "type/string.hpp"
#include "math/concat.hpp"
#include "math/basic.hpp"
#include "math/bit.hpp"
#include "math/hash.hpp"
#include "mem/basic.hpp"
#include "mem/block.hpp"
#include "mem/reg.hpp"
#include "data/buffer.hpp"
#include "data/list.hpp"
#include "data/queue.hpp"
// #include "core/context.hpp"
// #include "core/task.hpp"
/*
#include "core/sem.h"
#include "core/kernel.h"
*/

#endif /* _NITROS_HPP_ */