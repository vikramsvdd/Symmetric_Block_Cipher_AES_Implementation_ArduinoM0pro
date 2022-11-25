/* code was modified by george spanos <spaniakos@gmail.com>
 * 16/12/14
 */
/* 10/11/22, code modified by Vikram Vasudevan <vv50517@gmail.com> */
/* **NOTE: This code is part of the standard AES Library. This code has been modified in the following aspects
1. References to pgmspace has been removed as it is unnecessary for Arduino M0 pro (32-bit cortex ARM-M0+) or any ARM based environment
2. References to program memory or flash has been removed and thus SRAM is the only memory being used, this has been done due to the intrinsic advantage that Arduino M0 pro has : 32kb RAM which is huge by AVR standards, this library has been originally designed for AVR systems and thus we modified these aspects and tried to use the resources offered by arduino M0 pro to the fullest.
Also, it is important to note that the Encryption and Decryption function implementation is un-altered, thus it is absolutely safe to use this library and it can be called the official version due to the core functionality being un-changed, though technically the library has been modified to better utilize the resources offered by Arduino M0 pro** */
#ifndef __AES_CONFIG_H__
#define __AES_CONFIG_H__


#if defined(__x86_64) || (defined(__linux) || defined(linux)) && !defined(__ARDUINO_X86__)

  #define AES_LINUX

  #include <stdint.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <sys/time.h>
  #include <unistd.h>
#else
  #include <Arduino.h>
#endif

#include <stdint.h>
#include <string.h>

#if defined(__ARDUINO_X86__) || (defined (__linux) || defined (linux))
  #undef PROGMEM
  #define PROGMEM __attribute__(( section(".progmem.data") ))
  #define pgm_read_byte(p) (*(p))
  typedef unsigned char byte;
  #define printf_P printf
  #define PSTR(x) (x)
#else
  #if (defined(__AVR__))
    #include <avr/pgmspace.h>
  #else
  #if !defined(__x86_64)
    //#include <pgmspace.h> // probably ESP's PGMSPACE, needs to be mocked for testing
  #else
    // disable the PROGMEM definition in test environment
    #undef PROGMEM
    
  #endif
  #endif
#endif

#define N_ROW                   4
#define N_COL                   4
#define N_BLOCK   (N_ROW * N_COL)
#define N_MAX_ROUNDS           14
#define KEY_SCHEDULE_BYTES ((N_MAX_ROUNDS + 1) * N_BLOCK)
#define SUCCESS (0)
#define FAILURE (-1)

#endif
