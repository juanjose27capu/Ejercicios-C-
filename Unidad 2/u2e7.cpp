#include<stdio.h>
#define f 30
#define m 80

void cerear(int d[f][m]) {
    int i,j;

    for(i=0; i<f; i++) {
        for(j=0; j<m; j++) {
            d[i][j]=0;
        }
    }
    return;
}

void carga(int d[f][m]) {
    int cod,i,cant;

    printf("\nVentas");

    for(i=0; i<f; i++) {
        printf("\nFarmacia numero %d",i+1);
        printf("\nIngrese codigo de medicamento, finalice con cero: ");
        scanf("%d",&cod);

        while(cod!=0) {

            if((cod>=100)&&(cod<=179)) {
                printf("\nIngrese cantidades vendidas del codigo ingresado: ");
                scanf("%d",&cant);
                d[i][cod-100]+=cant;
            }
            else {
                printf("\nCodigo de medicamento incorrecto");
            }
            printf("\nIngrese codigo de medicamento, finalice con cero");
            scanf("%d",&cod);
        }
    }
    return;
}

void muestramatriz(int d[f][m]){
    int i,j;
    for(i=0;i<f;i++){
        for(j=0;j<m;j++){
            printf("%d    ",d[i][j]);
        }
        printf("\n");
    }
    return;
}

void mostrar(int d[f][m]) {
    int i,j,sum;
    printf("\nTotal unidades vendidas por codigo");
    for(i=0; i<m; i++) {
        sum=0;
        for(j=0; j<f; j++) {
            sum+=d[j][i];
        }
        printf("\nMedicamento %d: %d unidades",i+100,sum);
    }
    return;
}

void maximo(int d[f][m],int cf) {
    int j,n,max=-1;

    for(j=0; j<m; j++) {
        if(d[cf-1][j]>max) {
            max=d[cf-1][j];
			n=j;
        }
    }
    printf("\nEl medicamento mas vendido de la farmacia %d es el %d",cf,n+100);
    return;
}

int main() {

    int cantmed[f][m],codfarm;

    cerear(cantmed);
    carga(cantmed);
    muestramatriz(cantmed);
    mostrar(cantmed);

    printf("\nIngrese un codigo de farmacia: ");
    scanf("%d",&codfarm);
    maximo(cantmed,codfarm);
}

/*
100
25
101
30
102
500
0
100
900
101
36
102
80
0
100
95
101
3
102
780
0
*/