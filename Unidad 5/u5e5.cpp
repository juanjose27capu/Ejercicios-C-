#include<stdio.h>
#include<malloc.h>
struct nodo{
	int nro;
	struct nodo *sig;
};
typedef nodo *puntero;
void crear (puntero &xp){
	xp=NULL;
}
void insertar (puntero &xp, int dato){ 

	static puntero nuevo;
	if(dato != -1)
	{
		nuevo =(puntero) malloc(sizeof(struct nodo));
		nuevo->nro = dato;
		nuevo->sig = xp;
		xp = nuevo;
		printf("\nIngrese numero positivo (-1 para terminar): ");
		scanf("%d",&dato);
		insertar(xp,dato);
	}
	else return;
}
void recorre(puntero xp){
	if(xp!=NULL){
		if(xp->sig==NULL){
			if(xp->nro%2==0){
				printf("\nEl numero del ultimo nodo es par");
			}else printf("\nEl numero del ultimo nodo es impar");
		}else{
			xp=xp->sig;
			recorre(xp);
		} 
	}else return;
}
int main(){
	
	puntero cabeza;
	int num;
	crear(cabeza);
	printf("\nIngrese numero positivo (-1 para terminar): ");
	scanf("%d",&num);
	insertar(cabeza,num);
	recorre(cabeza);
}
