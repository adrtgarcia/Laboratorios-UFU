	.data						                               # declarando dados
array:		.word	1, 2, 3, 4, 5, 6, 7, 8, 9, 10
n:		    .word	10				                       # tamanho do vetor
soma:		  .word	0				                         # resultado da soma
msg:		  .ascii	"resultado: "

	.text
	.globl main

main:
	addi $t0, $0, 0					                        # i <- 0
	addi $t1, $0, 0					                        # soma <- 0
	la   $t2, n
	lw   $t2, 0($t2)				                        # $t2 <- n
	la   $t3, array					                        # $t3 <- &array[0]

loop:   
	slt  $t4, $t0, $t2				                      # $t4 = (i < n) ? 1 : 0
	beq  $t4, $0, end				                        # se (i >= n) go to end
	sll  $t4, $t0, 2				                        # i * 4
	add  $t4, $t4, $t3				                      # &x[0] + i * 4
	lw   $t4, 0($t4)				                        # $t4 <- array[i]
	add  $t1, $t1, $t4				                      # soma += array[i]
	add  $t0, $t0, 1				                        # i++
	j    loop

end:
	la   $t4, soma
	sw   $t1, 0($t4)
	li   $v0, 10					                          # finalizar programa
	syscall
