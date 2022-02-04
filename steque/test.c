#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "steque.h"
#include "steque.c"

int main() {
    /* initialize a steque_t structure */
    steque_t *this = (steque_t *) malloc(sizeof(steque_t));
    memset(this, 0, sizeof(*this));
    steque_init(this);
    printf("%p: %p | %d | %p\n", this, this->front, this->N, this->back);
    return 0;

    /*  */
}