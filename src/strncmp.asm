bits 64
global strncmp

section .text

strncmp:
    xor r8b, r8b
    xor r10b, r10b
    xor rcx, rcx
    xor rax, rax
loop:
    mov r8b, BYTE [rdi + rcx]
    mov r10b, BYTE [rsi + rcx]
    cmp rcx, rdx
    je number_null
    cmp r8b, 0
    je sub_number
    cmp r10b, 0
    je sub_number
    cmp r8b, r10b
    jne sub_number
    inc rcx
    jmp loop

number_null:
    mov rax, 0
    jmp end
sub_number:
    movsx rcx, r10b
    movsx rax, r8b
    sub rax, rcx
end:
    ret