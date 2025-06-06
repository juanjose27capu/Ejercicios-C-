#include<stdio.h>
#include<malloc.h>

void carga(int *x,int i,int j){

    if(i<j){
    
        printf("\nIngrese el valor de la componente %d: ",i+1);
        scanf("%d",&x[i]);
        carga(x,i+1,j);
    }
    else return;
}
void escalar(int *x,int *y,int x1,int y1){

    int i,esc=0;
    if(x1==y1){
    
        for(i=0;i<x1;i++){
        
            esc+=x[i]*y[i];
        
        }
        printf("\nEl producto escalar entre ambos arreglos es: %d",esc);
    } else printf("\nNo se puede realizar el producto escalar por diferencia de dimensiones");
    return;
}
int impares(int *x,int *&y,int j){

    int i,c=0;
    y=(int*)malloc(sizeof(int)*j);
    for(i=0;i<j;i++){
    
        if(x[i]%2!=0){
        
            y[c]=x[i];
            c++;
        }
    
    }
    return c;  
}
void muestra(int *x,int i,int j){

    if(i<j){
   
        printf("%d  ",x[i]);
        muestra(x,i+1,j);
    }
    else return;
}
int main(){

    int *p,*q,*s,ap,aq,num,in;
    
    printf("\nIngrese la dimension del arreglo 1: ");
    scanf("%d",&ap);
    printf("\nIngrese la dimension del arreglo 2: ");
    scanf("%d",&aq);    
    p=(int*)malloc(sizeof(int)*ap);
    q=(int*)malloc(sizeof(int)*aq);
    printf("\nCarga del arreglo 1:");
    carga(p,0,ap);
    printf("\nCarga del arreglo 2: ");
    carga(q,0,aq); 
    escalar(p,q,ap,aq);
    printf("\nSeleccione uno de los dos arreglos: ");
    scanf("%d",&num);
    switch(num){
        case 1: in=impares(p,s,ap);
        break;
        case 2: in=impares(q,s,aq);
        break; }
    printf("\nArreglo 1\n");
    muestra(p,0,ap);
    printf("\nArreglo 2\n");
    muestra(q,0,aq);
    printf("\nSubarreglo de impares del arreglo %d\n",num);   
    muestra(s,0,in);  
}