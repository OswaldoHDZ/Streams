#include <stdio.h>
#include <stdlib.h>

int x = 3;
extern void subAsm(void);
//extern void calculaEdad(int a,int m,int edad[2]);
main() {
	
	extern int n;
  
	printf("Ingresa una valor:");
	scanf_s("%d", &x);
	_asm {
	
		mov eax, x
		add x,6
	
	}

	subAsm();
	printf("n=%d", n);

}


int funcion(int a, int b) {

	return a+b;

}
