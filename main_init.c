#include "md5.h"
#include <math.h>
#include <malloc.h>
#include <string.h>

int initStats(struct stat_struct *s, struct context_struct *c);
void *prepString(char str[], struct context_struct *c);

int main_preproc(struct stat_struct *h, struct context_struct *c, char rawinput[]) {
    initStats(h, c);
    prepString(rawinput, c);
    return 0;
}

int initStats(struct stat_struct *s, struct context_struct *c) {
    unsigned int  rotations[64] = {7,12,17,22, 7,12,17,22,
                                   7,12,17,22, 7,12,17,22,
                                   5,  9, 14, 20, 5,  9, 14, 20,
                                   5,  9, 14, 20, 5,  9, 14, 20,
                                   4, 11, 16, 23, 4, 11, 16, 23,
                                   4, 11, 16, 23, 4, 11, 16, 23,
                                   6, 10, 15, 21, 6, 10, 15, 21,
                                   6, 10, 15, 21, 6, 10, 15, 21,
    };
    for (int i = 0; i < 64; ++i) {
        s->k[i] = floor(pow(2, 32) * fabs(sin(i + 1 ) ) );
        s->rots[i] = rotations[i];
    }
    c->a0 = 0x67452301;
    c->b0 = 0xefcdab89;
    c->c0 = 0x98badcfe;
    c->d0 = 0x10325476;
    return 0;
}
void *prepString(char str[], struct context_struct *c) {
    unsigned strbytes = strlen(str);
    int restbit = (strbytes * 8) % BLOCKSIZE;
    int padbytes = 0;
    if (restbit < MAGIC_PADDING_NUMBER)
        padbytes = (MAGIC_PADDING_NUMBER - restbit)/8;
    else
        padbytes = (BLOCKSIZE - restbit + MAGIC_PADDING_NUMBER)/8;
    int totalsize = strbytes + padbytes + 8;
    c->blockamt = totalsize*8/512;
    char* ptr = (char*) calloc(totalsize, sizeof(char));
    c->text = ptr;
    memcpy(ptr, str, strlen (str));
    ptr = ptr + strlen(str);
    *ptr = (char) 128; //single1 padding
    /*todo strlen(str) als 64 bit zahl anhängen (macht hier keinen ärger wegen calloc
     * danach sollte es eigentlich korrekt sein */
}



