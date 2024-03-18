	.data						           # declarando dados
array:		  .word	1, 2, 3, 4, 5, 6, 7, 8, 9, 10
n:		  .word	10				           # tamanho do vetor
soma:		  .word	0				           # resultado da soma
msg:		  .ascii	"resultado: "

	.text
	.globl main
main:
	xor  $t0, $0, $t0					   # i <- 0
	xor  $t1, $t1, $t1					   # soma <- 0
	la   $t2, n
	lw   $t2, 0($t2)				           # $t2 <- n
	la   $t3, array					           # $t3 <- &array[0]

loop:   
	slt    $t4, $t0, $t2				           # $t4 = (i < n) ? 1 : 0
	beq    $t4, $zero, end				           # se (i < n) faça
	lw     $t4, 0($t3)				           # $t4 <- v[i]
	add    $t1, $t1, $t4				           # soma += v[i]
	addiu  $t3, $t3, 4				           # apontador do vetor
	addiu  $t, $t0, 1				           # i++
	j      loop

end:
	la   $t4, soma
	sw   $t1, 0($t4)
	li   $v0, 10					           # finalizar programa
	syscall
