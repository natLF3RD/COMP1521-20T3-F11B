#include <stdio.h>

int main(void) {
    // for (int x = 24; x < 42; x += 3) {
    //     printf("%d\n",x);
    // }
    int x = 24; 
    // while (x < 42) {
while1:
    if (x >= 42) goto endwhile1;
        printf("%d\n",x);
        x += 3;
        goto while1;
endwhile1:    //}
    // hidden return 0;
}