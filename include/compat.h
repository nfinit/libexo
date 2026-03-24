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

/* UNSIGNED INTEGERS */

#ifndef uint8_p
 #ifdef UINT8_MAX 
  #define uint8_p uint8_t
 #else
  #define uint8_p unsigned char
 #endif
#endif

#ifndef uint16_p
 #ifdef UINT16_MAX 
  #define uint16_p uint16_t
 #else
  #define uint16_p unsigned short
 #endif
#endif

#ifndef uint32_p
 #ifdef UINT32_MAX 
  #define uint32_p uint32_t
 #else
  #define uint32_p unsigned long
 #endif
#endif

#ifndef uint64_p
 #ifdef UINT64_MAX 
  #define uint64_p uint64_t
 #else
  #define uint64_p unsigned long long 
 #endif
#endif

/* SIGNED INTEGERS */

#ifndef int8_p
 #ifdef INT8_MAX 
  #define int8_p int8_t
 #else
  #define int8_p char
 #endif
#endif

#ifndef int16_p
 #ifdef INT16_MAX 
  #define int16_p int16_t
 #else
  #define int16_p short
 #endif
#endif

#ifndef int32_p
 #ifdef INT32_MAX 
  #define int32_p int32_t
 #else
  #define int32_p long
 #endif
#endif

#ifndef int64_p
 #ifdef INT64_MAX 
  #define int64_p int64_t
 #else
  #define int64_p long long 
 #endif
#endif

/* POINTER-SIZED INTEGERS */

#ifndef intptr_p
 #ifdef INTPTR_MAX 
  #define intptr_p intptr_t
 #endif
#endif

#ifndef uintptr_p
 #ifdef UINTPTR_MAX 
  #define uintptr_p uintptr_t
 #endif
#endif

/* MAXIMUM-WIDTH INTEGERS */

#ifndef intmax_p
 #ifdef INTMAX_MAX 
  #define intmax_p intmax_t
 #endif
#endif

#ifndef uintmax_p
 #ifdef UINTMAX_MAX 
  #define uintmax_p uintmax_t
 #endif
#endif

#endif
