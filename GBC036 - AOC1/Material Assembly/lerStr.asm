	    .data
msg1:	.asciiz	"Digite uma string: "
msg2:	.asciiz	"String digitada: "
str:	.space	80			                  # declarar str como array de 80 bytes

	    .text
main:
	li  $v0, 4
	la  $a0, msg1
	syscall				                        # imprime a string msg1
	li  $v0, 8			
	la  $a0, str			                    # $a0 <- &str[0] 
	li  $a1, 80			                      # $a1 <- size
	syscall				                        # ler string -> $v0
	li  $v0, 4
	la  $a0, msg2
	syscall				                        # imprime a string msg2
	li  $v0, 4
	la  $a0, str
	syscall				                        # imprime a string str
	li  $v0, 10
	syscall				                        # exit
