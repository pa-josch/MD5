#include "md5.h"

//todo M[] als eingabe -> cheaten

//takes one block (512 bit as input)
void MD5 (struct context_struct *c, struct stat_struct *s, int M[16]) {
    unsigned int A = c -> a0;
    unsigned int B = c -> b0;
    unsigned int C = c -> c0;
    unsigned int D = c -> d0;
    unsigned int eq;
    unsigned int tempword;
    int g;

    for (int i = 0; i < 16; ++i) {
        eq = F(B, C, D);
        g = i;

        tempword = D;
        D = C;
        C = B;
        B = B + ROTATE_LEFT((A + tempword + s->k[i] + M[g]) , s->rots0[i%4] );
        A = tempword;
    }

    for (int i = 16; i < 32; ++i) {
        eq = G(B, C, D);
        g = (5*i + 1) % 16;

        tempword = D;
        D = C;
        C = B;
        B = B + ROTATE_LEFT(A + tempword + s->k[i] + M[g] , s->rots1[i%4] );
        A = tempword;
    }

    for (int i = 0; i < 16; ++i) {
        eq = H(B, C, D);
        g = ( 3*i + 5 ) % 16;

        tempword = D;
        D = C;
        C = B;
        B = B + ROTATE_LEFT(A + tempword + s->k[i] + M[g] , s->rots2[i%4] );
        A = tempword;
    }

    for (int i = 0; i < 16; ++i) {
        eq = I(B, C, D);
        g = (7*i) % 16;

        tempword = D;
        D = C;
        C = B;
        B = B + ROTATE_LEFT(A + tempword + s->k[i] + M[g] , s->rots3[i%4] );
        A = tempword;
    }

    c->a0 = c->a0 + A;
    c->b0 = c->b0 + B;
    c->c0 = c->c0 + C;
    c->d0 = c->d0 + D;
}

