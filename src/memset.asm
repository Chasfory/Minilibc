bits 64
global memset

section .text

memset:
    mov rax, rdi
    xor rcx, rcx
loop:
    cmp rcx, rdx
    je end
    mov BYTE [rdi], sil
    inc rdi
    inc rcx
    jmp loop
end:
    ret