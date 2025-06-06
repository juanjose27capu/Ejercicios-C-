#include<stdio.h>

void tablamult(int num,int m){
    if(m<=10){
        printf("\n%d",num*m);
        return(tablamult(num,m+1));
    }
    else return;
}

int main(){
    int numero;
    printf("\nIngrese un numero entre 1 y 9 ");
    scanf("%d",&numero);
    tablamult(numero,1);
}
