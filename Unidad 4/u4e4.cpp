#include<stdio.h>
#define N 6

void cereo(int arr[N],int inf){
    if(N-1>=inf){
        arr[inf]=0;
        cereo(arr,inf+1);
    }else return;
}

void carga(int arr[N],int i){
    if ((i)&&(i<7)){
        arr[i-1]++;
        printf("\ningrese el lenguaje elegido (finaliza en 0) ");
        scanf("%d",&i);
        return(carga(arr,i));
    }
    else return;        
}


void menos4mil(int arr[N],int inf){
    if(N-1>=inf){
        if(arr[inf]<4/*4000*/){
            printf("\nel lenguaje %d tiene menos de 4 mil encuestados ",inf+1);
            return menos4mil(arr,inf+1);
        }else return menos4mil(arr,inf+1);
    }else return;
}

int masel(int arr[N],int inf,int max){
    static int i;
    if(N-1>=inf){
        if(arr[inf]>max){
            max=arr[inf];
            i=inf;
            return (masel(arr,inf+1,max));
        }else return (masel(arr,inf+1,max));
    }else return(i);
}

int menos5mas9(int arr[N],int inf,int cont5,int &cont9){
    if(N-1>=inf){
        if(arr[inf]<5/*4000*/){
            cont5++;
            return menos5mas9(arr,inf+1,cont5,cont9);
        }else if(arr[inf]>9/*9000*/){
            cont9++;
            return menos5mas9(arr,inf+1,cont5,cont9);
        }
        else return menos5mas9(arr,inf+1,cont5,cont9);
    }else return(cont5);
}

int totalencuestados(int a[N],int inf, int xt){
    if(N-1>=inf){
       xt+=a[inf];
       return totalencuestados(a,inf+1,xt);
    } else return xt;
}

int main(){
    int arr[N];
    int len,m5,m9=0;
    cereo(arr,0);
    printf("\ningrese el lenguaje elegido (finaliza en 0) ");
    scanf("%d",&len);
    carga(arr,len);
    menos4mil(arr,0);
    printf("\nel lenguaje mas elegido fue el nº %d",masel(arr,0,0)+1);
    printf("\nel total de encuestas realizadas fue de %d ",totalencuestados(arr,0,0));
    m5=menos5mas9(arr,0,0,m9);
    printf("\n%d lenguajes fueron elegidos por menos de 5 mil encuestados ",m5);
    printf("\n%d lenguajes fueron elegidos por mas de 9 mil encuestados ",m9);
}
