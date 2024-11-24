section .text
bits 64
default rel
global imgCvtGrayIntoFloat

imgCvtGrayIntoFloat:
    MOV RAX, 255                ; Initialize RAX with 255
    CVTSI2SS XMM0, RAX          ; Convert RAX to float and store to XMM0
    
    L1:
        MOVZX RAX, byte [RDX]   ; Move the current integer to RAX
        CVTSI2SS XMM1, RAX      ; COnvert RAX to float and store to XMM1
        DIVSS XMM1, XMM0        ; Divide XMM1 (current integer) by XMM0 (255)
        MOVSS [R8], XMM1        ; Store the result to R8 (output array)
        
        ADD RDX, 1              ; Move to the next integer input
        ADD R8, 4               ; Move to the next output location
        
        loop L1                 ; Loop until RCX is zero
        
    ret