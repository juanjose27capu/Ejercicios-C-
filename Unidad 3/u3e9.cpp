#include <stdio.h>
#include<string.h>
#define N 10
#define M 7
#define P 3
struct seg{
	char nomb[ 40];
	char tipo;
	float precio;
	float total;
};
typedef int arr[N];
typedef int tabla[P][M];
typedef seg registro[P];
void inicializar(registro s,arr p,tabla x){
	
	int i,j;
	
	for(i=0;i<N;i++){
		
		printf("\nIngrese el sector del promotor %d ",i+1);
		scanf("%d",&p[i]);				
	}
	for(i=0;i<P;i++){
		
		printf("\nIngrese tipo de seguro ");
		fflush(stdin);
		scanf("%c",&s[i].tipo);
		printf("\nIngrese nombre de seguro ");
		fflush(stdin);
		gets(s[i].nomb);
		printf("\nIngrese precio del seguro ");
		scanf("%f",&s[i].precio);
		s[i].total=0;
		
		for(j=0;j<M;j++){
			
			x[i][j]=0;
		}		
	}
	return;
}
void carga(registro s,arr p,tabla x){
	
	int i=0,promo;
	char type;
	
	printf("\nIngrese numero de promotor, finalice con cero ");
	scanf("%d",&promo);
	
	while(promo){
		
		printf("\nIngrese tipo de seguro ");
		fflush(stdin);
		scanf("%c",&type);
		
		switch(type){
			
			case 'a': 
			x[0][p[promo-1]-30]++;
			s[0].total+=s[0].precio;
			break;
			case 'b': 
			x[1][p[promo-1]-30]++;
			s[1].total+=s[1].precio;
			break;
			case 'c':
			x[2][p[promo-1]-30]++;
			s[2].total+=s[2].precio;
			break;							
		}		
		

		
	printf("\nIngrese numero de promotor, finalice con cero ");
	scanf("%d",&promo);	
	}
	return;
}
void busca1(registro s,arr p,tabla x){
	
	int i=0,j,max=0,aux,c=0;
	char t;

	printf("\nIngrese un tipo de seguro ");
	fflush(stdin);
	scanf("%c",&t);	
	
	while((i<P)&&(t!=s[i].tipo)){
		
		i++;
	}
	if(i<P){
		
		for(j=0;j<M;j++){
			
			if(x[i][j]>max){
				
				max=x[i][j];
				aux=j+30;
			}
		}
		printf("\nEl seguro %c se vende mas en el sector %d",t,aux);
		for(j=0;j<N;j++){
			
			if(p[j]==aux){
				
				c++;
			}
		}
		printf("\nDicho sector tiene %d promotores",c);
	}	
}
void busca2(registro s,tabla x){
	
	int i,max=0,aux,sector;

	printf("\nIngrese un sector ");
	scanf("%d",&sector);
	
	for(i=0;i<P;i++){
		
		if(x[i][sector-30]>max){
			
			max=x[i][sector-30];
			aux=i;
		}
	}
	printf("\nEn el sector %d, el seguro que mas se vende es el %c",sector,s[aux].tipo);
	return;
}
void muestra(registro s){
	
	int i;
	
	for(i=0;i<P;i++){
		
		printf("\nSeguro: %c",s[i].tipo);
		printf("\nNombre: %s",s[i].nomb);
		printf("\nImporte total de venta: %0.2f",s[i].total);
	}
}
void menu(registro s,arr p,tabla x){

	int control=1;
	char a='s';
	
	while((a=='s')&&(control)){
	
		printf("\n----MENU PRINCIPAL----");
		printf("\n1-INICILIZAR PROMOTORES Y PRECIOS");
		printf("\n2-CARGAR VENTAS");
		printf("\n3-BUSCAR SEGURO");
		printf("\n4-BUSCAR SECTOR");
		printf("\n5-INFORMACION DE SEGUROS");
		printf("\n0-FINALIZAR\n");
		printf("\nIngrese un numero ");
		
		scanf("%d",&control);
		
		switch(control){
			
			case 1: 
			inicializar(s,p,x);
			break;
			case 2: 
			carga(s,p,x);
			break;
			case 3:
			busca1(s,p,x);
			break;						
			case 4:
			busca2(s,x);
			break;
			case 5: 
			muestra(s);
			break;	
			case 0:
			break;		
		}
		
		if(control){
		printf("\nPara continuar ingrese 's', para salir ingrese 'n' ");
		fflush(stdin);
		scanf("%c",&a);	
		}
	}
	return;
}
int main(){
	registro seguros;
	arr promotores;
	tabla sectores;
	menu(seguros,promotores,sectores);
}

/*
30
31
32
33
34
35
36
37
36
37
a
sexo
100
b
sexual
100
c
sexualidad
100
*/


	
