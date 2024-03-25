	.include "macros.asm"						# utilizando a fun��o print_str 
	
	.data								# declarando as vari�veis
M:  	.word 	16, 3, 2, 13, 5, 10, 11, 8, 9, 6, 7, 12, 4, 15, 14, 1  	# defina aqui os elementos da matriz quadrada nxn
n:  	.word 	4    							# defina aqui a dimens�o da matriz quadrada

	.text
	.globl main
main:
    	la 	$t0, M      						# endere�o base da matriz
    	lw 	$t1, n      						# carrega a dimens�o n
    									
    	li 	$t2, 0      						# soma1
    	li 	$t3, 0      						# soma2
    	li 	$t4, 0      						# soma3
    	li 	$t5, 1      						# magico (1 = true, 0 = false)
    									
    	li 	$t6, 0      						# i
  
diagonalPrincipal:							# soma da diagonal principal:
    	mul 	$t7, $t6, $t1    					# $t7 = i * n (calcula o deslocamento da matriz)
    	add 	$t7, $t7, $t6     					# $t7 += $t6 (acessa a posi��o na matriz)
   	sll 	$t7, $t7, 2       					# deslocamento l�gico � esquerda
   	add 	$t7, $t0, $t7     					# calcula o endere�o de M[i][i]
   	lw 	$t8, ($t7)         					# carrega o valor de M[i][i]
  	add 	$t2, $t2, $t8     					# soma1 += M[i][i]
  	addi 	$t6, $t6, 1      					# i++
   	blt 	$t6, $t1, diagonalPrincipal				# if (i < n) volta ao come�o do loop da diagonal principal

   	li 	$t6, 0      						# i = 0

diagonalSecundaria:							# soma da diagonal secund�ria:
    	sub 	$t9, $t1, 1       					# $t9 = n - 1 (pr�xima posi��o de i)
    	mul 	$t7, $t6, $t1    					# $t7 = i * n (calcula o deslocamento da matriz)
    	add 	$t7, $t7, $t9     					# $t7 = (n - 1) + (i * n) (acesso a posi��o na matriz)
    	sll 	$t7, $t7, 2       					# deslocamento l�gico � esquerda
    	add 	$t7, $t0, $t7     					# calcula o endere�o de M[i][n-1-i]
    	lw 	$t8, 0($t7)         					# carrega o valor de M[i][n-1-i]
    	add 	$t3, $t3, $t8    					# soma2 += M[i][n-1-i]
    	addi 	$t6, $t6, 1      					# i++
   	blt 	$t6, $t1, diagonalSecundaria				# if (i < n) volta ao come�o do loop da diagonal secund�ria
    									
    	bne 	$t2, $t3, falseMagico					# if (soma1 != soma2) encerra o programa
    									
    	li 	$t6, 0      						# i = 0

verificacao:
    	li 	$t3, 0      						# soma2 = 0
    	li 	$t4, 0      						# soma3 = 0
    	li 	$t7, 0      						# j = 0
    	
somas:
   	mul 	$t8, $t6, $t1    					# $t8 = i * n
    	add 	$t8, $t8, $t7     					# $t8 += j
    	sll 	$t8, $t8, 2      					# deslocamento l�gico � esquerda
    	add 	$t8, $t0, $t8     					# calcula o endere�o de M[i][j]
    	lw 	$t9, 0($t8)         					# carrega o valor de M[i][j]
    	add 	$t3, $t3, $t9     					# soma2 += M[i][j]

    	mul 	$t9, $t7, $t1    					# $t9 = j * n
    	add 	$t9, $t9, $t6						# $t9 += i
    	sll 	$t9, $t9, 2       					# deslocamento l�gico � esquerda
    	add 	$t9, $t0, $t9     					# calcula o endere�o de M[j][i]
    	lw 	$t8, 0($t9)         					# carrega o valor de M[j][i]
    	add 	$t4, $t4, $t8     					# soma3 += M[j][i]

    	addi 	$t7, $t7, 1      					# j++
    	blt 	$t7, $t1, somas						# if (j < n) volta ao come�o do loop das somas

    	bne 	$t3, $t4, falseMagico					# if (soma2 != soma3) encerra o programa
	bne	$t2, $t3, falseMagico					# if (soma1 != soma2) encerra o programa

    	addi 	$t6, $t6, 1      					# i++
    	blt 	$t6, $t1, verificacao					# if (i < n) volta ao come�o do loop da verificacao
    	
    	j	trueMagico						# passou por todos os testes, � m�gico
    
falseMagico:	
	print_str("nao eh um quadrado magico")				# m�gico = 0 (false)
	li	$v0, 10							# finalizar programa (syscall)
	syscall

trueMagico:
	print_str("eh um quadrado magico")				# m�gico = 1 (true)
	li	$v0, 10							# finalizar programa (syscall)
    	syscall