# Arduino M0 pro- Symmetric_Block_Cipher_AES Algorithm Implementation
TLDS: (for ling story look down)

I have implemented AEC algorithm and tested out the encryption and decryption process using two arduino M0 pro (which is basically powered by an  ARM-32 bit cortex M0+ microcontroller), which is an arduino.org board with ARM-32 bit architecture. Below are my attached references below, I also optimised the code for better suited performace for arduino M0 pro's environment. I have tested out the 128, 192 and 256 bit key versions for both ECB and CBC algorithms . Importantly, the disadvantage of ECB can be clearly seen in the case of Image encryption, where mapping an input data to a particular encrypted data reveals a pattern, hence theneed for CBC based encryption and decryption.

Also, I have altered the standard AES library offered by arduino.cc and modified it to suit Arduino M0 pro or similar ARM environments, do have a look!

References: 


https://github.com/kokke/tiny-AES-c

https://github.com/suculent/thinx-aes-lib

# Detailed Explanation:


I have successfully tested out the 128 bit key, 192 and 256 bit key versions of both Electronic-Code-Book (ECB) AES Encryption_Decryption algorithm and Cipher-Block-Chaining (CBC) AES Encryption_Decryption algorithm. The implementation is in generic C language, as there are not as many Cryptographic libraries compatible with Arduino M0 pro compared to Arduino Uno as M0 pro has an ARM architecture whereas the more common boards have an AVR architecture. ECB algorithm is less weight but also less secure compared to CBC algorithm, because ECB always encrypts a particular text  to an unique cipher text which is not the case with CBC. With regards to performance in time, EBC-128 bit key algorithm was the fastest but least secure whereas CBC-256 bit key algorithm was the slowest but the most secure. The performance of all algorithms are well below the expected threshold (100ms)  . I have attached the results below. (in us) :

An another success !  I was able to successfully use the standard AES library itself for the Encryption-Decryption process. Though I had to manually make the standard library compatible with an ARM environment by modifying certain things,  I previously overlooked some aspects and deemed it difficult and moved on to the non-standard library implementation, but upon deeper attention was able to resolve those things. The standard library offers only one encryption mode (CBC-128 bit ) but the good news is that this algorithm is twice faster (1447 us) than my previous implementation (2529 us), also adding to the good news it comes with an automatic data-padding feature which pads bits with inputs that does not match with the length of the key (In my previous implementation I had to manually do that but got saved the trouble in this standard implementation). 

Also, I added an improvement to the library to cater to the intrinsic advantage that Arduino M0 pro has : It has a vast space available in its SRAM (32kb) compared to AVR arduino boards and thus I changed all the references pointing to FLASH memory or PROGMEM to SRAM. This resulted in a 300 us saving and the total encryption-decryption time was around 1152 us. I have uploaded the modified library as well as the code in the repository

In my opinion one can proceed forward with implementing this CBC-128 bit implementation in a twinklet_twinkler system as it  offers a good balance: It offers good security as well as a decent performance in time, adding to that, due to its nature of being a standard-library, it is also reliable! . 
 



