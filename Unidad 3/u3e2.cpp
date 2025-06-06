#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 3
struct autito {
	char nomb[60];
	float precio;
	int stock;	
};
void cerear(autito a[n]){
	
	int i;
	
	for(i=0;i<n;i++){
		a[i].stock=rand()%300;
		a[i].precio=rand()%100000;
	}
}
void carga(autito a[n]){
	
	int cod,cant;
	char p[60];
	
	printf("\nIngrese nombre del articulo, finalice con FIN: ");
	gets(p);
	while(strcmp(p,"FIN")!=0){
		printf("\nIngrese codigo del articulo: ");
		scanf("%d",&cod);
		printf("\nIngrese cantidad de unidades vendidas: ");
		scanf("%d",&cant);
		a[cod-1].stock-=cant;
		fflush(stdin);
		strcpy(a[cod-1].nomb,p);
		fflush(stdin);
		printf("\nIngrese nombre del articulo, finalice con FIN: ");
		gets(p);
		fflush(stdin);
	}
}
void print(autito a[n]){
	
	int i;
	printf("\n---------------");	
	for(i=0;i<n;i++){
		printf("\n---------------");
		printf("\nStock: %d",a[i].stock);
		printf("\nPrecio: %10.2f\n",a[i].precio);
		puts(a[i].nomb);
		printf("\n---------------");	
	}
}
int sinstock(autito a[n],int &xm){
	int i,ne=0;
	
	for(i=0;i<n;i++){
		if(a[i].stock==0){
			ne++;
		}
		if(a[i].precio>7000){
			xm++;
		}
	}
	return(ne);
}
void mayores20(autito a[n]){
	int i,k,cota;
	autito aux;
	cota=n-1;
	k=1;
	while(k!=-1){
		k=-1;
		for(i=0;i<cota;i++){
			if(a[i].stock<a[i+1].stock){
				aux=a[i];
				a[i]=a[i+1];
				a[i+1]=aux;
				k=i;
			}
		}
		cota=k;
	}
	printf("\nArticulos con mayor stock");
	for(i=0;i<3;i++){
		printf("\n%s",a[i].nomb);
	}
}
void montototal(autito a[n]){
	int i;
	printf("\nMonto total de ventas por articulo: ");
	for(i=0;i<n;i++){
		printf("\nArticulo: %s: %10.2f",a[i].nomb,a[i].precio*a[i].stock);
	}
}
int main(){
	
	autito arr[n];
	int nulos=0,m=0;
	
	cerear(arr);
	carga(arr);
	print(arr);
	nulos=sinstock(arr,m);
	printf("\nCantidad de articulos con stock igual a cero: %d",nulos);
	printf("\nCantidad de articulos con precio mayor a 7000: %d",m);
	mayores20(arr);
	montototal(arr);
} 

/*
jaja
1
13
alberto
2
8
piñon fijo
3
56
FIN
*/
