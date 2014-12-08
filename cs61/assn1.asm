;=================================================
; 
; Name: Sells, Zachary 
; Login id: zsell010    
; 
; Assignment name: <assn 1>
; Lab section: <022>
; TA: Juan Casse
; 
; I hereby certify that the contents of this file
; are ENTIRELY my own original work. 
;
;=================================================

.orig x3000

;----------------
;Instruction
;----------------
LD R0, DEC_5 ;Load label, "DEC_5", into R0 register //Number to be multiplied
LD R1, DEC_8 ;Load label, "DEC_8", into R1 register //Iterator(eg. other number to be multiplied)
LD R2, product ;Load label, "product" into R2 register //Register to put answer(must be cleared)


FOR_LOOP_1
    ADD R2, R0, R2 ;Add R0 to R2 and store it in R2
    ADD R1, R1, #-1 ; Add R1 and -1 and store it in R1. (Reduce iterator)
    BRp FOR_LOOP_1 ; If last used Register is positive, jump to FOR_LOOP_1
END_FOR_LOOP_1
HALT

;------------
;Data
;------------
DEC_5 .fill #5
DEC_8 .fill #8
product .fill #0

;---------------------------------------------------
;REGISTER VALUES R0 R1 R2 R3 R4 R5 R6 R7
;---------------------------------------------------
;Pre-loop        5   8  0  x  x  x  x  x
;Iteration01     5   7  5  x  x  x  x  x
;Iteration02     5   6  10  x  x  x  x  x
;Iteration03     5   5  15  x  x  x  x  x
;Iteration04     5   4  20  x  x  x  x  x
;Iteration05     5   3  25  x  x  x  x  x
;Iteration06     5   2  30  x  x  x  x  x
;Iteration07     5   1  35  x  x  x  x  x
;Iteration08     5   0  40  x  x  x  x  x
;End of program  5   0  40  x  x  x  x  x
;---------------------------------------------------
.end
