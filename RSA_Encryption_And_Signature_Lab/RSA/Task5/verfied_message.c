#include <stdio.h>
#include <openssl/bn.h>

#define NBITS 256

void printBN(char *msg, BIGNUM *a) {
    // BN_bn2hex(a) -  for a hex string
    // BN_bn2dec(a) -  for a decimal string
    char *number_str = BN_bn2hex(a);
    printf("%s %s\n", msg, number_str);
    OPENSSL_free(number_str);
}

int main() {
    BN_CTX *ctx = BN_CTX_new();

    // BIGNUM *p, *q, *n, *phi, *e, *d, *m, *c, *res;
    // BIGNUM *new_m, *p_minus_one, *q_minus_one;
    
    BIGNUM  *m1 = BN_new();
    BIGNUM  *m2 = BN_new();
    BIGNUM  *n = BN_new();
    BIGNUM  *phi = BN_new();
    BIGNUM  *e = BN_new();
    BIGNUM  *d = BN_new();
    BIGNUM  *C = BN_new();
    BIGNUM  *S = BN_new();
    BIGNUM  *res = BN_new();


    BIGNUM  *new_m = BN_new();
    BIGNUM  *p_minus_one = BN_new();
    BIGNUM  *q_minus_one = BN_new();

    BN_hex2bn(&e,"010001");
    BN_hex2bn(&n,"AE1CD4DC432798D933779FBD46C6E1247F0CF1233595113AA51B450F18116115");
    // BN_hex2bn(&p,"F7E75FDC469067FFDC4E847C51F452DF");
    // BN_hex2bn(&q,"E85CED54AF57E53E092113E62F436F4F");

    // Generate phi
    //BN_sub(p_minus_one, p, BN_value_one()); // p - 1
    //BN_sub(q_minus_one, q, BN_value_one()); // q - 1
    //BN_mul(n,p,q,ctx); // n=pq
    //BN_mul(phi,p_minus_one, q_minus_one, ctx); // compute phi 

    // Check wheter e and phi(n) are relatively prime
    //BN_gcd(res, phi, e, ctx);
    //if (!BN_is_one(res)) {
    //    exit(0);
   //}

    // compute private key
    //BN_mod_inverse(d,e,phi,ctx);
    //BN_hex2bn(&d,"74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");
    //printBN("Private key d:",d);

    // Encryption
    BN_hex2bn(&m1,"4c61756e63682061206d697373696c652e");

    BN_hex2bn(&S,"643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6802F");

    printBN("Cipher Sinature:",S);


    BN_mod_exp(C,S,e,n,ctx);
    //printBN("Decryption Result: ", new_m);

    if (BN_cmp(C,m1) == 0){
	printf("Verified Signature");
    }
    else{
	printf("Verification Failed");
    }
    // Clearing sensitive data from memory
    BN_clear_free(m1);
    BN_clear_free(m2);
    BN_clear_free(e);
    BN_clear_free(n);
    BN_clear_free(d);
    BN_clear_free(C);
    BN_clear_free(S);
    //BN_clear_free(c);
    //BN_clear_free(res);

    BN_clear_free(new_m);
    BN_clear_free(p_minus_one);
    BN_clear_free(q_minus_one);

    return 0;
}
