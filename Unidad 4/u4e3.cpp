#include <stdio.h>

int maximo_comun_divisor (int a, int b)
{
    if(b){
        return(maximo_comun_divisor(b,a%b));
    } else {return(a);}
}
/*
    while (b != 0)
    {
        temporal = b;
        b = a % b; // % es el modulo entre a y b
        a = temporal;
    }
    return a;
}*/
int main(void)
{   int a, b;
    printf("ingrese numero a \n");
    scanf("%d",&a);
    printf("Ingrese numero b \n");
    scanf("%d",&b);
    printf("MCD de a y b: %d\n", maximo_comun_divisor(a, b));
    getchar();
}