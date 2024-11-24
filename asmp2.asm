section .text
global imgCvtGrayIntoFloat

imgCvtGrayIntoFloat:
    ; int size (in rcx)
    ; const uint8_t* input (in rdx)
    ; float* output (in r8)

    ; Save registers
    push rbx

    ; Initialize loop counter
    xor rbx, rbx

    ; Load 255.0 into xmm1
    mov rax, 0x437f000000000000
    movq xmm1, rax
    cvtsi2ss xmm1, rax

.loop:
    ; Check if we have processed all elements
    cmp rbx, rcx
    jge .end

    ; Load input value into al
    movzx eax, byte [rdx + rbx]

    ; Convert input value to float and divide by 255.0
    cvtsi2ss xmm0, eax
    divss xmm0, xmm1

    ; Store result in output array
    movss [r8 + rbx * 4], xmm0

    ; Increment loop counter
    inc rbx
    jmp .loop

.end:
    pop rbx
    ret