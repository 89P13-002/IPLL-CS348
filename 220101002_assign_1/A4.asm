extern printf
extern scanf

section .data 
    msg1 db "Enter 1st num : ",0
    msg2 db "Enter 2nd num : ",0
    msg3 db "Result : %f ",10,0
    msg4 db "Error : Div by 0!",10,0
    msg5 db "Invalid choice "
    menu db "Enter choice :",10
        db "1.Add",10
        db "2.Sub",10 
        db "3.Mult",10
        db "4.Div",10,0
    fmt1 db "%f",0
    fmt2 db "%d",0

section .bss
    num1 resd 1
    num2 resd 1
    choice resb 1
    res resd 1

section .text
    global main

main:
    push ebp
    mov ebp,esp

    push msg1
    call printf
    pop ecx

    push num1
    push fmt1
    call scanf
    pop ecx
    pop ecx

    push msg2
    call printf
    pop ecx

    push num2
    push fmt1
    call scanf
    pop ecx
    pop ecx

    push menu
    call printf
    pop ecx

    push choice
    push fmt2
    call scanf
    pop ecx
    pop ecx

    movss xmm0,[num1]
    movss xmm1,[num2]
    mov eax,[choice]

    cmp eax,1
    je add

    cmp eax,2
    je sub

    cmp eax,3
    je mult

    cmp eax,4
    je div

    push msg5
    call printf
    pop ecx
    jmp exit


add:
    addss xmm0,xmm1
    jmp print_res

sub:
    subss xmm0,xmm1
    jmp print_res

mult: 
    mulss xmm0,xmm1
    jmp print_res

div:
    xorps xmm2,xmm2
    ucomiss xmm1,xmm2
    je error

    divss xmm0,xmm1
    jmp print_res


error:
    push msg4
    call printf
    pop eax
    jmp exit

print_res:
    movss [res],xmm0
    fld dword[res]
    sub esp,8
    fstp qword[esp]
    push msg3
    call printf
    pop ecx
    add esp,8
    jmp exit

exit:
    mov esp,ebp
    pop ebp
    mov eax,1
    mov ebx,0
    int 0x80