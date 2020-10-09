.text

main:
    # $t0 <- x
    # $t1 <- y


    li      $v0, 4              # printf("Enter a number: ");
    la      $a0, prompt
    syscall

    li      $v0, 5              # scanf("%d", &x);
    syscall
    # can assume v0 stores our read number.
    move    $t0, $v0   # x now stores read variable
# y = x * x;
    mul     $t1, $t0, $t0
# printf("%d\n", y);
    li      $v0, 1
    move    $a0, $t1
    syscall

    li      $v0, 11
    li      $a0, '\n'
    syscall
# return 0;
    li      $v0, 0
    jr      $ra

.data
prompt:
    .asciiz "Enter a number: "