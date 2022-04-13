bits 64
global strlen

section .text
strlen:
    xor rax, rax

loop:
    cmp BYTE [rdi], 0
    je end
    inc rdi
    inc rax
    jmp loop

end:
    ret