bits 64
global strpbrk

section .text

strpbrk:
    xor rax, rax
    xor r10b, r10b
    xor r8b, r8b
    xor rcx, rcx
    mov r8b, BYTE [rdi]
    mov r10b, BYTE [rsi]
    jmp loop

check_second_string:
    mov r10b, BYTE [rsi + rcx]
    cmp r10b, 0
    je loop_2
    cmp r8b, r10b
    je end
    inc rcx
    jmp check_second_string

loop_2:
    inc rdi
    xor rcx, rcx
    mov r8b, BYTE [rdi]
loop:
    cmp r8b, 0
    je end_null
    jmp check_second_string

end_null:
    ret
end:
    mov rax, rdi
    ret