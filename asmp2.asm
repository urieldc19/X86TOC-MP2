section .text
bits 64
default rel
global imgCvtGrayIntoFloat

imgCvtGrayIntoFloat:
    ; int size (@ rcx)
    ; const uint8_t* input (@ rdx)
    ; float* output (@ r8)

    ; Save registers
    push rbx

    ; Initialize loop counter
    xor rbx, rbx ; int i = 0;

    ; Load 255.0 into xmm1
    mov rax, 255
    movq xmm1, rax ; float divisor = 255.0f;
    cvtsi2ss xmm1, rax ; Convert integer 255 to float and store in xmm1

L1:
    cmp rbx, rcx ; if (i >= size)
    jge END ; jump to end if condition met

    ; Load input value into eax (pixel value)
    movzx eax, byte [rdx + rbx]

    ; Convert input value to float
    cvtsi2ss xmm0, eax

    ; Divide by 255.0
    divss xmm0, xmm1

    ; Store result in output array
    movss [r8 + rbx * 4], xmm0

    inc rbx ; i++;

    jmp L1

END:
    ; Restore registers and return
    pop rbx
    ret
