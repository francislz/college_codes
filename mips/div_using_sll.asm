.text
.globl main

main:
    li $t1, 16
    srl $t3, $t1, 2
    li $v0, 1
    add $a0, $t3, $zero
    syscall
