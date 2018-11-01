.data
    size: .word 2
    array: .word 4
.text
.globl main
main:
    la $a0, size
    li $v0, 5
    syscall
    lw $t0, 0($a0)
    la $a0, array
while:
    li $v0, 5
    syscall
    sw $v0, 0($a0)
    addi $a0, $a0, 4
    addi $t0, $t0, -1
    bne $t0, $zero, while