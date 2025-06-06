#include<stdio.h>
#define N 5

void carga(int xa[N],int inf){
	
	if(inf<N){
		printf("\nIngrese el valor de la componente %d ",inf+1);
		scanf("%d",&xa[inf]);
		carga(xa,inf+1);
	} else return;
}
void promedio(int xa[N],int sum,int inf,float &xp){
	
	if(inf<N){
		sum+=xa[inf];
		promedio(xa,sum,inf+1,xp);
	}else {
			xp=(float)sum/N;
			return;
	}

}
int superaprom(int xa[N],int xsub[N],int inf,float prom,int j){
	
	if(inf<N){
		
		if(xa[inf]>=prom){
			xsub[j]=xa[inf];
			superaprom(xa,xsub,inf+1,prom,j+1);
		}else superaprom(xa,xsub,inf+1,prom,j);
	}else return j;
}
int mostrar1(int xsub[N],int inf,int sup,float xp,int c1,int &c2){
	
	if(inf<sup){
		
		if(xsub[inf]>xp){
			c1++;
			mostrar1(xsub,inf+1,sup,xp,c1,c2);
		}else c2++;
		mostrar1(xsub,inf+1,sup,xp,c1,c2);
	}else return c1;
}

void quicksort(int arr[ ], int inf, int sup){ 
	int t[N];
	int i,piv,m,n;
	if (inf < sup){
		i=(inf+sup)/2;
		piv=arr[i];
		for( i= inf;i<=sup;i++){
			t[i]=arr[i];
			m=inf; n=sup;
			for(i=inf; i<= sup; i++){
				if (t[i] < piv){
					arr[m]=t[i];
					m=m+1;
				}
				else if (t[i] > piv){
					arr[n]=t[i];
					n=n-1;
				}
				for( i=m;i<=n;i++){
					arr[i]=piv;
					quicksort(arr,inf,m-1);
					quicksort(arr,n+1,sup);
				}
			}
		}
	}
	return;
}
int main(){
	
	int a[N],suba[N],c,cont2=0,num;
	float prom;
	
	carga(a,0);
	promedio(a,0,0,prom);
	c=superaprom(a,suba,0,prom,0);
	printf("\nCantidad de componentes mayores al promedio: %d",mostrar1(suba,0,c,prom,0,cont2));
	printf("\nCantidad de componentes iguales al promedio: %d",cont2);
	quicksort(suba,0,c);
	print(suba,0,c);
	printf("\nIngrese un numero ");
	scanf("%d",&num);
	busquedasecuencial(suba,num,0);
}
