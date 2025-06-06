#include<stdio.h>
#include<malloc.h>
#define M 2
struct ipv{
    int dni;
    float monto;
};
void carga(ipv *x,int i,int n){
    if(i<n){
        printf("\nIngrese DNI del adjudicatario %d ",i+1);
        scanf("%d",&x[i].dni);
        printf("\nIngrese monto del adjudicatario %d ",i+1);
        scanf("%f",&x[i].monto); 
        carga(x,i+1,n);       
    } else return;
}
void busca(int x[M],ipv *y,int numero,int i,int j){
    if(i<M){
        if(j<x[i]){
            if(numero==y[j].dni){
                printf("\nEl DNI %d se adhirio al plan %d",numero,i+1);
                printf("\nMonto: %.2f",y[j].monto);
                return;
            } else busca(x,y,numero,i,j+1);
        }else busca(x,y,numero,i+1,0);
    }else printf("\nDNI no encontrado");
    return;
}


int main(){
    
    ipv *p;
    int a[M],i,num;
    for(i=0;i<M;i++){
        printf("\nIngrese cantidad de adjudicatarios del plan nro %d ",i+1);
        scanf("%d",&a[i]);
        p=(ipv*)malloc(sizeof(ipv)*a[i]);
        carga(p,0,a[i]);
        printf("\nIngrese un DNI ");
        scanf("%d",&num);
        busca(a,p,num,0,0);
        free(p);        
    }
}
