#include <stdlib.h>

int main (void) { 
    int  x;  // a variable located at address 1000 with initial value 0
    int *p;  // a variable located at address 2000 with initial value 0


    p = &x;     // p 1000; x=0 

    x = 5;      // p=1000; x=5

    *p = 3;     // adress 1000 = 3; x=3; p=1000
    printf("%d", x);

    x = (int)p; // p=1000; x=1000

    x = (int)&p;// p=1000; x=2000

    p = NULL;   // p=NULL   ;x=2000

    *p = 1;     // error. p is null. 

    return 0;
}

