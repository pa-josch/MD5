#include <stdio.h>
#include "md5.h"



void main_init(struct stat_struct *h, struct context_struct *c);
void MD5 (struct context_struct *c, struct stat_struct *s, int M[16]);
showOutput (struct context_struct *c);


int main() {
    struct stat_struct stats;
    struct context_struct context;

    main_init(&stats, &context);

    showOutput(&context);
}

showOutput (struct context_struct *c) {
    printf("%u" , c->a0);
    printf("%u" , c->b0);
    printf("%u" , c->c0);
    printf("%u" , c->d0);

}