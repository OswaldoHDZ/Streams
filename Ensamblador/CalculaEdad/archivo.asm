.586
.model flat,C	; Se pone C para que se puedan compartir bien las variables y funciones
printf  PROTO,:DWORD,:DWORD
funcion PROTO,:DWORD,:DWORD
calculaFechaNacimiento PROTO,:DWORD,:DWORD
.data
cadenaFormato DB "asm (x = %d)",0
EXTERN x: DWORD

PUBLIC n
n   DD 16
res DD 0

mesNac DD 8
aniNac DD 1996

.code
PUBLIC subAsm

subAsm PROC
	; Aqui vamos a meter los meses y los días
	PUSH aniNac ; Metemos a la pila para despues pasarlo como parametro a la fuc de C
	PUSH mesNac 
	CALL calculaFechaNacimiento

	

	INVOKE printf,OFFSET cadenaFormato,res		; PUSH y POP los hace internos

	RET
subAsm ENDP

END

