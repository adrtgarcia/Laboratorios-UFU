	.data
msg1:	.asciiz	"Digite uma string: "
msg2:	.asciiz	"String lenght: "
str:	.space	80                        	# declarar str[80]

	.text
main:
	li   $v0, 4
	la   $a0, msg1
	syscall				        # imprime a string msg1
	li   $v0, 8			
	la   $a0, str			        # $a0 <- &str[0] 
	li   $a1, 80			        # $a1 <- size
	syscall				        # ler string -> $v0
	xor  $t2, $t2, $t2
	la   $t0, str

loop:
	lbu  $t1, 0($t0)
	beq  $t1, $zero, fim
	addi $t2, $t2, 1
	addi $t0, $t0, 1
	j    loop

fim:
	li   $v0, 4
	la   $a0, msg2
	syscall				        # imprime a string msg2
	li   $v0, 1
	add  $a0, $zero, $t2
	syscall				        # imprime o tamanho
	li   $v0, 10
	syscall				        # exit
