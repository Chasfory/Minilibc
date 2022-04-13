bits 64
global strcmp

section .text

strcmp:
    xor rax, rax
    xor rcx, rcx
    xor r8b, r8b
    xor r10b, r10b
loop:
    mov r8b, BYTE [rdi + rcx]
    mov r10b, BYTE [rsi + rcx]
    cmp r8b, 0
    je sub_number
    cmp r10b, 0
    je sub_number
    cmp r8b, r10b
    jne sub_number
    inc rcx
    jmp loop

sub_number:
    movsx rcx, r10b
    movsx rax, r8b
    sub rax, rcx
end:
    ret