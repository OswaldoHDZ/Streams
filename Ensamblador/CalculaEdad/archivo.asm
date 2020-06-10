.586
.model flat,C	; Se pone C para que se puedan compartir bien las variables y funciones
printf  PROTO,:DWORD,:DWORD
funcion PROTO,:DWORD,:DWORD
calculaFechaNacimiento PROTO,:DWORD,:DWORD
.data
aniosCalculados DB "Anios calculados %d",0
mesesCalculados DB "Meses calculados %d",0
EXTERN x: DWORD
PUBLIC n
n   DD 16
res DD 0
mesNac DD 0
aniNac DD 0
arreglo DD 0,0
.code
PUBLIC calculaEdad
calculaEdad PROC

	MOV EAX,[ESP+4] ;Esto tiene el MES del USUARIO Hexadecimal
	MOV EBX,[ESP+8] ;Esto tiene el ANIO del USUARIO Hexadecimal
	MOV EDI,[ESP+12] ; Esto contiene el arreglo 
	MOV ECX, [ESP+16] ; Esto contiene el MES ACTUAL
	MOV EDX, [ESP+20] ; Esto contiene el ANIO ACTUAL

	SUB EDX,EBX 

	CMP EAX,ECX ; if (mesUsuario <= mesActual)
	JBE salta ; mesUsuario = mesActual - mesUsuario;
	SUB EDX,1H ;Restamos un anio en caso de que NO paso el mes de su cumpleños
	MOV EAX,ECX
	salta:
    MOV [EDI+0],EDX
	CMP EAX,ECX
	JAE salta1
	SUB ECX,EAX
	ADD EAX,ECX
	;Hacemos una suma en caso de que el mes de cumpleanios ya paso
	
	salta1:
	MOV [EDI+4],EAX
	ret


calculaEdad ENDP

END