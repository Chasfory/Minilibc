bits 64
global strchr

section .text

strchr:
    xor rax, rax
    xor r8b, r8b

loop:
    mov r8b, BYTE [rdi]
    cmp r8b, sil
    je end

loop_2:
    cmp r8b, 0
    je end_null
    inc rdi
    jmp loop

end_null:
    ret
end:
    mov rax, rdi
    ret