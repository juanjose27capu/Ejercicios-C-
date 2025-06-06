#include<stdio.h>
#define M 6
#define N 8
typedef float arr[M][N];
void cereo(arr v){
	
	int i,j;
	
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			v[i][j]=0;
		}
	}
	return;
}
void carga(arr v){
	
	int mes,dpto;
	float imp;
	
	printf("\nVentas de los ultimos 6 meses");
	printf("\nIngrese un mes, finalice con cero: ");
	scanf("%d",&mes);
	while(mes){
		
		if((mes>=6)&&(mes<=12)){
			
			do{
				printf("\nIngrese un departamento de ventas: ");
				scanf("%d",&dpto); 
				if((dpto<=8)&&(dpto>0)){
					
					printf("\nIngrese importe de ventas: ");
					scanf("%f",&imp);
					v[mes-6][dpto-1]=imp;
					
				}
				else {printf("\nNumero de departamento incorrecto");}
				
			}while((dpto<=0)||(dpto>8));
			
		}
		else {printf("\nMes incorrecto");}
		printf("\nIngrese un mes, finalice con cero: ");
		scanf("%d",&mes);	
			
	}return;
}
void muestramatriz(arr v){
    int i,j;
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            printf("%10.2f    ",v[i][j]);
        }
        printf("\n");
    }
    return;
}
int menorimp(arr v,float &p){
	
	int i,j,aux;
	float sum,sumtotal=0,min=99999999999999;
	
	for(j=0;j<N;j++){
		sum=0;
		for(i=0;i<M;i++){
			sum+=v[i][j];
		}
		sumtotal+=sum;
		if(sum<min){
		
			min=sum;
			aux=j;
		}
	}
	p=sumtotal/(M*N);
	return aux;
}
void superaprom(arr v,float p){
	
	int i,j;
	float sum=0;
	for(j=0;j<N;j++){
		sum=0;
		for(i=0;i<M;i++){
			sum+=v[i][j];
		}
		if(sum>p){
			printf("\nEl departamento %d supera la venta promedio",j+1);
			printf("\nImporte total vendido a lo largo del semestre: %0.2f",sum);
			printf("\n");
		}
	}
}
int main(){
	

	arr ventas;
	float prom;
	
	cereo(ventas);
	carga(ventas);
	printf("\n");
	muestramatriz(ventas);
	printf("\nEl departamento que menor importe de ventas tuvo fue el %d",menorimp(ventas,prom)+1);
	printf("\n");
	printf("\nImporte de ventas promedio del supermercado: %0.2f",prom);
	printf("\n");
	superaprom(ventas,prom);
	
}

/*
6
1
2
6
2
10
7
1
3
7
2
1
8
1
0
8
2
2
0
*/
