bits 64
global memcpy

section .text
memcpy:
    xor rcx, rcx
    xor r8b, r8b
    mov rax, rdi
loop:
    cmp rcx, rdx
    je end
    mov r8b, BYTE [rsi]
    mov BYTE [rdi], r8b
    inc rsi
    inc rdi
    inc rcx
    jmp loop
end:
    ret