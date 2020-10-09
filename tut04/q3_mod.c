#include <stdio.h>

int main(void) {
    int x, y;
    printf("Enter a number: ");
    scanf("%d", &x);

    if (x > 46340) goto if1;
    goto else1;
    // if (x > 46340) {
if1:
        printf("square too big for 32 bits\n");
        goto endif1;
    // } else {
else1:
        y = x * x;
        printf("%d\n", y);
endif1:    // }

    return 0;
}


int main(void) {
    int x, y;
    printf("Enter a number: ");
    scanf("%d", &x);

    // if (x > 46340) {
    if (x <= 46340) goto else2;
        printf("square too big for 32 bits\n");
        goto endif2;
    // } else {
else2:
        y = x * x;
        printf("%d\n", y);
    // }
endif2:

    return 0;
}