	.data
f:	.word
g:	.word
y:	.word

	.text
	.globl main
main:	
	addi	$sp, $sp, -4	# stack frame
	sw	$ra, 0($sp)	# store $ra
	addi	$a0, $0, 2	# $a0 = 2
	sw	$a0, f		# f = 2
	addi	$a1, $0, 3	# $a1 = 3
	sw	$a1, g		# g = 3
	jal	sum		# call sum
	sw	$v0, y		# y = sum( )
	lw	$ra, 0($sp)	# restore $ra
	addi	$sp, $sp, 4	# restore $sp
	jr	$ra		# return to OS
	
sum:
	add	$v0, $a0, $a1	# $v0 = a + b
	jr	$ra		# return
