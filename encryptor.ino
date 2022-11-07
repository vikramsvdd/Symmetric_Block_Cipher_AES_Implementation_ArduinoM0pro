#include <stdio.h>
#include <string.h>
#include <stdint.h>
// Enable ECB, CTR and CBC mode. Note this can be done before including aes.h or at compile-time.
#define CBC 0
#define CTR 0
#define ECB 1
#include "aes.h"
static int test_encrypt_ecb(void);

void setup()
{
 Serial1.begin(9600);
 Serial.begin(9600);
 Serial.println("ECB encrypt: ");
 #if defined(AES128)
 Serial.println("\nTesting AES128\n\n");
  #endif 

}

static int test_encrypt_ecb(void)       // test_encrypt_ecb function declaration
{

#if defined(AES128)
    uint8_t key[] = { 0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c };   // key
#endif
    uint8_t in[]  = { 0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a };    // input hex array to be encrypted
    for (int i = 0; i < 16; i++)
    {
        Serial.println(in[i]);               
    }
    struct AES_ctx ctx;
    AES_init_ctx(&ctx, key);
    AES_ECB_encrypt(&ctx, in);    // Encrypting function taking in[] array as input and stores  the encrypted values in in[] itself ( in[] : output of encryptor)
/*for (int i = 0; i < 16; i++)
    {
        Serial.println(in[i]);                 // printing the Encrypted array
    }*/
    Serial1.write(in,16);         // sending the in[] array or encypted array which contains encrypted data to other arduino 
    }                                      // also EDIT : changed Serial1 to Serial11


void loop(){
  // 
test_encrypt_ecb();             // testing the encryption process.
delay (5000);
}
