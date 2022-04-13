bits 64
global strcasecmp

section .text

strcasecmp:
    xor rcx, rcx
    xor rax, rax
    xor rbx, rbx
    xor r8b, r8b
    xor r10b, r10b
loop:
    mov r8b, BYTE [rdi + rcx]
    mov r10b, BYTE [rsi + rcx]
    cmp r8b, 0
    je result
    cmp r10b, 0
    je result
    cmp r8b, 122
    jle check_maj_r8b

loop_min_r8b:
    sub r8b, 32
    jmp check_maj_r10b

loop_min_r10b:
    sub r10b, 32
    jmp check_nbr

check_nbr:
    cmp r8b, r10b
    jne result
    inc rcx
    jmp loop
check_maj_r10b_bis:
    cmp r10b, 97
    jge loop_min_r10b
    jmp check_nbr

check_maj_r10b:
    cmp r10b, 122
    jle check_maj_r10b_bis

check_maj_r8b:
    cmp r8b, 97
    jge loop_min_r8b
    jmp check_maj_r10b

result:
    sub r8b, r10b
    movsx rax, r8b
end:
    ret