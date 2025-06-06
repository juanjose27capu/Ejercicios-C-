#include<stdio.h>
#define f 5
#define c 4

void cerear(int arr[f][c]){
    int i,j;
    
    for(i=0;i<c;i++){
        for(j=0;j<f;j++){
            arr[i][j]=0;
        }
    }
    return;
}

void carga(int a[f][c]){
    int x,y,i,j,valor;
    for(i=0;i<f*c;i++){
        printf("\nIngrese el numero de fila: ");
        scanf("%d",&x);
        printf("\nIngrese el numero de columna: ");
        scanf("%d",&y);
        printf("\nIngrese valor: ");
        scanf("%d",&valor);
        a[x-1][y-1]=valor;
    }
    for(i=0;i<f;i++){
        for(j=0;j<c;j++){
            printf("%d     ",a[i][j]);
        }
        printf("\n");
    }
}

void sumafilas(int arr[f][c]){
	int x,y,sum,sumtotal=0;
	
	for(x=0;x<f;x++){
		sum=0;
		for(y=0;y<c;y++){
			sum+=arr[x][y];
		}
		printf("\nSuma de los elementos de la fila %d: %d",x+1,sum);
		sumtotal+=sum;
	}	
		printf("\nSuma de todas las filas: %d", sumtotal);
}

void prom3c(int arr[f][c]){
	int x,sum=0;
	float prom;
	
	for(x=0;x<f;x++){
		sum+=arr[x][2];
	}
	prom=(float)sum/f;
	printf("\nPromedio de la tercera columna: %10.2f",prom);
}

void mayoresa100(int arr[f][c]){
	int x,y,cont=0;
	
	for(x=0;x<f;x++){
		for(y=0;y<c;y++){
			if(arr[x][y]>100){
				cont++;
			}
		}
	}
	printf("\nNumeros mayores a 100: %d", cont);
}

int main(){
	int a[f][c];
 
 	cerear(a);
	carga(a);
	sumafilas(a);
	prom3c(a);
	mayoresa100(a);
}


/*
1
1
12
1
2
15
1
3
18
1
4
1
2
1
3
2
2
4
2
3
9
2
4
7
3
1
5
3
2
8
3
3
2
3
4
0
4
1
155
4
2
16
4
3
300
4
4
188
5
1
177
5
2
19
5
3
199
5
4
200
*/
