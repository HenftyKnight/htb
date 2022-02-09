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

    BN_hex2bn(&e,"10001");
    BN_hex2bn(&n,"F588DFE7628C1E37F83742907F6C87D0FB658225FDE8CB6BA4FF6DE95A23E299F61CE9920399137C090A8AFA42D65E5624AA7A33841FD1E969BBB974EC574C66689377375553FE39104DB734BB5F2577373B1794EA3CE59DD5BCC3B443EB2EA747EFB0441163D8B44185DD413048931BBFB7F6E0450221E0964217CFD92B6556340726040DA8FD7DCA2EEFEA487C374D3F009F83DFEF75842E79575CFC576E1A96FFFC8C9AA699BE25D97F962C06F7112A028080EB63183C504987E58ACA5F192B59968100A0FB51DBCA770B0BC9964FEF7049C75C6D20FD99B4B4E2CA2E77FD2DDC0BB66B130C8C192B179698B9F08BF6A027BBB6E38D518FBDAEC79BB1899D");


    // Encryption
    BN_hex2bn(&m1,"9b71d33565fa095b8555c2ee50fd2b6c59de5eca60abaddae6b2265684986927");


    BN_hex2bn(&S,"72eafbc8a1ee36ad221f9d625613efad853e112e11a535c6589db926629855b03d4b78a4ebc058cf46e2ff763339acde6956e7105e9909b5a2e72434228eec129e44e5f1127de8d155909e034d84b6feafa2058273f1aaf7d661ba1503c4dcaf5ab7af92df5739faca06487a67784dd21568e077153fde67ee6ef6beed99d2c77935bdc9fcccdac77e6f485d96f7cd476b1ee3821cdee15c4487c7b286f116fada0e736d9ae35b08ed63536f1f993f3a986ac0ea22e9c355bafbc16ac270700d3036f5a368fff8b849d2279778109f06510dbc75447f66ab6c13cd47a63b75bc661eb348088d72a485be9b44db084b00f0dff1113971dc0b05790523db551584");
    
    printBN("Original Message: ", m1);
    //printBN("Cipher Signature:",S);


    BN_mod_exp(C,S,e,n,ctx);
    printBN("Value of C Computed: ", C);
    //printBN("Decryption Result: ", new_m);

    /*
    if (BN_cmp(C,m1) == 0){
	printf("Verified Signature");
    }
    else{
	printf("Verification Failed");
    }
    */
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
