#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<windows.h>
#define N 10

typedef char cadena[30];
struct nodo{
	int dni;
	struct nodo * sig;
} ;
struct datos{
	int numero;
	int cant;
	cadena titulo;
	struct nodo * ins; 
};
typedef struct nodo * inscriptos;
void crear (inscriptos &xp){
	xp=NULL;
}
void insertar (inscriptos &xp, long DNI){
	inscriptos nuevo;
	nuevo = (inscriptos) malloc(sizeof(nodo));
	nuevo->dni=DNI;
	nuevo->sig = xp;
	xp = nuevo;
	return;
}
void eliminar(inscriptos &xp,long DNI){
	inscriptos anterior,p;
	if(xp->dni==DNI){
		p=xp;
		xp=xp->sig;
		free(p);
		printf("\nInscripcion eliminada con exito >;)\n");
	}
	else{
		p=xp;
		anterior=xp;
		while((p!=NULL)&&(p->dni!=DNI)){
			anterior=p;
			p=p->sig;
		}
		if(p!=NULL){
			anterior->sig=p->sig;
			free(p);
			printf("\nInscripcion eliminada con exito >;)\n");
		}
		else printf("\nNo se encontro el DNI\n");
		return;
	}
}
int recorre(inscriptos xp,int DNI){
	if(xp!=NULL){
		if(xp->dni==DNI){
			return 1;
		}else recorre(xp->sig,DNI);
	}else return 0;
}
void busca(datos t[N],int i,int DNI){
	if(i<N){
		if(recorre(t[i].ins,DNI)){
			printf("\n Tutorial nro: %d",i+1);
			printf("\n Nombre: %s",t[i].titulo);
			busca(t,i+1,DNI);
		}else busca(t,i+1,DNI);
	}else return;
}
void listar(datos t[]){
	int i;
	inscriptos xp;
	for(i=0; i<N; i++){
		printf("\n **** Datos de Inscriptos en el Tutorial:%3d ****\n", i+1);
		printf("\n TITULO: "); puts(t[i].titulo);
		printf("\n INSCRIPTOS \n ");
		xp= t[i].ins;
		while (xp!= NULL){
		printf("\n %d",xp->dni);
		xp = xp->sig;
		}
	}
}
int main(){
	int i, n, op;
	long d;
	system("color 2");
	datos tutorial[N]; 
	printf("\n ********** Cargar de los tutoriales C *********");
	for (i=0;i<N;i++){
		tutorial[i].numero=1;
		printf("\n Ingrese nombre del tutorial %d :",i+1);
		gets(tutorial[i].titulo);
		tutorial[i].cant=0;
		crear(tutorial[i].ins);
	}
	_sleep(3000);
	system("cls");
	printf("\n ******** MENU DE OPCIONES ***********\n");
	do{
		printf("\n 1- Realizar una inscripcion: ");
		printf("\n 2- Eliminar una inscripcion: ");
		printf("\n 3- Mostrar Datos de un tutorial: ");
		printf("\n 4- Mostrar tutoriales en los cuales se inscribio una persona : ");
		printf("\n 5- Mostrar tutoriales con Datos de Inscriptos : ");
		printf("\n 6- Salir del Menu: ");
		scanf("%d", &op);
		switch (op){
			case 1: { printf("\n Ingrese numero del tutorial: ");
			scanf("%d", &n);
			printf("\n Ingrese DNI: ");
			scanf("%d", &d);
			tutorial[n-1].cant++;
			insertar(tutorial[n-1].ins,d);
			break;
			}		
			case 2: { printf("\n Ingrese numero del tutorial al que se inscribio: ");
			scanf("%d", &n);
			printf("\n Ingrese DNI del inscripto: ");
			scanf("%d", &d);
			eliminar(tutorial[n-1].ins,d);
			break;
			}
			case 3: { printf("\n Ingrese numero del tutorial: ");
			scanf("%d", &n);
			printf("\nNombre del tutorial: %s",tutorial[n-1].titulo);
			printf("\nCantidad de inscriptos: %d\n",tutorial[n-1].cant);
			break;
			case 4: { 
			printf("\n Ingrese DNI del inscripto: ");
			scanf("%d", &d);
			printf("\n Tutoriales en los que se inscribio el DNI %d ",d);
			busca(tutorial,0,d);
			break;
			case 5: listar(tutorial) ;
			}
		}
		}
		
		_sleep(3000);
		system("cls");
	} while (op !=6);
}
/*
cocina
reparacion de sillas gamer
php
lol
vacunacion para seniles
cocina para seniles
psiquiatria para seniles
seniles
fotografia con android
programacion procedural
*/