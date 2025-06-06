#include <stdio.h>
#include <malloc.h>

struct nodo{
	int nro;
	struct nodo*sig;
};
typedef struct nodo*puntero;

void crea(puntero &xp){
	xp=NULL;
}

void lista(puntero &xp){
	int num;
	puntero p, anterior, nuevo;
		printf("ingrese un numero entero finalice con 0\n ");
	    scanf("%d", &num);
	    if(num!=0){
	    	nuevo=(puntero)malloc(sizeof(struct nodo));
	    	nuevo->nro=num;
	    	nuevo->sig=xp;
	    	xp=nuevo;
	    	lista(xp);
	}else return;
		
}
void intercambia(puntero &p,puntero &k,puntero &cota,int aux){
        if(p->sig!=cota){
           if(p->nro>p->sig->nro){
               aux=p->sig->nro;
               p->sig->nro=p->nro;
               p->nro=aux; 
               k=p;   
            } 
            p=p->sig;
            intercambia(p,k,cota,aux);
        }else return;
}        
void consulta(puntero &xp,puntero &p,puntero &k,puntero &cota,int aux){
    if(k!=xp){
        k=xp;
        p=xp;
        intercambia(p,k,cota,aux);
        cota=k->sig;
        consulta(xp,p,k,cota,aux);
    }else return;
}    
void ordena(puntero &xp){
	static puntero k, cota,p;
	static int aux;
	cota=NULL;
	k=NULL;
 consulta(xp,p,k,cota,aux);  
}
void muestra(puntero xp){
	printf("lista de numeros\n");
	while(xp!=NULL){
		printf("\n %d", xp->nro);
		xp=xp->sig;
	}
}
void indicar(puntero xp){
	if(xp!=NULL){
		if(xp->sig==NULL){
			if(xp->nro%2==0){
				printf("\nEl numero del ultimo nodo es par");
			}else printf("\nEl numero del ultimo nodo es impar");
		}else{
			xp=xp->sig;
			indicar(xp);
		} 
	}else return;
}



int main(){
	puntero cabeza;
	crea(cabeza);
	lista(cabeza);
	ordena(cabeza);
	muestra(cabeza);
	indicar(cabeza);
}
