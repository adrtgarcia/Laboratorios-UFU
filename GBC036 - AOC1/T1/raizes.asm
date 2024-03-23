	.include "macros.asm"		# utilizando as funções read_float, print_str

	.data
cte2:	.float	2.0 
cte4: 	.float	4.0

	.text
	.globl main
main:
	read_float($f0)			# lê float do teclado
     	mov.s	$f1, $f0		# $f1 = a
     
     	read_float($f0)			# lê float do teclado
     	mov.s  	$f2, $f0		# $f2 = b
     
     	read_float($f0)			# lê float do teclado
     	mov.s  	$f3, $f0		# $f3 = c
     
     	mtc1   	$zero, $f5		# (fpu) $f5 = 0
     	c.eq.s  0, $f1, $f5		# if (a == 0) ???
     	bc1t  	fim         		# if (a == 0) encerra o programa 
     
     	mul.s   $f0, $f2, $f2   	# b^2
     
     	l.s     $f4, cte4      		# $f4 = 4.0
     
     	mul.s   $f4, $f4, $f1   	# 4 * a
     	mul.s   $f4, $f4, $f3   	# 4 * a * c
     					# delta = b*b - 4*a*c:
     	sub.s   $f0, $f0, $f4   	# $f0 = delta
     
     	c.lt.s 	$f0, $f5   		# Compare $f0 (delta) com 0
     	bc1t complexo     		# Branch para complexo se a condição for verdadeira (delta < 0)
     
     	sqrt.s  $f6,$f0     		#raiz quadrada de delta está em f6
     	sub.s   $f2, $f5, $f2   	#f2 = 0-b, portanto f2 é -b
     
     					#A partir daqui, precisa fazer as comparações para regra da tumba
     
     					#Comparar b^2 > ac e b>0 para utilizar R1 COM forma SEGURA E R2 COM TRADICIONAL
     	mul.s   $f13, $f3, $f1
     	add.s   $f9,$f1,$f1     	#mesma coisa que multiplicar A por 2, em f9 está 2a
     	add.s   $f14,$f3,$f3    	#mesma coisa que multiplicar C por 2, em f14 está 2C
     
     	c.le.s  $f13, $f2   		#ac <= bc
     	bc1t    segundo_metodo
     	j       primeiro_metodo
     
segundo_metodo:
     	add.s   $f7,$f2,$f6     	#-b + raiz de delta
     	div.s   $f16,$f7,$f9    	#coloca em f7 a divisao por 2a, (-b+sqrt(b2-4ac))/2a PORTANTO AQUI ESTÁ R1 COM A FORMA TRADICIONAL
     	div.s   $f15,$f14,$f7   	#coloca em f15: PORTANTO AQUI ESTÁ R2 COM A FORMA SEGURA
     
     	j imprimir_resultado
    
primeiro_metodo:
     	sub.s   $f7,$f2,$f6     	#-b - raiz de delta
     	div.s   $f16,$f14,$f7   	#coloca em f16 a divisão: 2C/-b-delta PORTANTO EM F7 ESTÁ O VALOR DA RAIZ 1 DE FORMA SEGURA
     	div.s   $f15,$f7,$f9    	#coloca em f15 a divisao de f7 e f9
     
imprimir_resultado:
     					# Chamadas de função para imprimir os resultados
     	print_str "x1: "
     	mov.s   $f12, $f16   		# Valor a ser impresso em x1
     	print_float($f12)
     	print_str "\n"

     	print_str "x2: "
     	mov.s   $f12, $f15   		# Valor a ser impresso em x2
     	print_float($f12)
     	print_str "\n"
     	j fim

complexo:
     	abs.s   $f0, $f0
     	sqrt.s  $f6,$f0     		#sqrt(abs(b2-4ac))
     	sub.s   $f2, $f5, $f2
     	add.s   $f9,$f1,$f1     	#2*a
     	div.s   $f7,$f2,$f9     	#(-b)/2a
     	div.s   $f8,$f6,$f9     	#(sqrt(abs(b2-4ac)))/2a
     
     	print_str "x1,2: "
     	mov.s   $f12, $f7   		# Parte real
     	print_float($f12)
     	print_str " +- "
     	mov.s   $f12, $f8   		# Parte imaginária
     	print_float($f12)
     	print_str "i\n"
     
fim:
     	li      $v0, 10     		# exit
     	syscall
