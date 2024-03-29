# P2 - avaliação polinomial
	
	.data 
coef: 	.word 	2, -11, -7, -27, 88 			# vetor de coeficientes 
x: 	.word 	3 					# valor de x 
n: 	.word 	5 					# ordem do polinômio 
result: .word 	0 					# resultado do cálculo 

	.text
	.globl main 

main: 							 
	la 	$a0, coef 				# define registrador para coef
	lw 	$a1, n 					# define registrador para n
	lw 	$a2, x 					# define registrador para x
	jal 	tradicional 				# chama a função tradicional
	sw 	$v0, result 				# move o resultado para $v0
	li 	$v0, 1 
	lw 	$a0, result 				# imprime o resultado (syscall)
	syscall 					
	
	la 	$a0, coef 				# define registrador para coef
	lw 	$a1, n 					# define registrador para n
	lw 	$a2, x 					# define registrador para x 
	jal 	horner					# chama a função horner 
	sw 	$v0, result 				# move o resultado para $v0 
	li 	$v0, 1 
	lw 	$a0, result 				# imprime o resultado (syscall)
	syscall  
	li 	$v0, 10					# encerra o programa (syscall) 
	syscall 

pow: 							# função para calcular a potência
	move 	$v0, $zero 				# $v0 = 0
	beq 	$a1, $zero, fim_pow 			# if (n == 0) encerra o loop
	li 	$v0, 1 					# $v0 = 1

loop_pow: 
	mul 	$v0, $v0, $a0 				# valor em $v0 x coeficiente
	sub 	$a1, $a1, 1 				# n -= 1
	bnez 	$a1, loop_pow 				# if (n != 0) continua o loop

fim_pow: 
	jr 	$ra 					# volta para a main
							# inicializa variáveis para a função tradicional: 
	move 	$t0, $zero 				# resultado = 0
	move 	$t1, $zero 				# contador = 0

loop_trad: 
	beq 	$t1, $a1, fim_trad 			# if (n == contador) encerra o loop
	move 	$a0, $a2 				# base = x ((a0 nn era o coeficiente???)
	sub 	$a1, $a1, $t1 				# expoente = n - contador 
	jal 	pow 					# não faço ideia
	move 	$t2, $v0 				# x^(n-i) 
	lw 	$t3, 0($a0) 				# coef[i] 
	mul 	$t2, $t2, $t3 				# coef[i]*x^(n-i) 
	add 	$t0, $t0, $t2				# resultado += coef[i]*x^(n-i) 
	addiu 	$a0, $a0, 4 				# próximo coeficiente 
	addiu 	$t1, $t1, 1 				# próximo i j 
	loop_trad 					# isso aqui já deixa em loop???
	
fim_trad: 
	move 	$v0, $t0 				# move o resultado para $v0
	jr 	$ra 					# volta pra onde???
							# inicializa variáveis para função horner: 
	lw 	$t0, 0($a0) 				# resultado = coef[0] 
	addiu	$a0, $a0, 4 				# próximo coeficiente 
	li 	$t1, 1 					# contador = 1

loop_horner: 
	beq 	$t1, $a1, fim_horner 
	mul 	$t0, $t0, $a2 				# resultado *= x 
	lw 	$t2, 0($a0) 				# coef[i] 
	add 	$t0, $t0, $t2 				# resultado += coef[i] 
	addiu 	$a0, $a0, 4 				# próximo coeficiente 
	addiu 	$t1, $t1, 1 				# próximo i j 
	loop_horner 

fim_horner: 
	move 	$v0, $t0 				# move o resultado para $v0
	jr 	$ra					# volta pra onde??
