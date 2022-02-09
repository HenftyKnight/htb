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
    
    BIGNUM  *p = BN_new();
    BIGNUM  *q = BN_new();
    BIGNUM  *n = BN_new();
    BIGNUM  *phi = BN_new();
    BIGNUM  *e = BN_new();
    BIGNUM  *d = BN_new();
    BIGNUM  *m = BN_new();
    BIGNUM  *c = BN_new();
    BIGNUM  *res = BN_new();

    BIGNUM  *new_m = BN_new();
    BIGNUM  *p_minus_one = BN_new();
    BIGNUM  *q_minus_one = BN_new();

    BN_hex2bn(&e,"0D88C3");

    BN_hex2bn(&p,"F7E75FDC469067FFDC4E847C51F452DF");
    BN_hex2bn(&q,"E85CED54AF57E53E092113E62F436F4F");

    // Generate phi
    BN_sub(p_minus_one, p, BN_value_one()); // p - 1
    BN_sub(q_minus_one, q, BN_value_one()); // q - 1
    BN_mul(n,p,q,ctx); // n=pq
    BN_mul(phi,p_minus_one, q_minus_one, ctx); // compute phi 

    // Check wheter e and phi(n) are relatively prime
    BN_gcd(res, phi, e, ctx);
    if (!BN_is_one(res)) {
        exit(0);
    }

    // compute private key
    BN_mod_inverse(d,e,phi,ctx);
    printBN("Private key d:",d);
}
