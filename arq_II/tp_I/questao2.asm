.data
    array: .word
.text
.globl main
main:
    li $v0, 5
    syscall
    move $a0, $v0
    la $a1, array
    addu $t0, $zero, $zero
    jal read_data
    # Recarrega o endereço base de array
    la $a1, array
    jal sort
read_data:
    li $v0, 5
    syscall
    sw $v0, 0($a1)
    addiu $a1, $a1, 4
    addiu $t0, $t0, 1
    sub $t1, $a0, $t0
    bnez $t1, read_data
    jr $ra

sort:
    move $t0, $a1 #Move o addr base de array para $t0
    move $t2, $a0 # Move n para $t2
    addiu $t2, $t2, -1
for1:
    addu $t3, $zero, $t2 # 
    addu $t1, $zero, $t0 # Copia o end base para $t1
for2:
    lw $t4, 0($t1)
    lw $t5, 4($t1)
    sltu $t6, $t5, $t4
    # Condicao for1
    addu $t3, $t3, -1
    addiu $t1, $t1, 4
    bnez $t6, troca
    bnez $t3, for2
    j exit_for1
troca:
    sw $t4, 0($t1)
    sw $t5, -4($t1)
    bnez $t3, for2
exit_for1:
    # Condicao for1
    addu $t2, $t2, -1
    bnez $t2, for1
    
