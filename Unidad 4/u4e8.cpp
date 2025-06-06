#include<stdio.h>
#define N 3

void carga(int m[N][N],int i,int j){
	
	if(i<N){
		if(j<N){
			scanf("%d",&m[i][j]);
			carga(m,i,j+1);
		}else carga(m,i+1,0);
	}else return;
}
void diagonal(int m[N][N],int i,int j,int sum){

	if(i<N){
			sum+=m[i][i];
			diagonal(m,i+1,0,sum);
		}
	else{
		printf("\nSuma de elementos de la diagonal: %d",sum);
	} return;	
}

int main(){
	
	int matriz[N][N];
	carga(matriz,0,0);
	diagonal(matriz,0,0,0);
}
