section .data
    msg1 db "Input format be as follows ",10,0
    msg2 db "Operation MEM_address Val(if needed)",10,0
    msg3 db "1.Read 2.Write 3.Exit",10,0 
    msg4 db "Invalid choice ",10,0
    msg5 db "Cache hit : ",0
    msg6 db "Cache miss",10,0
    msg7 db "Need eviction",10,0
    newline db 10,0
    fmt db "%d",0

section .bss
    cache resd 13   ; for cache
    values resd 13  ; store val 

    address resd 1 
    operat resd 1  ; current operation to be done
    remm resd 1   ; remainder
    val resd 1   ; val to be written

section .text 
    extern scanf
    extern printf
    global main

main:
    push ebp
    mov ebp,esp

    ; INITIALISE    both the array cache and values with initial val
    mov edi,cache
    mov ecx,13
    mov eax,-1
    rep stosd

    mov edi,values
    mov ecx,13
    mov eax,1
    rep stosd

    ; console few instruction
    push msg1
    call printf
    pop ecx

    push msg2
    call printf
    pop ecx

    push msg3
    call printf
    pop ecx

take_input:

    ; based on the operation choosen switch to diff cases
    push operat
    push fmt
    call scanf
    pop ecx
    pop ecx

    mov eax,[operat]
    cmp eax,1
    je read

    cmp eax,2
    je write

    cmp eax,3
    je exit

    push msg4
    call printf
    pop ecx
    jmp exit


; if op == read
read:
    push address
    push fmt
    call scanf
    pop ecx
    pop ecx

    ; do modulo operation and get the cache line (rem is in edx reg)
    xor edx,edx
    mov eax,[address]
    mov ebx,13

    div ebx
    mov [remm],edx 
     
    ; check for cache hit
    mov edx,[remm]
    mov eax,dword[cache + edx*4]
    mov ebx,[address]
    cmp eax,ebx
    je hit

    ; if there is conflict (two mem address to same location)
    mov edx,[remm]
    mov eax,dword[cache + edx*4]
    mov dword[val],1
    cmp eax,1
    jge eviction

    ; if cache miss
    push msg6
    call printf
    pop ecx

    mov eax,[address]
    mov edx,[remm]
    mov dword[cache + edx*4],eax
    mov dword[values + edx*4],1  ; default val at that mem location
    jmp take_input

; op == write then 2 23 3 (op address val)
write:
    ; read address
    push address
    push fmt
    call scanf
    pop ecx
    pop ecx

    ; read val
    push val
    push fmt
    call scanf
    pop ecx
    pop ecx

    ; do mod operation
    xor edx,edx
    mov eax,[address]
    mov ebx,13

    div ebx
    mov [remm],edx

    ; check for cache hit
    mov edx,[remm]
    mov eax,[val]
    mov dword[values + edx*4],eax ; update val in cache if hit
    mov eax,dword[cache + edx*4] 
    mov ebx,[address]
    cmp eax,ebx
    je hit

    ; if conflict
    mov edx,[remm]
    mov eax,dword[cache + edx*4]
    cmp eax,1
    jge eviction

    ; if cache miss then update cache and val 
    push msg6
    call printf
    pop ecx

    mov eax,[address]
    mov edx,[remm]
    mov dword[cache + edx*4],eax
    mov eax,[val]
    mov dword[values + edx*4],eax
    jmp take_input

hit:
    push msg5
    call printf
    pop ecx

    mov edx,[remm]

    ; print the val in cache
    push dword[values + edx*4] 
    push fmt 
    call printf
    pop ecx
    pop ecx 

    push newline
    call printf
    pop ecx

    jmp take_input

; in case of conflict remove earlier content and update both cache and val in it
eviction:
    push msg7
    call printf
    pop ecx

    mov eax,[address]
    mov edx,[remm]
    mov dword[cache + edx*4],eax
    mov eax,[val]
    mov dword[values + edx*4],eax

    jmp take_input

; exit the program
exit:
    mov esp,ebp
    pop ebp
    mov eax,1
    mov ebx,0
    int 0x80
