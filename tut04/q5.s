.text

main:
#     int x = 24; 
    li $t0, 24
while1:
#     if (x >= 42) goto endwhile1;
    bge $t0, 42, endwhile1
#         printf("%d\n",x);
    li $v0, 1
    move $a0, $t0
    syscall

    li $v0, 11
    li $a0, '\n'
    syscall
#         x += 3;
    addi $t0, $t0, 3
#         goto while1;
    j while1
endwhile1:    
#     // hidden return 0;
    li $v0, 0
    jr $ra