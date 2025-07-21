extern printf

section .data
    msg1 db "Cycle found!",10,0
    msg2 db "No cycle!",10,0
    node dd 4

    adjMat dd 0,1,0,0,
        dd 1,0,1,0,
        dd 0,1,0,1,
        dd 0,0,1,0

section .bss
    vis resd 10

section .text
    global main

main:
    push ebp
    mov ebp,esp

    mov edi,vis
    mov ecx,10
    mov eax,0
    rep stosd

    push -1,
    push 0
    call findCycle
    pop ecx
    pop ecx
    
    cmp eax,1
    je foundCycle 
    
    push msg2  
    call printf
    pop ecx
    jmp exit

foundCycle:
    push msg1
    call printf
    pop ecx
    jmp exit

exit:
    mov esp, ebp
    pop ebp
    xor eax, eax
    ret

findCycle:
    push ebp
    mov ebp,esp
    push ebx
    push esi
    push edi

    mov esi,[ebp+8]
    mov edi,[ebp+12]
    mov dword[vis+esi*4],1

    xor ebx, ebx
    jmp checkNei

checkNei:
    cmp ebx,4
    jge noCycle

    mov eax,esi
    imul eax,4
    add eax,ebx

    cmp dword[adjMat+eax*4],0
    je nextNei

    cmp ebx,edi
    je nextNei

    mov eax,[vis+ebx*4]
    cmp eax,1
    je funRet

    push esi
    push ebx
    call findCycle
    pop ecx
    pop ecx

    cmp eax,1
    je funRet

nextNei:
    inc ebx
    jmp checkNei

noCycle:
    xor eax,eax
    jmp funRet

funRet:
    pop edi
    pop esi
    pop ebx
    mov esp,ebp
    pop ebp
    ret

