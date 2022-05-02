#include "md5.h"
#include <math.h>
#include <malloc.h>
#include <string.h>

int initStats(struct stat_struct *h, struct context_struct *c);
int* prepString(char str[]);

int main_preproc(struct stat_struct *h, struct context_struct *c, char rawinput[]) {
    initStats(h, c);
    c->text = prepString(rawinput);
    return 0;
}

int initStats(struct stat_struct *h, struct context_struct *c) {
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

    for (int i = 0; i < 64; ++i) {
        //double inci = i + 1;
        h->k[i] = floor( pow(2,32) * fabs( sin( i+1 ) ) );
    }

    c->a0 = 0x67452301;
    c->b0 = 0xefcdab89;
    c->c0 = 0x98badcfe;
    c->d0 = 0x10325476;

    return 0;
}


int* prepString(char str[]) {
    unsigned strbytes = strlen(str);
    int restbit = (strbytes * 8) % BLOCKSIZE;
    int padbytes = 0;
    if (restbit < MAGIC_PADDING_NUMBER)
        padbytes = (MAGIC_PADDING_NUMBER - restbit)/8;
    else
        padbytes = (BLOCKSIZE - restbit + MAGIC_PADDING_NUMBER)/8;

    if ( !((8 * (strbytes + padbytes) ) % BLOCKSIZE == MAGIC_PADDING_NUMBER) ) //TEST
        return NULL;

    char* ptr = (char*) calloc(strbytes + padbytes, sizeof(char));//TODO TODO TODO da fehlen noch 8 byte
    char* origin = ptr;
    memcpy(ptr, str, strlen (str));
    ptr = ptr + strlen(str);
    *ptr = (char) 128; //single1 padding
    ptr = ptr + padbytes;
//    long long padend = 8 * padbytes;
//    *ptr = padend; //funktioniert nicht
    return origin;
}


