#include <stdlib.h>
struct node {
    int data;
};

int main (void) {
    struct node *a, *b, *c, *d;
    a = NULL;
    b = malloc(sizeof *b);
    c = malloc(sizeof (struct node));
    d = malloc(8);
    c = a;
    d->data = 42;
    c->data = 42;

    return 0;
}