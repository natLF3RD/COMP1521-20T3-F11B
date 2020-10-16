    .text
main:
# int main(void) {
#     int i; <- $t0
#     int numbers[10] = {0,1,2,3,4,5,6,7,8,9}; ***

#     i = 0;
    li $t0, 0
#     while (i < 10) {
#     while (i >= 10) skip over content of loop
while2:
    bge $t0, 10 endwhile2
#         printf("%d\n", numbers[i]);
        la $t1, numbers
        mul $t2, $t0, 4 
        add $t3, $t1, $t2   #  &(numbers[i])

        lw $a0, ($t3)       # numbers[i]

        #printf
        li $v0, 1
        syscall
#         i++;
    addi $t0, $t0, 1
#     }
    b while2
endwhile2:
# }

    .data
#     int numbers[10] = {0,1,2,3,4,5,6,7,8,9}; ***
numbers: 
    .word 0 1 2 3 4 5 6 7 8 9