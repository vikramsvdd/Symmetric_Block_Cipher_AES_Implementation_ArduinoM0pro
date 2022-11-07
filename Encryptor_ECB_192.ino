#include <stdio.h>
#include <string.h>
#include <stdint.h>

// Enable ECB, CTR and CBC mode. Note this can be done before including aes.h or at compile-time.
// E.g. with GCC by using the -D flag: gcc -c aes.c -DCBC=0 -DCTR=1 -DECB=1
#define CBC 0
#define CTR 0
#define ECB 1

#include "aes.h"


static void phex(uint8_t* str);
static int test_encrypt_ecb(void);
static int test_decrypt_ecb(void);


void setup()
{
  //Serial1.begin(9600);
  Serial.begin(9600);
  Serial1.begin(9600);
    

#if defined(AES192)
    Serial.println("\nTesting AES192\n\n");
#endif


test_encrypt_ecb();
   }


// prints string as hex
static void phex(uint8_t* str)
{
#if defined(AES192)
    uint8_t len = 24;
#endif

    unsigned char i;
    for (i = 0; i < 24; ++i)
        Serial.println("%.2x" + str[i]);
    Serial.println("\n");
}




static int test_encrypt_ecb(void)
{

#if defined(AES192)
uint8_t key[] = { 0x8e, 0x73, 0xb0, 0xf7, 0xda, 0x0e, 0x64, 0x52, 0xc8, 0x10, 0xf3, 0x2b, 0x80, 0x90, 0x79, 0xe5,0x62, 0xf8, 0xea, 0xd2, 0x52, 0x2c, 0x6b, 0x7b };
//uint8_t out[] = { 0xbd, 0x33, 0x4f, 0x1d, 0x6e, 0x45, 0xf2, 0x5f, 0xf7, 0x12, 0xa2, 0x14, 0x57, 0x1f, 0xa5, 0xcc };
#endif

    uint8_t in[]  = { 0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a };
    for (int i = 0; i < 16; i++)
    {
        Serial.println(in[i]);               
    }
    struct AES_ctx ctx;

    AES_init_ctx(&ctx, key);
    AES_ECB_encrypt(&ctx, in);

    Serial.println("ECB encrypt: ");

    Serial1.write(in,16);
}





void loop(){
  //wdwnd
  test_encrypt_ecb();
  delay (5000);
}

