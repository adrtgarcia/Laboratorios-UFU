# Autor:	Cláudio C. Rodrigues
# Data:	28/03/2023
# Descrição: Este algoritmo soma dois valores digitados pelo usuário --> a + b --> c

	.data
a: 	.word	0	
b1: 	.word	0
c: 	.word	0
msg1:	.asciiz	"Digite a: " 
msg2:	.asciiz	"Digite b: " 
msg3:	.asciiz	"Soma = "
	.text
	.globl main
main:
	li	$v0, 4
	la	$a0, msg1		
	syscall			# imprimir a msg1
	li	$v0, 5		
	syscall			# ler o valor de a
	sw	$v0, a		# armazenar o valor de a na memória
	
	li	$v0, 4
	la	$a0, msg2		
	syscall			# imprimir a msg2
	li	$v0, 5		
	syscall			# ler o valor de b
	sw	$v0, b1		# armazenar o valor de b na memória
	
	lw	$a0, a
	lw	$a1, b1	
	jal	sum 			# chamar a função sum(a,b)
	sw	$v0, c 		
	move	$t0, $v0
	
	li	$v0, 4
	la	$a0, msg3
	syscall			# imprimir a msg3
	li	$v0, 1
	move	$a0, $t0
	syscall			# imprimir o resultado da soma
	
	li	$v0, 10		# terminar o programa
	syscall

sum:
	add 	$v0, $a0, $a1 	# $v0 = a + b
	jr	$ra 			# return
