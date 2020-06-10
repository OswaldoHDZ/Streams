.586
.model flat,C	; Se pone C para que se puedan compartir bien las variables y funciones
printf  PROTO,:DWORD,:DWORD
funcion PROTO,:DWORD,:DWORD

.data
cadenaFormato DB "asm (x = %d)",0
EXTERN x: DWORD

PUBLIC n
n   DD 16
res DD 0

.code
PUBLIC subAsm

subAsm PROC

	MOV  EBX,x
	; Con entrada en pantalla con 2
	PUSH x ; Tiene que tener 8 del archvio C, con la suma del _asm
	PUSH n ; Tiene 16 
	CALL funcion ; Llamada a funcion del archivo C
	MOV  res,EAX ; EAX contine 8
	POP  EBX  	 ; Se debe regresar la pila a su estado
	POP  EBX		

	INVOKE printf,OFFSET cadenaFormato,res		; PUSH y POP los hace internos

	RET
subAsm ENDP

END
