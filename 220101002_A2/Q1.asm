; Abhishek Kumar 
; 16/01/2024

section .data
	msg1 db "Enter 1st string",10,0
	msg2 db "Enter 2nd string",10,0
	fmt1 db "%d \n",0
	fmt2 db "%s",0

section .bss
	string1 resb 100
	string2 resb 100
	
section .text 
	global main
	extern printf
	extern scanf
	

main :
	push ebp 
	mov ebp,esp
	
	push msg1
    	call printf
    	pop ecx

    	push string1
    	push fmt2
    	call scanf
    	pop ecx
    	pop ecx
    	
    	push msg2
    	call printf
    	pop ecx

    	push string2
    	push fmt2
    	call scanf
    	pop ecx
    	pop ecx
	
	mov ebx,-1
	
	
loop1 : 
        inc ebx
	mov al,[string1 + ebx]
	cmp al,0
	je end
	
	mov ecx,0
	
loop2 : 
	mov al,[string2 + ecx]
	cmp al,0
	je found
	
	mov al,[string1 + ebx + ecx]
	mov dl,[string2 + ecx]
	cmp al,dl
	jne loop1
	
	inc ecx
	jmp loop2
	
	
end : 
	push -1
	push fmt1
	call printf
	pop ecx
	pop ecx
	
	mov esp,ebp
    	pop ebp
    	mov eax,1
    	mov ebx,0
    	int 0x80
	
found : 
	add ebx,1
	push ebx
	push fmt1
	call printf
	pop ecx
	pop ecx
	
	mov esp,ebp
    	pop ebp
    	mov eax,1
    	mov ebx,0
    	int 0x80	
	
