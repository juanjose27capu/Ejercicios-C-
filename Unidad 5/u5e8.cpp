#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef char cadena[50];
struct nodo{
	cadena nom;
	float prom;
	int anio;
	struct nodo *sig;
};
struct datos{
	cadena nombre;
	int cont;
	struct nodo *ins;
};
typedef struct nodo *puntero;

void insertar(puntero &xp,cadena xn){
	puntero nuevo,p,anterior;
	nuevo=(puntero)malloc(sizeof(nodo));
	strcpy(nuevo->nom,xn);
	printf("\nIngrese promedio de %s: ",nuevo->nom);
	scanf("%f",&nuevo->prom);
	scanf("%d",&nuevo->anio);
	if(xp==NULL){
		nuevo->sig=NULL;
		xp=nuevo;
	}
	else if(xp->prom==nuevo->prom){
		nuevo->sig=xp;
		xp=nuevo;
	}
	else{
		p=xp;
		anterior=xp;
		while((p!=NULL)&&(nuevo->prom < p->prom)){
			anterior=p;
			p=p->sig;
		}
		anterior->sig=nuevo;
		nuevo->sig=p;
	}
}
void listar(puntero xp){
	if(xp!=NULL){
		printf("\nNombre del alumno: %s",xp->nom);
		printf("\nPromedio: %.2f",xp->prom);
		printf("\nAño que cursa: %d",xp->anio);
		printf("\n");
		listar(xp->sig);
	}
}
int menosins(datos *f,int cant,int i,int xmin){
	static int aux;
	if(i<cant){
		if (f[i].cont<xmin){
			xmin=f[i].cont;
			aux=i;
			menosins(f,cant,i+1,xmin);
		}else menosins(f,cant,i+1,xmin);
	}else return aux;
}
int selecciona(puntero xp,int cc){
	if(xp!=NULL){
		if((xp->prom>=7)&&(xp->anio==2)){
			cc++;
			selecciona(xp->sig,cc);
		}else selecciona(xp->sig,cc);
	}else return cc;
}
int main(){
	
	datos *facu;
	int i,cant,min=99999999;
	cadena name;
	
	printf("\nIngrese el numero de facultades inscriptas para becas: ");
	scanf("%d",&cant);
	facu=(datos*)malloc(sizeof(datos)*cant);
	for(i=0;i<cant;i++){
		facu[i].ins=NULL;
		facu[i].cont=0;
		
		printf("\nIngrese el nombre de la facultad numero %d: ",i+1);
		fflush(stdin);
		gets(facu[i].nombre);
		fflush(stdin);
		
		printf("\nInscriptos a becas de la facultad: %s\n",facu[i].nombre);
		
		printf("\nIngrese nombre del alumno, finalice con FIN: ");
		fflush(stdin);
		gets(name);
		fflush(stdin);
		
		while(stricmp(name,"FIN")){
			insertar(facu[i].ins,name);
			facu[i].cont++;
			
			printf("\nIngrese nombre del alumno, finalice con FIN: ");
			fflush(stdin);
			gets(name);	
			fflush(stdin);		
		}
	}
	//INCISO 1
	printf("\nIngrese el nombre de una facultad: ");
	fflush(stdin);
	gets(name);
	fflush(stdin);
	
	i=0;
	while((i<cant)&&(stricmp(name,facu[i].nombre))){
		i++;
	}
	if(i<cant){
		printf("\nListado de alumnos de la facultad %s ordenados por promedio",facu[i].nombre);
		listar(facu[i].ins);
	}else printf("\nNombre no encontrado");
	printf("\n");
	//INCISO 2
	min=menosins(facu,cant,0,99999);
	printf("\nFacultad con menos inscriptos: %s",facu[min].nombre);
	printf("\nCantidad de inscriptos: %d",facu[min].cont);
	printf("\n");
	//INCISO 3
	printf("\nCantidad de alumnos de cada facultad con promedio mayor o igual a 7 que cursan segundo año:");
	printf("\n");
	for(i=0;i<cant;i++){
		printf("%s: %d\n",facu[i].nombre,selecciona(facu[i].ins,0));
	}
	free(facu);
	facu=NULL;
}

/*
exactas
juan
9.5
2
pepe
6
2
fin
sociales
jesus
10
2
jose
4
2
pedro
7
2
fin
*/



