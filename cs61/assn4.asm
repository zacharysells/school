;=================================================
; 
; Name: Sells, Zachary 
; Login id: zsell010    
; 
; Assignment name: <assn 4>
; Lab section: <022>
; TA: Juan Casse
; 
; I hereby certify that the contents of this file
; are ENTIRELY my own original work. 
;
;=================================================
;-----------------------------------------------------------
;Labels             ;Instruction                ;Comments
;-------------------------------------------------------
                    .orig x3000
                    
BEGIN               ld R2, DATA_ARRAY_PTR
                    ld R4, DEC_0
                    ld R5, DEC_0
                    ld R1, DEC_0
 
PROMPT_INPUT        ld R0, DEC_10
                    trap x21
                    lea R0, MESSAGE_1
                    puts
                    lea R0, MESSAGE_2
                    puts
                    
SIGN_INPUT          ld R0, DEC_10               ;Newline
                    trap x21
                    trap x20                    ;Get sign from user
                    trap x21
                    
                    add R0, R0, #-15
                    add R0, R0, #-15
                    add R0, R0, #-15
                    add R0, R0, #-12
                    brp BEGIN                   ;Error checking
                    add R0, R0, #15
                    add R0, R0, #15
                    add R0, R0, #15
                    add R0, R0, #12
                    
                    add R0, R0, #-15
                    add R0, R0, #-15
                    add R0, R0, #-12
                    brnz BEGIN                  ;Error checking
                    add R0, R0, #15
                    add R0, R0, #15
                    add R0, R0, #12

                    add R0, R0, #-12
                    add R0, R0, #-12
                    add R0, R0, #-12
                    add R0, R0, #-7
                    
                    brz POSITIVE
                    add R0, R0, #-2
                    brz NEGATIVE

DATA_INPUT          trap x20    
                    trap x21                    ;Get number from user
                    
                    add R0, R0, #-10
                    brz ARRAY_TO_BINARY
                    add R0, R0, #10
                    
                    add R0, R0, #-15
                    add R0, R0, #-15
                    add R0, R0, #-15
                    add R0, R0, #-12
                    brp BEGIN                   ;Error Checking
                    add R0, R0, #15
                    add R0, R0, #15
                    add R0, R0, #15
                    add R0, R0, #12
                    
                    add R0, R0, #-15
                    add R0, R0, #-15
                    add R0, R0, #-12
                    brnz BEGIN                  ;Error checking
                    add R0, R0, #15
                    add R0, R0, #15
                    add R0, R0, #12
                    
                    str R0, R2, #0
                    add R2, R2, #1
                    add R4, R4, #1
                    br  DATA_INPUT
                    
                    halt
                    
                    
;---------------Store user in R1-------------------------                    
ARRAY_TO_BINARY     ld R7, DEC_1
ARRAY_TO_BINARY_RET add R2, R2, #-1

                    ldr R3, R2, #0
                    add R3, R3, #-12
                    add R3, R3, #-12
                    add R3, R3, #-12
                    add R3, R3, #-12
                 
                    st R6, R6_TEMP
                    st R5, R5_TEMP
                    ld R6, DEC_0
                                        
                    add R5, R5, #-1         ;multiply (10)^R5 store it in R7
                    brzp SQUARE_10
MULT_1              ld R6, R6_TEMP
                    ld R5, R5_TEMP
                    
                                            ;mult R7 * R3 --> Store in R3
                    st R7, R7_TEMP
                    br NORM_MULTIPLY
MULT_2              ld R7, R7_TEMP
                    
                    add R1, R1, R3
                    
                    add R5, R5, #1
                    add R4, R4, #-1
                    brp ARRAY_TO_BINARY_RET

                    add R6, R6, #0
                    brp COMPLEMENT_2S
                    halt 
;----------------------------------------------------------



;-----------------Take square of 10------------------------
SQUARE_10           
                    add R7, R7, #0
                    brz SPECIAL_CASE
                    add R6, R7, #0
                    ld R7, DEC_0
SPECIAL_CASE_RET    add R0, R0, #10
SQUARE_10_RET       add R7, R6, R7
                    add R0, R0, #-1
                    brp SQUARE_10_RET
                    br MULT_1

            
SPECIAL_CASE        add R6, R6, #10
                    br SPECIAL_CASE_RET
;----------------------------------------------------------


;----------------------Multiply R3 by R7-------------------                    
NORM_MULTIPLY       st R5, R5_TEMP
                    add R5, R3, #0
                    brz MULT_2
                    ld R3, DEC_0
NORM_MULTIPLY_RET   add R3, R7, R3
                    add R5, R5, #-1
                    brp NORM_MULTIPLY_RET
                    ld R5, R5_TEMP
                    br MULT_2
;----------------------------------------------------------                    


POSITIVE            ld R6, DEC_0
                    lea R0, DATA_INPUT
                    jmp R0

NEGATIVE            ld R6, DEC_1
                    lea R0, DATA_INPUT
                    jmp R0
                    
;----------------------------------------------------------
                    
                    
;-----------------Convert to 2's complement----------------

COMPLEMENT_2S       not R1, R1
                    add R1, R1, #1
                    halt
;----------------------------------------------------------
                    
;-----------------------
;Data
;-----------------------
DEC_0              .fill #0
DEC_1              .fill #1
DEC_10             .fill #10

R7_TEMP            .fill #0
R6_TEMP            .fill #0
R5_TEMP            .fill #0
R3_TEMP            .fill #0
R4_TEMP            .fill #0

DATA_ARRAY_PTR     .fill x4000

MESSAGE_1          .stringz "Input a decimal number(max 5 digits), "
MESSAGE_2          .stringz "preceded with +/- followed by ENTER"

                   .orig x4000
DATA_ARRAY         .blkw #5
                    
                   .end
