bits 64
global strstr

section .text

strstr:
    xor rcx, rcx
    xor r11, r11
    xor r10b, r10b
    xor r8b, r8b
    cmp BYTE [rsi], 0
    je end_finish
    jmp main_loop

sub_loop:
    mov r8b, BYTE [rdi + rcx]
    mov r10b, BYTE [rsi + rax]
    cmp r10b, 0
    je end
    cmp r8b, r10b
    je agrement
    jmp main_loop
agrement:
    inc rcx
    inc rax
    jmp sub_loop

main_loop:
    mov r11, rcx
    xor rax, rax
    mov r8b, BYTE [rdi + rcx]
    mov r10b, BYTE [rsi + rax]
    cmp r8b, 0
    je end_null
    cmp r8b, r10b
    je agrement
    inc rcx
    jmp main_loop
end_finish:
    mov rax, rdi
    ret
end_null:
    mov rax, 0
    ret
end:
    add rdi, r11
    mov rax, rdi
    ret