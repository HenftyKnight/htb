#include<stdio.h>
#include<arpa/inet.h>
#include<openssl/sha.h>

int main(int argc, const char *argv[]) {

	int i;
	unsigned char buffer[SHA256_DIGEST_LENGTH];
	SHA256_CTX c;SHA256_Init(&c);

	for(i=0; i<64; i++)
		SHA256_Update(&c, "*", 1);

	// MAC of the original message M (padded)
	c.h[0] = htole32(0xc58aab22);
	c.h[1] = htole32(0x1e746509);
	c.h[2] = htole32(0x05fa113e);
	c.h[3] = htole32(0x2663c5c0);
	c.h[4] = htole32(0x521b86cd);
	c.h[5] = htole32(0x684cc401);
	c.h[6] = htole32(0xad47f8c1);
	c.h[7] = htole32(0xc84a09ec);
	
	// Append additional message
	SHA256_Update(&c, "&download=secret.txt", 20);
	SHA256_Final(buffer, &c);
	
	for(i = 0; i < 32; i++) {
		printf("%02x", buffer[i]);
	}
	
	printf("\n");
	return 0;
}
