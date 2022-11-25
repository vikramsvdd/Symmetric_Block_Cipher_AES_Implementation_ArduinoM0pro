#ifndef AESLib_h
#define AESLib_h

/* 10/11/22, code modified by Vikram Vasudevan <vv50517@gmail.com> */
/* **NOTE: This code is part of the standard AES Library. This code has been modified in the following aspects
1. References to pgmspace has been removed as it is unnecessary for Arduino M0 pro (32-bit cortex ARM-M0+) or any ARM based environment
2. References to program memory or flash has been removed and thus SRAM is the only memory being used, this has been done due to the intrinsic advantage that Arduino M0 pro has : 32kb RAM which is huge by AVR standards, this library has been originally designed for AVR systems and thus we modified these aspects and tried to use the resources offered by arduino M0 pro to the fullest.
Also, it is important to note that the Encryption and Decryption function implementation is un-altered, thus it is absolutely safe to use this library and it can be called the official version due to the core functionality being un-changed, though technically the library has been modified to better utilize the resources offered by Arduino M0 pro** */
#define __STDC_WANT_LIB_EXT1__ 1

#include "AES.h"
#include "xbase64.h"

#ifndef __AVR__
#include <iomanip> // provides std::setfill and setw:: (only for intToHex debugging)
#include <sstream>
#include <cstdint>
#include <iostream>
#include <string>
#endif

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef __x86_64
#include "Arduino.h"
#undef max
#undef min
#define debug(format, ...) if (Serial) Serial.printf ( format, __VA_ARGS__)

#define dumpHex(arr, count) if (Serial) { for(int kkk =0;kkk< count;kkk++) \
                                      Serial.printf ("%x " ,arr[kkk]); \
                                      Serial.printf ("\n"); \
                          }

#define dump(arr, count) if (Serial) { for(int kkk =0;kkk< count;kkk++) \
                                      Serial.printf ("%s," ,arr[kkk]); \
                                      Serial.printf ("\n"); \
                          }
//#define AES_DEBUG
#endif

class AESLib
{
  public:

    void gen_iv(byte  *iv);

    int get_cipher_length(int msg_len);
    int get_cipher64_length(int msg_len);

    void set_paddingmode(paddingMode mode);
    paddingMode get_paddingmode();

    uint16_t encrypt64(char * input, uint16_t input_length, char * output, byte key[],int bits, byte my_iv[]); // base64 encode, encrypt and base64 encode again; will deprecate
    uint16_t encrypt(byte input[], uint16_t input_length, char * output, byte key[],int bits, byte my_iv[]); // base64 encode and encrypt; should encode on output only (if)

    uint16_t decrypt64(char * input, uint16_t input_length, char * output, byte key[],int bits, byte my_iv[]); // decode, decrypt and decode
    uint16_t decrypt(byte input[], uint16_t input_length, char * output, byte key[], int bits, byte my_iv[]); // decrypts and decodes (expects encoded)

#ifndef __AVR__
    std::string intToHex(uint8_t intValue);
#endif

#ifndef __x86_64
    String decrypt(String msg, byte key[],int bits, byte my_iv[]) __attribute__((deprecated)); // decode, decrypt, decode and return as String
    String encrypt(String msg, byte key[], int bits, byte my_iv[]) __attribute__((deprecated)); // encode, encrypt, encode and return as String
#endif

    uint8_t getrnd();

  private:
    void clean();
    AES aes;
};

#endif // AESLib_h
