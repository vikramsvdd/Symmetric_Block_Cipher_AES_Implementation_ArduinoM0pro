#include <stdio.h>
#include <string.h>
#include <stdint.h>
// Enable ECB, CTR and CBC mode. Note this can be done before including aes.h or at compile-time.
#define CBC 0
#define CTR 0
#define ECB 1
#include "aes.h"
static int test_decrypt_ecb(void); 

void setup()
{
   Serial1.begin(9600);
   Serial.begin(9600);
   #if defined(AES128)
    Serial.println("\nTesting AES128\n\n");
#endif

 }

static int test_decrypt_ecb(void)
{

#if defined(AES128)
    uint8_t key[] = { 0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c };  // key
uint8_t in[16];  // declaring in[] array which is going to receive the encrypted array from Encryptor
for (int i = 0; i < 16; i++)
  {
   in[i]=0;     
  }
  if (Serial1.available()){

    Serial1.readBytes(in,16); // receiving the encrypted text from encryptor and storing in in[] array
  
   /* for (int i = 0; i < 16; i++)
  {
    Serial.println(in[i]);     // displaying the received array from encryptor 
  } */
#endif

 uint8_t outr[]   = { 0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a }; // reference output array meant to be compared with output of decryptor
 struct AES_ctx ctx;
  AES_init_ctx(&ctx, key);
  AES_ECB_decrypt(&ctx, in);  // decrypting function taking in[] as input and stores the decrypted values in in[] itself (in[] : output of decryptor)
Serial.println("ECB decrypt: ");
for (int i = 0; i < 16; i++)
  {
    Serial.println(in[i]);     // displaying the received array from encryptor 
  }

    
if (0 == memcmp((char*) outr, (char*) in , 16)) {
        Serial.println("SUCCESS!\n");
  return(0);                                            // Function for checking whether the encryption-decryption process is a success or a failure
    } else {
        //Serial.println("FAILURE!\n");
  return(1);
    }
  }
}



void loop(){
  
  //
test_decrypt_ecb(); // testing the decryption process.

}
