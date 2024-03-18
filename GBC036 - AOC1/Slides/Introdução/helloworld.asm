	.data
hello:	.asciiz	"Hello, world!"	# aloca memória para string

	.text
	li	$v0, 4		# configura syscall
	la	$a0, hello	# imprime string
	syscall	
	li	$v0, 10		# sair do programa
	syscall
