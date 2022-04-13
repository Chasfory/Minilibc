bits 64
global strcspn

section .text

strcspn:
    xor rcx, rcx
    xor r11, r11
    xor r10b, r10b
    xor r8b, r8b
    cmp BYTE [rdi], 0
    je end
    cmp BYTE [rsi], 0
    je end_finish
    jmp main_loop

sub_loop:
    mov r8b, BYTE [rdi + rcx]
    mov r10b, BYTE [rsi + rax]
    cmp r10b, 0
    je agrement_rcx
    cmp r8b, r10b
    je end
    jmp agrement
agrement:
    inc rax
    jmp sub_loop

agrement_rcx:
    inc rcx

main_loop:
    mov r11, rcx
    xor rax, rax
    mov r8b, BYTE [rdi + rcx]
    mov r10b, BYTE [rsi + rax]
    cmp r8b, 0
    je end
    cmp r8b, r10b
    je end
    jmp agrement
end_finish:
    cmp BYTE [rdi], 0
    je end
    inc r11
    inc rdi
    jmp end_finish
end:
    mov rax, r11
    ret