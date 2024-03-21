	.data  
A:	.word	0:256		        # A[16][16] words
lin:	.word	16
col:	.word	16

	.text
	lw	$t0, lin	        # $t0 = número de linhas
	lw	$t1, col	        # $t1 = número de colunas
	move	$s0, $zero      	# i <- 0
	move	$s1, $zero      	# j <- 0
	move	$t2, $zero      	# $t2 = valor
	
loop:    
	mult	$s0, $t1	        # $s2 = i * colunas
	mflo	$s2
	add	$s2, $s2, $s1	        # $s2 += j
	sll	$s2, $s2, 2	        # $s2 *= 4
	sw	$t2, A($s2)	        # A[i][j] <- valor
	addi	$t2, $t2, 1	        # valor++
	
	addi	$s1, $s1, 1	        # j <- j + 1
	bne	$s1, $t1, loop    	# if (j < colunas)
    	move	$s1, $zero	        # j <- 0
    	addi	$s0, $s0, 1      	# i <- i + 1
    	bne	$s0, $t0, loop	        # if (i < linhas)
    	
    	li	$v0, 10		        # exit
    	syscall
