#include "md5.h"
#include <math.h>
#include <string.h>

int initS(struct stat_struct *h);
int initK(struct stat_struct *h);


int main_init(struct stat_struct *stats, struct context_struct *conx, char *rawm) {
    initS(stats);
    initK(stats);

    conx->a0 = 0x67452301;
    conx->b0 = 0xefcdab89;
    conx->c0 = 0x98badcfe;
    conx->d0 = 0x10325476;

    int meslen = strlen(rawm);


}

void prepareInput (char* rawInput) {

}

int initS(struct stat_struct *h) {
    int firstround[4] = {7,12,17,22};
    int secondround[4] = {5,9,14,20};
    int thirdround[4] = {4,11,16,23};
    int fourthround[4] = {7,12,17,22};

    for (int i = 0; i < 4; ++i) {
        h->rots0[i] = firstround[i];
        h->rots1[i] = secondround[i];
        h->rots2[i] = thirdround[i];
        h->rots3[i] = fourthround[i];
    }
    h->rots[0] = h->rots0;
    h->rots[1] = h->rots1;
    h->rots[2] = h->rots2;
    h->rots[3] = h->rots3;

    return 0;
}

int initK(struct stat_struct *h) {
    for (int i = 0; i < 64; ++i) {
        //double inci = i + 1;
        h->k[i] = floor( pow(2,32) * fabs( sin( i+1 ) ) );
    }
    return 0;
}
