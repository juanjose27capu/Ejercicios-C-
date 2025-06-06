#include<stdio.h>
#include<malloc.h>
#include<iostream>
#include<stdlib.h>
struct nodo{
	int nro;
	struct nodo *sig;
};
typedef nodo *puntero;

void crear (puntero &xp){
	xp=NULL;
}
void evalua(puntero &pp,puntero &ant){
	
	if (pp != NULL){ 
		ant = pp;
		pp = pp->sig;
		evalua(pp,ant);
 	} else return;
}
void investiga (puntero &xp,int num){ 
	static puntero p, anterior,nuevo;
	nuevo =(puntero) malloc(sizeof(struct nodo));
	if (num!=0){
		nuevo->nro = num;
		nuevo->sig = NULL;
		if (xp == NULL){
			 xp = nuevo;
			 printf(" Ingrese nuevo valor: ");
			 scanf("%d",&num);
			 investiga (xp,num);
		}
		else{
			p = xp;
			evalua(p,anterior);
		 	anterior->sig = nuevo;
			printf(" Ingrese nuevo valor: ");
			scanf("%d",&num);
			investiga (xp,num);
		}
			system("color 4");
			return;
}

void recorre (puntero xp){
	printf("\n Listado de datos: ");
	while (xp != NULL){
		printf("\n %d ",xp->nro);
		xp = xp->sig;
	}
}

int main(){
int nn;
puntero cabeza;
system("color 2");
printf("ingrese el primer componente(finaliza con 0)");
scanf("%d",&nn);
 crear(cabeza);
 investiga(cabeza,nn);
 recorre(cabeza);
}


