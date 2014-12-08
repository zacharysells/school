.text

main:
   la    $a0, STR1   # load a message to be output
   li    $v0, 4      # syscall 4 (print_str)
   syscall           # outputs the string at $a0


   li    $v0, 5      # syscall 5 (read_int)
   syscall           # reads an int into $v0
   
   beq $v0, 0, FIX_FLOAT
   beq $v0, 1, FLOAT_FIX
   j main
   
   

   
   
FIX_FLOAT:  	     	# User has chosen Fixed to Float operation
	la		$a0, STR2
   li    $v0, 4      	
   syscall          	
   li		$v0, 5
   syscall
   move 	$s0, $v0		# register $s0 now holds location to left of binary point
   
   la		$a0, STR3
   li 	$v0, 4
   syscall
   li		$v0, 5
   syscall
   move	$s1, $v0			# register $s1 now holds the int representation of the floating point number
   
   beqz $s1, END_MAN_LOOP
   #addi $s7, $0, 0
   
   #bgtz $s1, POS
   
   #add $t7, $0, 31
   #add $s7, $s7, 1
   #LOOP:
   #	beqz $t7, END_LOOP
   #	addu $s7, $s7, $s7
   #	add $t7, $t7, -1
  # 	j LOOP
  # END_LOOP:
   
  # not $s1, $s1
  # addi $s1, $s1, -1
   
#POS:
   add $t2, $0, 32			# $t2 <= 32
   clz $t1, $s1  				# number of leading zeros -> $t1
   
   not $t1, $t1				# 32 - # of leading 0's
   add $t1, $t1, 1			#	""
   add $t1, $t2, $t1			#	""
   
   not $s0, $s0				# 32 - # of leading 0's - distance from decimal point
   add $s0, $s0, 1			#	""
   add $t1, $t1, $s0			#	""
   
   add $t1, $t1, 126			
   sll $t1, $t1, 23			# register $t1 holds the biased exponent in proper location
   
   clz $t3, $s1
   
   not $t3, $t3
   add $t3, $t3, 1
   add $t3, $t3, $t2
   add $t3, $t3, -1
   
   addu $s2, $0, 1			# register $s2 <= 1
   add $t0, $t3, $0
   MAN_LOOP:
   	beqz $t0, END_MAN_LOOP
   	addu $s2, $s2, $s2
   	add $t0, $t0, -1
   	j MAN_LOOP
   END_MAN_LOOP:
   addu $s2, $s2, -1
   and $s3, $s2, $s1			# register $s3 <= mantisa
   
   clz $t4, $s1
   add $t4, $t4, 1			# add 1 to account for the 1.xxxxxx that is not included when counting leading 0's
   add $t4, $t4, -9			# -9 is the bits required for the sign and the biased exponent
   sllv $s3, $s3, $t4

	
   or $s4, $s3, $t1			#$t1 is the biased exponent
   or $s4, $s4, $s7			#$s7 is the sign bit
   mtc1  $s4, $f12   		# moves integer to floating point register
   li    $v0, 2      		# syscall 2 (print_float)
   syscall           		# outputs the float at $f12
   j main
   
   
   
FLOAT_FIX:

	la		$a0, STR2
   li    $v0, 4      	
   syscall          	
   li		$v0, 5
   syscall
   move 	$s0, $v0			# register $s0 now holds location to left of binary point
   
   la		$a0, STR4
   li 	$v0, 4
   syscall
   
	li    $v0, 6      	
   syscall           	
   
   
   cvt.w.s $f1, $f0
   mfc1 $s1, $f0			# register $s1 now holds the floating point number
   mfc1 $s2, $f1			# register $s2 now holds the integer value of the left hand side
   
   add $t1, $s0, $0
   FOR:
   	beqz $t1, END_FOR
   	sll $s2, $s2, 1
   	add $t1, $t1, -1
   	j FOR
   END_FOR:
	# register $s2 holds the binary representation without the decimal precision 8.25 -> 8
   							
   									
   add $s7, $0, 0
   bgtz $s1, POS		# register $s7 is 0 when $s1 is postive, otherwise $s1 is negative
   
   add $s7, $0, 1
   
POS:
	add $t0, $0, 1
	add $t0, $t0, $t0
	add $t0, $t0, $t0
	add $t0, $t0, $t0
	add $t0, $t0, $t0		
	add $t0, $t0, $t0
	add $t0, $t0, $t0
	add $t0, $t0, $t0
	add $t0, $t0, $t0		
	add $t0, $t0, -1		# register $t0 <- x00000008
	
	sll $t0, $t0, 23
	and $t0, $s1, $t0
	srl $t0, $t0, 23
	
	add $t0, $t0, -127	# register $t0 now holds the exponent
	
	add $t2, $0, 32			# $t2 <= 32
	
	not $t1, $t0
	add $t1, $t1, 1
	add $t2, $t2, $t1
	add $t2, $t2, -9		# register $t2 now holds the number of bits to cut off fromt the right of the binary #
	
	add $t3, $t2, $0
	add $t4, $0, 1
	FOR2:
		beqz $t3, END_FOR2
		addu $t4, $t4, $t4
		add $t3, $t3, -1
		j FOR2
	END_FOR2:
	add $t4, $t4, -1
	
	and $s3, $s1, $t4
	
	not $t5, $s0
	add $t5, $t5, 1
	add $t2, $t2, $t5
	srlv $s3, $s3, $t2
	
	or $s4, $s2, $s3
	#beqz $s7, POS_2
	
	#not $s4, $s4
	#add $s4, $s4, 1
	
POS_2:
	move  $a0, $s4   # moves integer to floating point register
   li    $v0, 1      # syscall 2 (print_float)
   syscall           # outputs the float at $f12
	j main
	


DONE:

.data
 
STR1:
   .asciiz "\nChoose an operation(0 for Fixed to Float, 1 for Float to Fixed):\n"

STR2: 
   .asciiz "Enter the location to the left of the binary point: \n"
   
STR3: 
   .asciiz "Enter an integer representation of a 32-bit floating point number: \n"
   
STR4:
	.asciiz "Enter a floating point number: \n"
   
   

   
