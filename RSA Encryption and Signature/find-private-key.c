#include <stdio.h>
#include <openssl/bn.h>

#define NBITS 256

void printBN(char *msg, BIGNUM *a) {
    // BN_bn2hex(a) -  for a hex string
    // BN_bn2dec(a) -  for a decimal string
    char *number_str BN_bn2hex(a);
    printf("%s %s\n", msg, number_str);
    OPENSSL_free(number_str);
}

int main() {
    BN_CTX *ctx = BN_CTX_new();

    BIGNUM *p, *q, *n, *phi, *e, *d, *m, *c, *res;
    BIGNUM *new_m, *p_minus_one, *q_minus_one;
    
    p = BN_NEW();
    q = BN_NEW();
    n = BN_NEW();
    phi = BN_NEW();
    e = BN_NEW();
    d = BN_NEW();
    m = BN_NEW();
    c = BN_NEW();
    res = BN_NEW();

    new_m = BN_NEW();
    p_minus_one = BN_NEW();
    q_minus_one = BN_NEW();

    BN_bn2hex(&e,"0D88C3");

    BN_bn2hex(&p,"F7E75FDC469067FFDC4E847C51F452DF");
    BN_bn2hex(&q,"E85CED54AF57E53E092113E62F436F4F");

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
    printBN("Private key d:",d)
}
