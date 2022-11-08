# Arduino M0 pro- Symmetric_Block_Cipher_AES Algorithm Implementation

I have implemented AEC algorithm and tested out the encryption and decryption process using two arduino M0 pro, which is an arduino.org board with ARM-32 bit architecture. All thanks to my attached reference below , for providing me with base code, which I am able to modify to suit Arduino M0's  environment. I have tested out the 128, 192 and 256 bit key versions for both ECB and CBC algorithms . 

Reference:
https://github.com/kokke/tiny-AES-c
 
 Attached below is the Encryption time, Decryption time and Total time taken (all in us): 
 
Results:

| Encryption Time(us)  |	128-bit_key  |	192-bit_key  |	256-bit_key |
| ECB |	273  |	396  |	387 |
| CBC |	941 |	1204  |	1306
			
			
| Decryption Time (us)  |	128-bit_key  |	192-bit_key  |	256-bit_key |
| ECB |	413  |	569  |	589 |
| CBC |	1588	1984	2242
			
Total Time (us)	128-bit_key	192-bit_key	256-bit_key
ECB	686	965	976
CBC	2529	3188	3548
