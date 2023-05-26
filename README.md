# Arduino M0 pro- Symmetric_Block_Cipher_AES Algorithm Implementation

I have implemented AEC algorithm and tested out the encryption and decryption process using two arduino M0 pro (which is basically powered by an  ARM-32 bit cortex M0+ microcontroller), which is an arduino.org board with ARM-32 bit architecture. Below are my attached references below, I also optimised the code for better suited performace for arduino M0 pro's environment. I have tested out the 128, 192 and 256 bit key versions for both ECB and CBC algorithms . Importantly, the disadvantage of ECB can be clearly seen in the case of Image encryption, where mapping an input data to a particular encrypted data reveals a pattern, hence theneed for CBC based encryption and decryption.

Also, I have altered the standard AES library offered by arduino.cc and modified it to suit Arduino M0 pro or similar ARM environments, do have a look!

References: 


https://github.com/kokke/tiny-AES-c

https://github.com/suculent/thinx-aes-lib
 



