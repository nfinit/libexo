#ifndef _EXO_COMPAT_H_
#define _EXO_COMPAT_H_

/* LIBEXO COMPATABILITY DEFINItIOS
 *
 * REVISION I (03/26) (C) NFINIT Systems 2026
 *
 * This file provides definitions for compatability with different CXX standards.
 * Currently different signed and unsigned integer types are defined.
 *
 */

#include <cerrno>
#include <functional>
#include <stdint.h>

/* UNSIGNED INTEGERS */

#ifndef uint8_p
 #define uint8_p uint8_t
#endif

#ifndef uint16_p
 #define uint16_p uint16_t
#endif

#ifndef uint32_p
 #define uint32_p uint32_t
#endif

#ifndef uint64_p
 #define uint64_p uint64_t
#endif

/* SIGNED INTEGERS */

#ifdef int8_p
 #define int8_p int8_t
#endif

#ifdef int16_p
 #define int16_p int16_t
#endif

#ifdef int32_p
 #define int32_p int32_t
#endif

#ifdef int64_p
 #define int64_p int64_t
#endif

/* POINTER-SIZED INTEGERS */

#ifdef intptr_p
 #define intptr_p intptr_t
#endif

#ifdef uintptr_p
 #define uintptr_p uintptr_t
#endif

/* MAXIMUM-WIDTH INTEGERS */

#ifdef intmax_p
 #define intmax_p intmax_t
#endif

#ifdef uintmax_p
 #define uintmax_p uintmax_p
#endif

/* FLOATS */

#ifdef float32_p
 #define float32_p float
#endif

#ifdef float64_p
 #define float64_p double 
#endif

#endif
