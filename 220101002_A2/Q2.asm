; Abhishek Kumar 
; 16/01/2024

section .data
    file db "input.txt",0
    mode db "r",0
    msg db "Error in opening file!",10,0
    newline db 10,0
    fmt db "%d %d ",0

section .bss
    buffer resb 1024
    fd resd 1
    bytes_read resd 1
    extern printf
    extern fopen
    extern fread
    extern fwrite
    extern fclose
    vis resd 128


section .text
    global main

main:
    push ebp
    mov ebp,esp

    ; open file
    push mode
    push file
    call fopen
    add esp,8

    test eax,eax
    jz open_err

    mov [fd],eax
    
    ; initialise all the vis array to 0
    
    mov edi,vis
    mov ecx,10
    mov eax,0
    rep stosd
    

read:
    push dword[fd]
    push 1024
    push 1
    push buffer
    call fread
    add esp,16

    mov [bytes_read],eax

    test eax,eax
    mov ebx,0
    jz end

    mov ecx,eax
    mov esi,buffer

process:
    mov al,byte[esi]
    mov ebx,[vis + 4*eax]
    add ebx,1
    mov [vis + 4*eax],ebx
    jmp next_char
    
next_char:
    inc esi
    dec ecx
    jnz process
    jmp read

end:
    cmp ebx,128
    jge close_file
    
    
    mov edx,dword[vis + 4*ebx]
    cmp edx,0
    jg out
    
    inc ebx
    jmp end
    

out :
    push edx
    push ebx
    push fmt
    call printf
    pop ecx
    pop ecx
    pop ecx
    
    
    inc ebx
    jmp end

close_file:
    push dword[fd]
    call fclose
    add esp,4

    mov esp,ebp
    pop ebp
    xor eax,eax
    ret

open_err:
    push msg
    call printf
    add esp,4

    mov esp,ebp
    pop ebp
    mov eax,1
    ret
