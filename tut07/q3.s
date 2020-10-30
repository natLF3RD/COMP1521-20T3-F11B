    .text

# a[] -> $a0
# length -> $a1

# first_el -> $t0
# max_so_far -> $t1
# int max(int a[], int length) {
max:
prologue:
    #set up stack and save what we want to use
    #save $ra
    addi $sp, $sp, -4
    sw $ra, ($sp)
    #save $s0
    addi $sp, $sp, -4
    sw $s0, ($sp)
    #save #s1
    addi $sp, $sp, -4
    sw $s1, ($sp)




#     int first_element = a[0];
    lw $s0, ($a0)

#     if (length == 1) {
#       if (length != 1) goto else
max_if1:
    bne $a1, 1, max_else1
        #### return first_element; #####
    move $v0, $t0
    j epilogue

    j max_endelse1
#     } else {
max_else1:
#         // find max value in rest of array
#         int max_so_far = max(&a[1], length - 1); ######
    addi $a0, $a0, 4 # -> addr of next element of a
    addi $a1, $a1, -1 #length-1
    jal max


#         if (first_element > max_so_far) {
max_if2:
    # if (first_element <= max_so_far) goto endif2
    ble $s0, $s1, max_endif2
#             max_so_far = first_element;
    move $s1, $s0
#         }  
max_endif2:


#         return max_so_far; ######
    move $v0, $s1
    j epilogue
    
max_endelse1:
#     }

epilogue:
    #put stack back to how it was
    lw $s1, ($sp)
    addi $sp, $sp, 4

    lw $s0, ($sp)
    addi $sp, $sp, 4

    lw $ra, ($sp)
    addi $sp, $sp, 4

    #save $ra
    #save $s0
    #save #s1

max_end:
    jr $ra
# }

    .data
