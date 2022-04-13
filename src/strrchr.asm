bits 64
global strrchr

section .text

strrchr:
    mov rax, rdi

loop_start:
    cmp BYTE [rdi], 0
    je loop
    inc rdi
    jmp loop_start
loop:
    cmp BYTE [rdi], sil
    je end
    cmp rax, rdi
    je end_null
    dec rdi
    jmp loop

end_null:
    mov rax, 0
    ret
end:
    mov rax, rdi
    ret