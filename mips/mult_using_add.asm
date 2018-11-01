# Cod to calculate the a * b, using MIPS assembly
.text
.globl main

main:
    li $t0, 16
    li $t1, 4
while:
    add $t2, $t2, $t1
    addi $t0, $t0, -1
    beq	$t0, $zero, exit
    j while
exit:
    li $v0, 1
    add $a0, $t2, $zero
    
    syscall