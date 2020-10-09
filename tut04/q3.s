.text
    # $t0 <- x
    # $t1 <- y


    li      $v0, 4              # printf("Enter a number: ");
    la      $a0, prompt
    syscall

    li      $v0, 5              # scanf("%d", &x);
    syscall
    # can assume v0 stores our read number.
    move    $t0, $v0   # x now stores read variable


#     if (x <= 46340) goto else2;
    ble     $v0, 46340, else2
#         printf("square too big for 32 bits\n");
    li      $v0, 4              
    la      $a0, error
    syscall
#         goto endif2;
    j       endif2

else2:
# y = x * x;
    mul     $t1, $t0, $t0
# printf("%d\n", y);
    li      $v0, 1
    move    $a0, $t1
    syscall

    li      $v0, 11
    li      $a0, '\n'
    syscall

endif2:
    li      $v0, 0
    jr      $ra
    # return 0;


.data
prompt:
    .asciiz "Enter a number: "
error:
    .asciiz "square too big for 32 bits\n"