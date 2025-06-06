#include<stdio.h>
#include<string.h>
#include <Windows.h>

typedef char cadena[50];

struct datos{
	cadena nomb;
	int registro;
	char nota;
};

void carga(FILE *archi){
	
	datos a;
	
	printf("\nIngrese el nombre del alumno, finalice con FIN: ");
	fflush(stdin);
	gets(a.nomb);
	fflush(stdin);
	
	while(stricmp(a.nomb,"FIN")){
		
		printf("\nIngrese el registro: ");
		scanf("%d",&a.registro);
		fwrite(&a,sizeof(a),1,archi);
		printf("\nIngrese la nota: ");
		scanf("%s",&a.nota);
		fwrite(&a,sizeof(a),1,archi);
		printf("\nIngrese el nombre del alumno, finalice con FIN: ");
		fflush(stdin);
		gets(a.nomb);
		fflush(stdin);			
	}
}

void mostrar(FILE *archi){
	datos a;
	rewind(archi);
	while(fread(&a,sizeof(a),1,archi)!=0 ){
		printf("\nme voy a matar");
		printf("\n Nombre: %s, Registro: %d, Nota: %s\n",a.nomb,a.registro,a.nota);
	}
}

void aprobados(FILE *parchi,FILE *aarchi){

	datos p;
	datos a;
	rewind(parchi);
	rewind(aarchi);	
	printf("alumnos aprobados");
	while(fread(&p,sizeof(p),1,parchi)!=0 ){
		while(fread(&p,sizeof(p),1,aarchi)!=0 ){
		if((p.nota=='a')&&(a.nota=='a')){
				printf("\n Nombre: %s, Edad: %d\n",a.nomb,a.registro);
			}
		}
	}
}

int main(){
	
	FILE *archiP;
	FILE *archiA;
	
{//PP
	printf("\nProgramacion procedural:\n");
	if((archiP=fopen("alumnosPP.dat","wb"))==NULL){
		printf("hay error1 \n");
	}
	else{
		
		carga(archiP);
		fclose(archiP);
	}
	
	system("cls");
	if ((archiP=fopen("alumnosPP.dat","rb"))==NULL){
		
		printf("hay error1 \n");
	}
	else{
		printf("\nlista:");
		mostrar(archiP);
		fclose(archiP);
	}
}
{//AL
	printf("\nAlgebra Lineal:\n");
	if((archiA=fopen("alumnosAL.dat","wb"))==NULL){
		printf("hay error1 \n");
	}
	else{
		
		carga(archiA);
		fclose(archiA);
	}
	
	system("cls");
	if ((archiA=fopen("alumnosAL.dat","rb"))==NULL){
		
		printf("hay error1 \n");
	}
	else{
		printf("\nlista:");
		mostrar(archiA);
		fclose(archiA);
	}
}
	aprobados(archiA,archiP);
}

/*
juan
20
a
julian
21
r
julia
22
a
*/