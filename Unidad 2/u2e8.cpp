#include<stdio.h>
#define m 2
#define d 2

void cerear(float s[m][d]) {
    int i,j;

    for(i=0; i<m; i++) {
        for(j=0; j<d; j++) {
            s[i][j]=0;
        }
    }
    return;
}

void carga(float s[m][d]){
	int mes,dpto;
	float imp;
	
	printf("\nIngrese mes de ventas, finalice con cero: ");
	scanf("%d",&mes);
	while(mes!=0){
		if (mes<=12){
			
			do{
			printf("\nIngrese departamento de ventas: ");
			scanf("%d",&dpto);
			
			if(dpto<=8){
				printf("\nIngrese importe de ventas: ");
				scanf("%f",&imp);
				s[mes-1][dpto-1]=imp;
				}	
			else printf("\nDepartamento no valido");
			
			}while(dpto>8);
		}
		else printf("\nMes no valido");
		
		printf("\nIngrese mes de ventas, finalice con cero: ");
		scanf("%d",&mes);
	}
	printf("\n");
	return;
}

void muestramatriz(float s[m][d]){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<d;j++){
            printf("%10.2f    ",s[i][j]);
        }
        printf("\n");
    }
    return;
}

void menosventas(float s[m][d],int xm){
	int i,n;
	float min=99999999999;
	
	for(i=0;i<d;i++){
		if(s[xm-1][i]<min){
			min=s[xm-1][i];
			n=i;
		}
	}
	printf("\nEl departamento que menos vendio en el mes %d fue el numero %d",xm,n+1);
	return;
}

float ventapromedio(float s[m][d]){
	int i,j;
	float sumfila,sumtotal=0;
	
	for(i=0;i<m;i++){
		sumfila=0;
		
		for(j=0;j<d;j++){
			sumfila+=s[i][j];
		}
		sumtotal+=sumfila;
	}
	return(sumtotal/(m*d));
}

void superaprom(float s[m][d],int xm,int xd,float p){
	if(s[xm-1][xd-1]>p){
		printf("\nEl importe de ventas del departamento %d en el mes %d supera el promedio",xd,xm);
	} else printf("\nEl importe de ventas del departamento %d en el mes %d NO supera el promedio",xd,xm);
	return;
}

int main() {
	float super[m][d],prom;
	int xmes,xdpto;
	
	cerear(super);
	carga(super);
	muestramatriz(super);
	
	printf("\nIngrese un mes: ");
	scanf("%d",&xmes);
	menosventas(super, xmes);
	
	prom=ventapromedio(super);
	printf("\nImporte de ventas promedio del supermercado: %10.2f",prom);
	
	printf("\nIngrese un mes: ");
	scanf("%d",&xmes);
	printf("\nIngrese un departamento: ");
	scanf("%d",&xdpto);
	superaprom(super,xmes,xdpto, prom);
}

/*
1
1
50000
1
2
8700
2
1
30.58
2
2
500.51
0
*/


