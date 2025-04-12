extern printf
extern scanf
section .data
    file db "input.txt",0
    msg db "Error in opening file!",10,0
    newline db 10,0

section .bss
    buffer resb 1024
    fd resd 1
    bytes_read resd 1

section .text
    global main

main:
    push ebp
    mov ebp,esp

    ; open file (sys_open)
    mov eax,5   ; sys_open
    mov ebx,file  ; filename
    mov ecx,0  ; O_RDONLY
    int 0x80

    test eax,eax
    js open_err

    mov [fd],eax

read:
    ; read file (sys_read)
    mov eax,3      ; sys_read
    mov ebx,[fd]  ; file descriptor
    mov ecx,buffer  ; buffer
    mov edx,1024 ; count
    int 0x80

    mov [bytes_read],eax

    test eax,eax
    jz end

    mov ecx,eax
    mov esi,buffer

process:
    mov al,byte[esi]

    cmp al,32
    jb replace
    cmp al,126
    ja check 
    jmp next_char

check:
    cmp al,10    ; newline
    je next_char
    cmp al,9     ; tab
    je next_char

replace:
    mov byte[esi],'*'

next_char:
    inc esi
    dec ecx
    jnz process

    ; write to stdout (sys_write)
    mov eax,4   ;sys_write
    mov ebx,1  ;stdout
    mov ecx,buffer ;buffer
    mov edx,[bytes_read] ;count
    int 0x80

    jmp read

end:
    ; write newline
    mov eax,4  ;sys_write
    mov ebx,1   ;stdout
    mov ecx,newline ; buffer
    mov edx,1  ; count
    int 0x80 

close_file:
    ;close file (sys_close)
    mov eax,6 ;sys_close
    mov ebx,[fd]  ;file descriptor
    int 0x80

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
