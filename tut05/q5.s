    .text
main:
# int main(void) {
#     int i; <- $t0
#     int numbers[10] = {0}; ***

#     i = 0;
    li $t0, 0
#     while (i < 10) {
while1:
#->   if (i >= 10) then skip loop content
    bge $t0, 10, endwhile1
#         scanf("%d", &numbers[i]);
    li $v0, 5
    syscall
    # scanned result is now in $v0
    
    # get location of numbers[i]
    la $t1, numbers
    mul $t2, $t0, 4
    add $t3, $t2, $t1

    #store in numbers[i]
    sw $v0, ($t3)

#   i++;
    addi $t0, $t0, 1
    b while1: # or could use j instead
#     }
endwhile1:
# }

    .data
#     int numbers[10] = {0}; ***
numbers:
    .word 0 0 0 0 0 0 0 0 0 0