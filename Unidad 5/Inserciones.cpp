#include<stdio.h>
#include<malloc.h>
struct nodo{
	int nro;
	nodo *sig;
};
typedef nodo *puntero;
void insertar(puntero &xp){ 
	int dato;
	puntero nuevo;
	printf("\n Ingrese el nuevo valor (0 para terminar): ");
	scanf("%d",&dato);
	while (dato != 0){
		nuevo =(puntero) malloc(sizeof(struct nodo));
		nuevo->nro = dato;
		nuevo->sig = xp;
		xp = nuevo;
		printf("\n Ingrese el nuevo valor (0 para terminar): ");
		scanf("%d",&dato);
	}
	return;
}
void insertarAlFinal (puntero &xp){
	puntero p, nuevo, anterior;
	int num;
	printf("\n Ingrese el nuevo valor, finalice con cero: ");
	scanf("%d",&num);
	while(num){
		nuevo =(puntero) malloc(sizeof(struct nodo));
		nuevo->nro=num;
		nuevo->sig = NULL;
		if (xp == NULL){ /* controla si la lista está vacía */
			xp = nuevo;
		}	
		else{
			p = xp; /* resguarda a xp de las siguientes modificaciones */
			while (p != NULL){ 
				anterior = p;
				p = p->sig;
			}
			anterior->sig = nuevo;
		}
		printf("\n Ingrese el nuevo valor, finalice con cero: ");
		scanf("%d",&num);
	}
	return;
}
void insertarAdentro (puntero &xp){ 
	puntero p, nuevo, anterior;
	int num;
	printf("\n Ingrese el nuevo valor, finalice con cero: ");
	scanf("%d",&num);
	while(num){
		nuevo =(puntero) malloc(sizeof(struct nodo));
		nuevo->nro=num;
		if (xp == NULL){ /* caso 1: la lista está vacía */
			xp = nuevo;
			nuevo->sig = NULL;
		}
		else if (xp->nro == nuevo->nro){ /* caso 2: la inserción debe hacerse al comienzo */
			nuevo->sig = xp;
			xp=nuevo;
		}
		else{
			p = xp; /* resguarda a xp de las siguientes modificaciones */
			anterior=xp; /* caso 3: la inserción debe hacerse adentro o al final */
			while ((p != NULL)&&(nuevo->nro > p->nro)){
				anterior = p;
				p = p->sig;
			}
		anterior->sig = nuevo;
		nuevo->sig = p;
		}
		printf("\n Ingrese el nuevo valor, finalice con cero: ");
		scanf("%d",&num);
	}return;
}

void muestra(puntero xp){
	if(xp!=NULL){
		printf("\n%d",xp->nro);
		muestra(xp->sig);
	}else return;
}
int main(){
	puntero cabeza=NULL;
	//insertarAlFinal(cabeza);
	insertarAdentro(cabeza);
	//insertar(cabeza);
	printf("\nListado de numeros");
	muestra(cabeza);
	
}
