bits 64
global memmove

section .text

memmove:
    mov rax, rdi
    xor rcx, rcx
    xor r8b, r8b
    cmp rdi, rsi
    je end
    jg loop_bis
loop:
    cmp rcx, rdx
    je end
    mov r8b, BYTE [rsi + rcx]
    mov BYTE [rdi + rcx], r8b
    inc rcx
    jmp loop

loop_bis:
    cmp rdx, 0
    je end
    mov r8b, BYTE [rsi + rdx]
    mov BYTE [rdi + rdx], r8b
    dec rdx
    jmp loop_bis
end:
    ret