.data
.text
.globl main
main:
    li $v0, 5
    syscall
    move $a0, $v0
    li $v0, 5
    syscall
    move $a1, $v0
    li $t1, 1
pot:
    mul $t1, $t1, $a0
    addiu $a1, $a1, -1
    bnez $a1, pot
    j exit
exit:
    addu $a0, $zero, $t1
    li $v0, 1
    syscall
