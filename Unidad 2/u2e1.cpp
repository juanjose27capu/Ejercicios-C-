#include <stdio.h>
const int N = 20;


void carga(int arr[N]){
	int i;
	for (i=0;i<N;i++){
		printf ("ingresar numero %d ", i);
		scanf ("%d",&arr[i]);
	}
}

void indicapar(int arr[N]){
	int i;
	for (i=0;i<N;i++){
		if (i%2==0){
			printf(" \nel componente %d es %d \n",i,arr[i]);
		}
	}
}
void escero(int arr[N]){
	int i;
	i=0;
	while((i<N)&&(arr[i]!=0)){
		i++;
	}
	if (i<N)
		printf(" \n existe un 0 \n");
		else printf(" \n no existe un 0 \n");
}
numrpar (int arr[N]){
	int i;int npar;
	npar = 0;
	for (i=0;i<N;i++){
		if ((arr[i])%2 == 0){
			npar++;
		}
	}
	printf("\n existen %d numeros pares ",npar);
}


int main(){
	int a[N];
	carga(a);
	indicapar(a);	
	escero(a);
	numrpar(a);
}

/*
0
1
5
15
20
20
70
588
172
0
6
5
2
1
3
8
48
5
6
3
5
*/
