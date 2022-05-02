#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "md5.h"



int main_preproc(struct stat_struct *h, struct context_struct *c, char rawinput[]);
void MD5 (struct context_struct *c, struct stat_struct *s, int M[16]);
showOutput (struct context_struct *c);


int main() {



    struct stat_struct stats;
    struct context_struct context;

    char inputtext[] = "123456789";


    main_preproc(&stats, &context, inputtext);

    context.text = context.text + 7;
    showOutput(&context);
    size_t a = sizeof(context.text);
    size_t b = strlen(context.text);

}

showOutput (struct context_struct *c) {
    printf("%u" , c->a0);
    printf("%u" , c->b0);
    printf("%u" , c->c0);
    printf("%u" , c->d0);

}