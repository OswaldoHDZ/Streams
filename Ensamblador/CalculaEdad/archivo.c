#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//https://stackoverflow.com/questions/19321804/this-function-or-variable-may-be-unsafe-visual-studio
//Para que funcione el programa tiene que poner la siguiente configuración
//El compilador de Visual Studio(VS) da este error.Es fácil deshacerse de este problema.

//Vaya a su menú contextual VS Proyecto > Propiedades .
//Haga clic en Configuración > Propiedades > C / C++ > Preprocesador .
//Edite las definiciones de preprocesador y agregue _CRT_SECURE_NO_WARNINGS última línea vacía.
//Esta advertencia de compilación se habrá ido.
int* calculaFechaNacimiento();
extern void subAsm();
extern void calculaEdad(int a, int m, int edad[2] ,int mesActual, int anioActual);
extern void fechaActual(int mesAcutal, int anioActual);
int x = 3;

main() {
	int *fechaActual;
	fechaActual = calculaFechaNacimiento();
	//printf("El MES actual es : %d\n", fechaActual[0]);
	//printf("El ANIO actual es : %d\n", fechaActual[1]);
	
	int mesActual =  fechaActual[0];
	int anioActual = fechaActual[1];
	
	int mesNac = 8;
	int aniNac = 1996;
	int edad[2];
	calculaEdad(mesNac, aniNac, edad, mesActual, anioActual);
	printf("\n\nEl usuario tiene LA EDAD DE %d ", edad[0]);
	printf("CON %d MESES\n\n", edad[1]);
}

int funcion(int a, int b) {
	//printf("Estoy en funcion\n");
	//printf("Lo que tiene a = %d\n",a);
	//printf("Lo que tiene b = %d\n",b);
	return a + b;
}
int* calculaFechaNacimiento() {
	time_t t;
	struct tm* tm;
	char fechayhora[100];
	//int mesUsuario = a;
	//int anioUsuario = b;
	t = time(NULL);
	tm = localtime(&t);
	int mesActual = tm->tm_mon + 1;
	int anioActual = 1900 + tm->tm_year;
	int *actual = (int*)calloc(2, sizeof(int)); ;
	actual[0] = mesActual;
	actual[1] = anioActual;
	return actual;
	//int anios = calculoAnios(anioUsuario, anioActual);
	//printf("El mes acutual es  %d", mesActual);
	//printf("El mes del usuario es  %d", mesUsuario);
	//Lo siguiente que vamos a hacer es si el mes de cumpleños ya paso o no
	//if (mesUsuario <= mesActual) {
	//	//printf("El usuario tiene %d", anios);
	//	mesUsuario = mesActual - mesUsuario;
	//}
	//else {
	//	anios = anios - 1;
	//	//printf("El usuario tiene %d", anios - 1);
	//}
	//int edad[2];
	//edad[0] = anios;
	//printf("El usuario tiene %d", anios - 1);
	//edad[1] = mesUsuario;
	//return edad;
	//printf("\n MES:    %d\n", tm->tm_mon+1); //Queremos imprimir el indice del mes
	//printf("\n ANIO:   %d\n", 1900 + tm->tm_year); //Queremos imprimir el indice del año

	//Ya tenemos el día,mes, año de hoy ahora vamos a regresar solo el mes y año
}
int calculoAnios(int anioUsuario, int anioActual) {
	return anioActual - anioUsuario;
}

//Calculo de edad de una  persona 
//Obtener la fecha actual
//Apartir de la fecha de nacimiento
//	SOLO : Mes y año