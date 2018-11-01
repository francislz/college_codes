.data
    input: .word 4

.text
.globl main

main:
    li $v0, 5
    la $a0, input 
    syscall