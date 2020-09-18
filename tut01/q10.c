#include <stdio.h>

// a recursive is a function that calls itself
// 3 steps:
    // "base case" -> case where the recursion will stop itself
    // "state change" -> how to move closer to the end
    // "call to self" -> recursive part

void print_nums(int array[], int index) {
    // base case
    if (index >= 10) {
        return;
    }

    printf("%d\n", array[index]);

    // state change
    index++;


    // call to self
    print_nums(array, index);

    return;
}

int main(void)
{
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // for (int i = 0; i < 10; i++) {
    //     printf("%d\n", nums[i]);
    // }
    // int i=0;
    print_nums(nums, 0);

    return 0;
}