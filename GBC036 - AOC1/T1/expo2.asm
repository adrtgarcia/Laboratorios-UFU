# P2 - potenciação, fragmento 1

	.data					# declarar variáveis
x:      .word 	3         			# defina aqui o valor de x (base)
n:      .word 	4         			# defina aqui o valor de n (expoente)
result: .word 	1         			# resultado começa em 1 (fator nulo da multiplicação)

	.text
	.globl expo2
expo2:
    	la	$t0, x				# $t0 recebe o endereço de x
	lw	$a0, 0($t0)			# $a0 recebe o valor apontado por $t0
	la	$t1, n				# $t1 recebe o endereço de n
	lw	$a1, 0($t1)			# $a1 recebe o valor apontado por $t1
	la	$t2, result			# $t2 recebe o endereço de result
	lw	$t2, 0($t2)			# $t2 recebe o valor apontado por $t2

loop:
    	beq 	$t1, $zero, fimloop   		# if (n == 0) saia do loop
    	andi 	$t3, $t1, 1          		# if ($t1 == 1) $t1 tem valor ímpar, $t3 recebe 1
    	bnez 	$t3, impar           		# if ($t3 != 0) jump para ímpar

par:						# n é par, eleva x ao quadrado
   	mul 	$t0, $t0, $t0         		# x *= x
    	srl 	$t1, $t1, 1           		# n /= 2 (deslocamento lógico para a direita)
    	j 	loop				# jump para loop

impar:						# n é ímpar, multiplica result por x e eleva x ao quadrado
  	mul 	$t2, $t2, $t0         		# result *= x
    	mul 	$t0, $t0, $t0         		# x *= x
    	srl 	$t1, $t1, 1           		# n /= 2 (deslocamento lógico para a direita)
    	j 	loop				# jump para loop

fimloop:
    	li 	$v0, 1          	 	# imprime inteiro na tela (syscall)
    	move 	$a0, $t2      			# move o resultado em $t2 para $a0
    	syscall
    
    	li 	$v0, 10          		# encerra o programa (syscall)
    	syscall
