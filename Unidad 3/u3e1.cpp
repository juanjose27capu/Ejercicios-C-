#include <stdio.h>
#include <stdlib.h>
#define N 49

void carga(int ar[N]){
	int i;
	for(i=0;i<=N;i++){
		ar[i]=(rand()%200)-100;
		printf ("\n %d",ar[i]);
	}
}

int main(){
	int arr[N];
	int contmas,contmenos,i,num;
	carga(arr);
	
	contmas = 0;
	contmenos = 0;
	{//masmenos
	
	for(i=0;i<=N;i++){
		if(arr[i]>0){
			contmas++;
		}else if(arr[i]<0){
			contmenos++;
		}
	}
	
	if (contmas>=contmenos){printf("\nhay mas numeros mayores a 0");}
	else{printf("\nhay mas numeros menores a 0");}
}
	{//parimpar
		contmas=0;
		contmenos=0;
		for(i=0;i<=N;i++){
			if(i %2 == 0){contmas+=arr[i];}
			else {contmenos+=arr[i];}	
		}
		printf("\nsumatoria de pares %d",contmas);
		printf("\nsumatoria de impares %d",contmenos);		
	}
	{//coso
		printf("\ningresar numero ");
		scanf("%d",& num);
		
		for(i=0;i<=N;i++){
			if(arr[i]==num){printf("\nel numero se encuentra en la posicion %d",i+1);}
		}
	}
}