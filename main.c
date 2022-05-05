#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "md5.h"



int main_preproc(struct stat_struct *h, struct context_struct *c, char rawinput[]);
void MD5 (struct context_struct *c, struct stat_struct *s);
showOutput (struct context_struct *c);


int main() {
    struct stat_struct stats;
    struct context_struct context;

    //todo user input (or file?)
    char inputtext[] = "123456789aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa8aaa";

    main_preproc(&stats, &context, inputtext);
    context.activeblock = (char*) malloc(64);
    for (int i = 0; i < context.blockamt; ++i) {
        memcpy(context.activeblock, context.text, 64);
        context.text = context.text + 64;//leaves memory block on last iteration
        MD5(&context, &stats);
    }
    free(context.activeblock);
    free(context.text - (context.blockamt*64));

    showOutput(&context);
}
//todo?
showOutput (struct context_struct *c) {
    printf("%u" , c->a0);
    printf("%u" , c->b0);
    printf("%u" , c->c0);
    printf("%u" , c->d0);
}