# Public-Key-Cryptography
A great challenge in secret-key encryption is the key agreement problem that is, how the communication parties obtain the shared secret key.

This problem is solved by the **public key cryptography**.

In public key encryption, there are two keys, a public key and a private key. The public key is used for encryption, and only the party who knows the corresponding private key can do the decryption.

Public-key cryptography can also be used for generating digital signature. Signature can only be created using a private key, but everybody who has the corresponding public key can verify the signature. Other than 
encryption and signature, public key cryptography has many other
applications.

## Basics of Public Key of Cryptography
**Diffie-Hellman Key exchange protocol**
This method allows communicati on parties to exchange a
shared secret without a face-to-face meeting or using a trusted courier.
The main goal here was tou slightly modify the usage of one secret key to using 2 secret keys, one for encryption and the other for decryption.

**public-key cryptosystem**, in which 
    "enciphering and deciphering are governed by distinct keys,
    E and D ,such that computing D from E is computationally infeasible. The 
    enciphering key E can thus be publicly disclosed without compro mising the deciphering key D"

Today, public key cryptography has become a cornerstone in the Internet infrastructure, protecting our logins, online banking, web
brows ing, communications, etc.

**RSA (Rivest–Shamir–Adleman)** is one of the first public-key cryptosystems and is widely used for secure communication.
    The RSA algorithm is based on modulo operations.
    In computing, the modulo operation finds
    the remainder after division of one number by another (the second number is called modulus).

## Math Background - 
    Discrete Logarithmic Problem
    modulus operation, 
    Euler's toitem function
    Extended Eulidean Algorithm

### Lab Tasks

#### Task 1 - Deriving the private key
Let p, q, and e be three prime numbers. 
Let n = p*q. We will use (e, n) as the public key.

Calculate the private key d
    p = F7E75FDC469067FFDC4E847C51F452DF
    q = E85CED54AF57E53E092113E62F436F4F
    e = 0D88C3