.586
.model flat,C
printf PROTO,:DWORD,:DWORD
funcion PROTO, :DWORD,:DWORD
.data
	cadenaFormato db "x=%d",0
	PUBLIC n
	EXTERN x:DWORD
	n DD 16
	res DD 0
.code
	PUBLIC subAsm
	subAsm PROC
		mov ebx,x
		push x
		push n
		call funcion
		mov res,EAX
		pop ebx
		pop ebx
		INVOKE printf,OFFSET cadenaFormato,res
		ret
	subAsm ENDP

END