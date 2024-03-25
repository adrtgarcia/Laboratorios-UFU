# P1 - potenciação, fragmento 2

	.data					# declarar variáveis
x:      .word 	3         			# defina aqui o valor de x (base)
n:      .word 	4         			# defina aqui o valor de n (expoente)
result: .word 	1         			# resultado inicializada como 1 (fator nulo da multiplicação)

	.text
	.globl expo2
expo2:
    	la	$t0, x				# $t0 recebe o endereço de x
	lw	$a0, 0($t0)			# $a0 recebe o valor apontado por $t0
	la	$t1, n				# $t1 recebe o endereço de n
	lw	$a1, 0($t1)			# $a1 recebe o valor apontado por $t1
	la	$t2, result			# $t2 recebe o endereço de result
	lw	$t2, 0($t2)			# $t2 recebe o valor apontado por $t2
expo2:
	la $t0, x				# carrega x
    	lw $t0, x
              
   	la $t1, n				# carrega n
    	lw $t1, n
    
    	la $t2, result				# carrega result
    	lw $t2, result

loop:
    	beq 	$a1, $zero, fimloop   		# if (n == 0) saia do loop
    	andi 	$t3, $a1, 1          		# if ($a1 == 1) $a1 tem valor ímpar, $t3 recebe 1
    	bnez 	$t3, impar           		# if ($t3 != 0) jump para ímpar

loop:
    beq $t1, $zero, fimloop   # Compara se n = 0, se for, termina o loop

    andi $t3, $t1, 1          #Compara bit a bit de t1 com o valor 1. Se forem iguais, retorna 1 em t3, revelando que o numero eh impar
    bnez $t3, impar           # Se n é ímpar,ou seja, t3 é diferente de 0, vá para a parte ímpar


par:						# n é par, eleva x ao quadrado
   	mul 	$a0, $a0, $a0         		# x *= x
    	srl 	$a1, $a1, 1           		# n /= 2 (deslocamento lógico para a direita)
    	j 	loop				# jump para loop

impar:						# n é ímpar, multiplica result por x e eleva x ao quadrado
  	mul 	$a2, $a2, $a0         		# result *= x
    	mul 	$a0, $a0, $a0         		# x *= x
    	srl 	$a1, $a1, 1           		# n /= 2 (deslocamento lógico para a direita)
    	j 	loop				# jump para loop

fimloop:
    	li 	$v0, 1          	 	# imprime inteiro na tela (syscall)
    	move 	$a0, $a2      			# move o resultado em $t2 para $a0
    	syscall
    
    	li 	$v0, 10          		# encerra o programa (syscall)
    	syscall


.data
x:      .word 3         # Defina o valor de x aqui
n:      .word 4         # Defina o valor de n aqui
result: .word 1         # Inicialize result com 1

.text
.globl expo2



par:
    # Se n é par, apenas eleva x ao quadrado, sem realizar result *= x
    mul $t0, $t0, $t0         # x *= x
    srl $t1, $t1, 1           # n /= 2, utilizando o deslocamento lógico para a direita pelo fato da base ser 2
    j loop

impar:
    # Se n é ímpar, multiplica result por x e depois eleva x ao quadrado e atribui n/=2
    mul $t2, $t2, $t0         # result *= x
    mul $t0, $t0, $t0         # x *= x
    srl $t1, $t1, 1           # n /= 2
    j loop

fimloop:
    # Imprime o resultado
    li $v0, 1           # Carrega o código do serviço de impressão inteira
    move $a0, $t2      # Move o resultado para o argumento de impressão
    syscall             # Chama o serviço de impressão
    
    # Finaliza o programa
    li $v0, 10          # Carrega o código do serviço de saída no v0
    syscall             # Chama o syscall
