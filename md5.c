#include "md5.h"




//takes one block (512 bit as input)
void MD5(struct context_struct *c, struct stat_struct *s) {

    unsigned int A = c -> a0;
    unsigned int B = c -> b0;
    unsigned int C = c -> c0;
    unsigned int D = c -> d0;

    unsigned int* word = (unsigned int*) c->activeblock;


    //magic number party
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 16; ++j) {
            unsigned int F;
            unsigned int g;
            if (i == 0) {
                F = F(B,C,D);
                g = j;
            }
            else if (i == 1) {
                F = F(D,B,C);
                g = (5*(15+j)+1)%16;
            }
            else if (i == 2) {
                F = H(B,C,D);
                g = (3 * (32+j) + 5) % 16;
            }
            else if (i == 3) {
                F = I(C,B,D);
                g = (7 * (48 + j) ) % 16;
            }
            F = F + A + s->k[i*16+j] + *(word+g);
            A = D;
            D = C;
            C = B;
            B = B + ROTATE_LEFT(F, s->rots[i*16+j]);
        }
    }
    c->a0 = c->a0 + A;
    c->b0 = c->b0 + B;
    c->c0 = c->c0 + C;
    c->d0 = c->d0 + D;
}

