#include<stdio.h>
#define N 70
#define M 30

struct prod {
	float precio;
	int cant;
};

void cerear(prod xp[N],int xa[M]){
	
	int i;
	
	for(i=0;i<N;i++){
		xp[i].precio=0;
		xp[i].cant=0;
		if(i<30){
		xa[i]=0;			
		}
	}
}

void carga(prod xp[N]){
	
	int cod,xcant;
	
	printf("\nIngrese codigo de producto, finalice con cero ");
	scanf("%d",&cod);
	
	while(cod!=0){
		
		if((cod>=100)&&(cod<=169)){
			
			printf("\nIngrese precio ");
			scanf("%f",&xp[cod-100].precio);
			printf("\nIngrese cantidad de unidades vendidas ");
			scanf("%d",&xcant);
			xp[cod-100].cant+=xcant;
			
		}else printf("\nCodigo incorrecto ");
		
		printf("\nIngrese codigo de producto, finalice con cero ");
		scanf("%d",&cod);
	}
}

void totalvendido(prod xp[N]){
	
	int i;
	
	printf("\nTotal de unidades vendidas por producto");
	printf("\n");
		
	for(i=0;i<N;i++){
		
		printf("\nProducto %d: %d unidades",i+100,xp[i].cant);
		printf("\n");
	}
}

int maximo(prod xp[N]){
	
	int i,max=0,n;
	
	for(i=0;i<N;i++){
		
		if((xp[i].cant*xp[i].precio)>max){
			
			max=xp[i].cant*xp[i].precio;
			n=i;
		}	
	}
	return(n);
}

void cuantovendio(prod xp[N],int xa[M]){
	
	int i;
	
	for(i=0;i<N;i++){
		
		if((xp[i].cant>=20)&&(xp[i].cant<=50)){     
			xa[xp[i].cant-20]++;
		}
	}
	
	for(i=0;i<M;i++){
		printf("\nSe vendieron %d unidades en %d productos",i+20,xa[i]);
		printf("\n");
	}
}

int main(){
	
	
	prod p[N];
	int m, a[M];

	cerear(p,a);
	carga(p);
	totalvendido(p);
	m=maximo(p);
	
	printf("\nEl codigo del producto que recaudo mayor importe es el %d",m+100);
	printf("\n");
	printf("\nEl mayor importe es %10.2f",p[m].cant*p[m].precio);
	printf("\n");
	printf("\nCantidad de unidades vendidas: %d",p[m].cant);
	printf("\n");
	
	cuantovendio(p,a);
}

/*
LOTE DE PRUEBA
100
500
20
101
600
21
102
80
22
103
6000
23
0
*/
