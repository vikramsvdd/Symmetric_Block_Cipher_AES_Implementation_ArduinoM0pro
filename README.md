# Arduino M0 pro- Symmetric_Block_Cipher_AES Algorithm Implementation

Reference:
https://github.com/kokke/tiny-AES-c
 
Results:
Encryption Time(us)	128-bit_key	192-bit_key	256-bit_key
ECB	273	396	387
CBC	941	1204	1306
			
			
Decryption Time (us)	128-bit_key	192-bit_key	256-bit_key
ECB	413	569	589
CBC	1588	1984	2242
			
Total Time (us)	128-bit_key	192-bit_key	256-bit_key
ECB	686	965	976
CBC	2529	3188	3548
