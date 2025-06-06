#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define N 2
#define M 2
struct med {
	int cant;
	float precio;
	char nomb[50];
	float total;
};

void cerear(med a[],int n){
	
	int i;
	
	for(i=0;i<n;i++){
		
		a[i].cant=0;
		a[i].precio=0;
		a[i].total=0;
	}
	return;
}

void carga(med a[N],med b[M]){
	
	int i,cod,xcant;
	float imp;
	
	for(i=0;i<M;i++){
		
		printf("\nFarmacia %d",i+1);
		printf("\nIngrese codigo de medicamento: ");
		scanf("%d",&cod);
		
		while(cod){

		printf("\nIngrese nombre del medicamento: ");
		fflush(stdin);
		gets(a[cod-1].nomb);
		fflush(stdin);
		printf("\nIngrese cantidades vendidas: ");
		scanf("%d",&xcant);
		a[cod-1].cant+=xcant;
		b[i].cant+=xcant;		
		printf("\nIngrese precio: ");	
		scanf("%f",&imp);
		a[cod-1].precio=imp;
		b[i].total+=xcant*imp;
		printf("\nIngrese codigo de medicamento: ");
		scanf("%d",&cod);					
		}
	}
	return;
}

void mayorimp(med a[N]){
	
	int i;
	float max=0;
	
	for(i=0;i<N;i++){
		
		if((a[i].cant*a[i].precio)>max){
			max=a[i].cant*a[i].precio;	
		}
	}
	printf("\nCodigo de los medicamentos que recaudaron mayor importe");
	for(i=0;i<N;i++){
		
		if((a[i].cant*a[i].precio)==max){
			printf("\nMedicamento numero %d",i+1);
		}	
	}	
}

void buscacod(med a[N],int xc){
	
	int i=0;
	
	while((i<N)&&(xc-1!=i)){
		
		i++;
	}
	if(i<N){
		printf("\nCantidad de unidades vendidas para el codigo %d: %d",xc,a[xc-1].cant);
	}else printf("\nCodigo no encontrado");
	return;
}

void buscanombre(med a[N],char xn[50] ){
	
	int i=0;
	
	while((i<N)&&strcmp(xn,a[i].nomb)){
		
		i++;
	}
	if(i<N){
		cout <<"\nTotal recaudado por el medicamento "<<xn<<": "<<("%10.2f",a[i].cant*a[i].precio);
		printf("\nCantidades vendidas: %d",a[i].cant);
	}
	else printf("\nNombre no encontrado");
	return;
}

void muestra(med b[M]){
	
	int i;
	
	for(i=0;i<M;i++){
		
		printf("\nUnidades vendidas a la farmacia %d: %d",i+1,b[i].cant);
		printf("\nImporte total que pago: %10.2f",b[i].total);
	}
	return;
}
int main(){
	
	med remedios[N],farmacias[M];
	int code;
	char name[50];
	
	cerear(remedios,N);
	cerear(farmacias,M);
	carga(remedios,farmacias);
	printf("\n---------------");
	mayorimp(remedios);
	printf("\n---------------");
	printf("\nIngrese un codigo de medicamento ");
	scanf("%d",&code);
	buscacod(remedios,code);
	printf("\n---------------");
	printf("\nIngrese el nombre de un medicamento ");
	fflush(stdin);
	gets(name);
	fflush(stdin);	
	buscanombre(remedios,name);
	printf("\n---------------");
	muestra(farmacias);
}

/*
1
hola
10
500
2
chau
5
10
0
1
hola
10
500
2
chau
5
10
0
*/

