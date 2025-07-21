extern printf 
extern scanf

section .data
    msg db "Enter num of row : ",0
    format db "%d",0
    space db ' ',0
    star db '*',0
    newline db 10,0

section .bss
    row resd 1
    counter resd 1

section .text
    global main

main:
    push ebp
    mov ebp,esp

    push msg
    call printf
    add esp,4

    push row
    push format
    call scanf
    add esp,8

    mov dword[counter],1

loop:
    mov eax,[counter]
    cmp eax,[row]
    jg exit

    mov ecx,1

print_space:
    cmp ecx,[counter]
    jge print_star1

    push ecx

    push space
    call printf
    add esp,4

    pop ecx
    inc ecx
    jmp print_space

print_star1:
    mov eax,[row]
    sub eax,[counter]
    mov ebx,2
    mul ebx
    inc eax
    mov ecx,eax

print_star2:
    test ecx,ecx
    jz print_newline

    push ecx

    push star
    call printf
    add esp,4

    pop ecx
    dec ecx
    jmp print_star2

print_newline:
    push newline
    call printf
    add esp,4

    inc dword[counter]
    jmp loop

exit:
    mov esp,ebp
    pop ebp
    xor eax,eax
    ret