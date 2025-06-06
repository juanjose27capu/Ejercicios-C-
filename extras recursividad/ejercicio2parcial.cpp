#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M 8
#define E 5

void carga(float S[M][E]){
	for(int i=0; i<M; i++){
		for(int j=0; j<E; j++){
			printf("ingrese el sueldo del empleado %d\n", j+1);
			scanf("%f", &S[i][j]);
		}
	}
}
void mostrar(float S[M], int i){
	if(i<E){
		printf("el sueldo que cobro el empleado %d es %.2f\n", i+1, S[i]);
		printf("\n");
		mostrar(S,i+1);
	}else
	return;
}

void calcula(float S[M][E], int i, int j){
	float sum;
	for(i=0; i<M; i++){
		sum=0;
		for(j=0; j<E; j++){
			sum+=S[i][j];
		}
		printf("el sueldo promedio del empleado %d es de %.2f\n", j+1, sum/E);
		printf("\n");
	}
	
}


int main(){
	float sueldo[M][E];
	carga(sueldo);
	printf("sueldo que cobro cada empleado en el mes 7\n");
	printf("\n");
	mostrar(sueldo[6],0);
	printf("sueldo promedio de cada empleado:\n");
	printf("\n");
	calcula(sueldo, 0, 0);
	
}
