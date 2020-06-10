#include <stdio.h>
#include <stdlib.h>

extern void subAsm();
extern void calculaEdad(int a, int m, int edad[2]);
int x = 3;

main() {
	extern int n;

	printf("Ingrese un valor: ");
	scanf_s("%d", &x);	

	_asm {
		MOV EAX,x
		ADD x,6
	}

	subAsm();
	printf("\nx = %d", x);
	printf("\nn = %d", n);
}

int funcion(int a, int b) {
	//printf("Estoy en funcion\n");
	//printf("Lo que tiene a = %d\n",a);
	//printf("Lo que tiene b = %d\n",b);
	return a + b;
}

