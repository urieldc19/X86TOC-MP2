section .text
global imgCvtGrayIntoFloat

imgCvtGrayIntoFloat:
    ; int size (@ rcx)
    ; const uint8_t* input (@ rdx)
    ; float* output (@ r8)

    ; Save registers
    push rbx

    xor rbx, rbx

    ; Load 255.0 into xmm1
    mov rax, 255
    movq xmm1, rax
    cvtsi2ss xmm1, rax

.loop:
    ; Checker
    cmp rbx, rcx
    jge .end

    ; Load input value
    movzx eax, byte [rdx + rbx]

    ; Convert input value to float and divide by 255.0
    cvtsi2ss xmm0, eax
    divss xmm0, xmm1

    ; Store result in output array
    movss [r8 + rbx * 4], xmm0

    ; Increment ctr
    inc rbx
    jmp .loop

.end:
    pop rbx
    ret