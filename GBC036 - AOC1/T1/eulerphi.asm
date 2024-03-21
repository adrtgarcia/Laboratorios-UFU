.data
    n: .word 100  # Valor de entrada
    result: .word 0  # Resultado da função phi
    msg: .asciiz "O resultado é: "

.text
.globl main
main:
    la $t0, n  # Carrega o endereço de n em $t0
    lw $a0, 0($t0)  # Carrega o valor de n em $a0
    addi $t1, $zero, 1  # Inicializa o contador
    addi $t2, $zero, 0  # Inicializa o resultado

loop:
    beq $t1, $a0, fim  # Se o contador for igual a n, termina o loop
    jal mdc  # Chama a função gcd
    beq $v0, 1, incrementar  # Se gcd(n, i) for 1, incrementa o resultado
    addi $t1, $t1, 1  # Incrementa o contador
    j loop

incrementar:
    addi $t2, $t2, 1  # Incrementa o resultado
    addi $t1, $t1, 1  # Incrementa o contador
    j loop

fim:
    la $t0, result  # Carrega o endereço de result em $t0
    sw $t2, 0($t0)  # Armazena o resultado em result

    # Imprime a mensagem
    la $a0, msg
    li $v0, 4
    syscall

    # Imprime o resultado
    move $a0, $t2
    li $v0, 1
    syscall

    j exit

mdc:
    add $t3, $a0, $zero  # Copia n para $t3
    add $t4, $t1, $zero  # Copia i para $t4

mdc_loop:
    beq $t4, $zero, mdc_end  # Se i for 0, termina o loop
    add $t5, $t3, $zero  # Copia n para $t5
    rem $t5, $t5, $t4  # Calcula n mod i
    add $t3, $t4, $zero  # Copia i para n
    add $t4, $t5, $zero  # Copia n mod i para i
    j mdc_loop

mdc_end:
    add $v0, $t3, $zero  # Retorna n
    jr $ra

exit:
    li $v0, 10  # Código de saída
    syscall
