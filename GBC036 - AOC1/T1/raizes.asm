		.data
buffer: 	.space	32
a:  		.float
b:  		.float
c:  		.float
cte2: 		.float 	2.0 
cte4: 		.float 	4.0
str_x1: 	.asciiz "x1: "
str_x2: 	.asciiz "x2: "
str_newline: 	.asciiz "\n"
str_complex: 	.asciiz "x1,2: "
str_plusminus: 	.asciiz " +- "
str_i: 		.asciiz "i\n"

		.text
		.globl main

readFloat:
    li 	$v0, 8
    la 	$a0, buffer
    li 	$a1, 32
    syscall
    
    l.s $f0, 0($a0)
    #jr  $ra

printFloat:
    # Carrega o valor de ponto flutuante de $f12 para a syscall 2 (imprimir float)
    li 	$v0, 2  
    syscall
    #jr 	$ra

printStr:
    # Carrega o valor do ponteiro da string ($a0) para a syscall 4 (imprimir string)
    li 	$v0, 4
    syscall
    #jr 	$ra

main:
     jal 	readFloat
     mov.s 	$f1, $f0
     
     jal 	readFloat
     mov.s 	$f2, $f0
     
     jal 	readFloat
     mov.s 	$f3, $f0
     
     mtc1 	$zero, $f5
     c.eq.s 	0, $f1, $f5
     bc1t 	fim 		#se A for = 0, o programa encerra 
     
     mul.s 	$f0, $f2, $f2 	#b^2
     
     l.s 	$f4, cte4 	#coloca a constante 4 no registrador f4
     
     mul.s 	$f4, $f4, $f1 	#4 * a
     mul.s 	$f4, $f4, $f3 	#4 * a * c
     
     sub.s 	$f0, $f0, $f4 	#DELTA = b*b -4*a*c
     
     c.lt.s 	1, $f0, $f5
     bc1t 	1, complexo 	#se delta for abaixo de 0, é complexo
     
     sqrt.s 	$f6,$f0
     sub.s 	$f2, $f5, $f2 	#f2 = 0-b
     
     add.s 	$f7,$f2,$f6 	#-b + raiz de delta
     sub.s 	$f8,$f2,$f6 	#-b - raiz de delta
     
     add.s 	$f9,$f1,$f1 	#mesma coisa que multiplicar a por 2
     
     div.s 	$f7,$f7,$f9 	#coloca em f7 a divisao por 2a, (-b+sqrt(b2-4ac))/2a 
     div.s 	$f8,$f8,$f9 	#coloca em f8 a divisao por 2a, #(-b-sqrt(b2-4ac))/2a

    				# Chamadas de função para imprimir os resultados
     la 	$a0, str_x1
     jal 	printStr
     mov.s 	$f12, $f7  	# Valor a ser impresso em x1
     jal 	printFloat
     la 	$a0, str_newline
     jal 	printStr

     la 	$a0, str_x2
     jal 	printStr
     mov.s 	$f12, $f8  	# Valor a ser impresso em x2
     jal 	printFloat
     la 	$a0, str_newline
     jal 	printStr
    
     j 		fim
      
complexo:
	abs.s 	$f0, $f0
	sqrt.s 	$f6,$f0 		#sqrt(abs(b2-4ac))
	sub.s	$f2, $f5, $f2
	add.s	$f9,$f1,$f1 		#2*a
	div.s	$f7,$f2,$f9 		#(-b)/2a
	div.s	$f8,$f6,$f9 		#(sqrt(abs(b2-4ac)))/2a

	la 	$a0, str_complex
	jal 	printStr
	mov.s 	$f12, $f7  		# Parte real
	jal 	printFloat
	la 	$a0, str_plusminus
	jal 	printStr
	mov.s 	$f12, $f8  		# Parte imaginária
	jal 	printFloat
	la 	$a0, str_i
	jal 	printStr
     
fim:
    	li 	$v0, 10 		# exit
    	syscall
