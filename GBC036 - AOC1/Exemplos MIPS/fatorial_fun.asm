# void main ( void ) { // fatorial iterativo
# int  i , j ;
	.data 		# area de dados
n : 	.word 	5 	# aloca espaco para variaveis globais
x:	.word	5
y:	.word	3

resp : 	.asciiz	"!  =  " 	# constant e tipo string
elev: 	.asciiz	"^" 		# constant e tipo string
igual: 	.asciiz	" = " 		# constant e tipo string
newl:	.asciiz "\n"
	.text 		# area de codigo
	.globl	main 	# define main como nome global
main:

	lw	$s1, n
	addi	$a0, $s1, 0
	jal	fatorial
	addi	$s2, $v0, 0

	addi 	$v0 , $zero , 1 	# imprime inteiro
	addu 	$a0 , $zero , $s1 	# s y s c a l l ( 1 ) = imprime inteiro
	syscall

	addi 	$v0 , $zero , 4 	# imprime resposta
	la 	$a0 , resp		# s y s c a l l ( 4 ) = imprime string
	syscall

	addi 	$v0 , $zero , 1 	# imprime inteiro
	addu 	$a0 , $zero , $s2 	# s y s c a l l ( 1 ) = imprime inteiro
	syscall
	addi 	$v0 , $zero , 4 	# imprime resposta
	la 	$a0 , newl		# s y s c a l l ( 4 ) = imprime string
	syscall

	lw	$s1, x
	lw	$s2, y
	addi	$a0, $s1, 0
	addi	$a1, $s2, 0
	jal	potencia
	addi	$s3, $v0, 0

	addi 	$v0 , $zero , 1 	# imprime inteiro
	addu 	$a0 , $zero , $s1 	# s y s c a l l ( 1 ) = imprime inteiro
	syscall

	addi 	$v0 , $zero , 4 	# imprime resposta
	la 	$a0 , elev		# s y s c a l l ( 4 ) = imprime string
	syscall
	addi 	$v0 , $zero , 1 	# imprime inteiro

	addu 	$a0 , $zero , $s2 	# s y s c a l l ( 1 ) = imprime inteiro
	syscall

	addi 	$v0 , $zero , 4 	# imprime resposta
	la 	$a0 , igual		# s y s c a l l ( 4 ) = imprime string
	syscall

	addi 	$v0 , $zero , 1 	# imprime inteiro
	addu 	$a0 , $zero , $s3 	# s y s c a l l ( 1 ) = imprime inteiro
	syscall

	addi 	$v0 , $zero , 4 	# imprime resposta
	la 	$a0 , newl		# s y s c a l l ( 4 ) = imprime string
	syscall



	# return ( 0 ) ;
	li 	$v0 , 10 		# termina programa
	syscall 			# s y s c a l l (10) = termina rograma

# }		
fatorial:
	addi $t2, $a0, 1		# $t2 = n+1
	# j=1;
	addi 	$t1 , $zero , 1

	# for ( i=1; i <= n ; i++)
	addi 	$t4 , $zero , 1

for : slt	$t7 , $t4 , $t2 	# i < n - fat( 5 )
	beq 	$t7 , $zero , fimfor

	# j = j * i ;
	mult	$t1 , $t4
	mflo 	$t1

	addi 	$t4 , $t4 , 1

	j	for
	
fimfor : add	$v0, $t1, $zero
	jr 	$ra

potencia:
	addi $t1, $a0, 0		# $t1 = x
	addi $t2, $a1, 0		# $t2 = y+1
	# j=x;
	addi $t3, $t1, 0
	# for ( i=1; i <= y ; i++)
	addi 	$t4 , $zero , 1

L1 : 	slt	$t7 , $t4 , $t2 	# i < y - 
	beq 	$t7 , $zero , fimL1

	# j = j * i ;
	mult	$t3 , $t1
	mflo 	$t3

	addi 	$t4 , $t4 , 1

	j	L1
	
fimL1 : add	$v0, $t3, $zero
	jr 	$ra

