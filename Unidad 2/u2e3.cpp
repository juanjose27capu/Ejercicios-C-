#include <stdio.h>
#include <string.h>
#include <iostream>
#define N 3

struct procedural{
	char nombre[20];
	char apellido[20];
	int dni;
};

void carga(procedural alumno[N]){
	int i;
	for (i=0;i<=N-1;i++){
		printf("\n alumno %d: ",i+1);
		fflush(stdin);
		printf("\n Introduce el nombre: ");
      	gets(alumno[i].nombre);
      	fflush(stdin);
      	printf("\n Introduce el apellido: ");
      	gets(alumno[i].apellido);
      	fflush(stdin);
      	printf("\n Introduce el DNI: ");
      	scanf("%d",&alumno[i].dni);
	}
	
}

void lista (procedural alumno[N]){
	int i;
	for (i=0;i<N;i++){
		printf("\n alumno %d: ",i+1);
		printf("\n nombre: %s %s", alumno[i].nombre, alumno[i].apellido);
		printf("\n dni: %d",alumno[i].dni);
	}


}

void indicar (procedural alumno[N]){
	int i;int cont;
	cont = 0;
	for (i=0;i<N;i++){
		if (alumno[i].dni > 4){
			cont ++;
		}
	}
	printf("\n hay %d alumnos con dni mayor a 40 millones", cont);
}

int main(){
	procedural alumno[N];
	carga(alumno);
	lista(alumno);
	indicar(alumno);
	
}