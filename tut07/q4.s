    .text

# int main(void) {
main:

# old     for (int row = 0; row < 6; row++)  {
#   int row = 0; <- $t0
    li $t0, 0
    #alt. move $t0, $zero

#   while (row < 6) {
    # if (row >= 6) goto end of loop
while1:
    bge $t0, 6, endwhile1
#  old       for (int col = 0; col < 12; col++) {
#   int col = 0;
    li $t1, 0
#   while (col <12) {
while2:
#   if (col >= 12) goto end of loop
    bge $t1, 12, endwhile2

#             printf ("%c", flag[row][col]);
    #get to row pos
    la $t3, flag
    # width = no. of eleements * elements size
    # start of row = width * nth_row
    li $t6, 1
    li $t4, 12 # 12 columns
    mul $t4, $t4, $t6 # char size
    mul $t4, $t0, $t4 # correct start of row.

    # add on element size * col
    mul $t5, $t1, $t6, # char size
    add $t5, $t5, $t4

    add $t3, $t5, $t3   #actual final address

    lb $a0, ($t3) ## load char
    li $v0, 11

    syscall


#   col = col + 1;
    addi $t1, $t1, 1
    j while2
endwhile2:
#          }
#         printf ("\n");
    li $v0, 11
    li $a0, '\n'
    syscall

#     row = row + 1;
    addi $t0, $t0, 1
#   }
    j while1 # loop
endwhile1:
#     
    li $v0, 0
    jr $ra
# }

    .data
flag:   
    .byte   '#' '#' '#' '#' '#' '.' '.' '#' '#' '#' '#' '#'
   .byte    '#' '#' '#' '#' '#' '.' '.' '#' '#' '#' '#' '#'
   .byte    '.' '.' '.' '.' '.' '.' '.' '.' '.' '.' '.' '.'
   .byte    '.' '.' '.' '.' '.' '.' '.' '.' '.' '.' '.' '.'
   .byte    '#' '#' '#' '#' '#' '.' '.' '#' '#' '#' '#' '#'
   .byte    '#' '#' '#' '#' '#' '.' '.' '#' '#' '#' '#' '#'