#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Para que funcione el programa tiene que poner la siguiente configuración
//El compilador de Visual Studio(VS) da este error.Es fácil deshacerse de este problema.

//Vaya a su menú contextual VS Proyecto > Propiedades .
//Haga clic en Configuración > Propiedades > C / C++ > Preprocesador .
//Edite las definiciones de preprocesador y agregue _CRT_SECURE_NO_WARNINGS última línea vacía.
//Esta advertencia de compilación se habrá ido.
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
void calculaFechaNacimiento(int a, int b) {
	time_t t;
	struct tm* tm;
	char fechayhora[100];
	int mesUsuario  = a;
	int anioUsuario = b;
	t = time(NULL);
	tm = localtime(&t);
	int mesActual = tm->tm_mon + 1;
	int anioActual = 1900 + tm->tm_year;
	int anios = calculoAnios(anioUsuario, anioActual);
	printf("El usuario tiene %d", anios);
	//printf("\n MES:    %d\n", tm->tm_mon+1); //Queremos imprimir el indice del mes
	//printf("\n ANIO:   %d\n", 1900 + tm->tm_year); //Queremos imprimir el indice del año
	
	//Ya tenemos el día,mes, año de hoy ahora vamos a regresar solo el mes y año
}
int calculoAnios(int anioUsuario,int anioActual) {
	return anioActual-anioUsuario;
}
//Calculo de edad de una  persona 
//Obtener la fecha actual
//Apartir de la fecha de nacimiento
//	SOLO : Mes y año