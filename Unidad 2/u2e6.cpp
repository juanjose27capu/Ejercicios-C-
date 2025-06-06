#include<stdio.h>
#define f 4
#define c 6


void cerear(int ca[c][f]){
    int i,j;
    
    for(i=0;i<c;i++){
        for(j=0;j<f;j++){
            ca[i][j]=0;
        }
    }
    return;
}

void carga(int ca[c][f]){
    int at,turno;
    
    printf("\nIngrese area tematica, finalie con cero: ");
    scanf("%d",&at);
    
    while(at!=0){
    
        if(at<=6){
        
            do{
            
            printf("\nIngrese turno: ");
            scanf("%d",&turno);
            
            if(turno<=4){
            
               ca[at-1][turno-1]++;
            }
            
            else printf("\nNumero de turno incorrecto");}
            
            while(turno>4);}
        
        else printf("\nNumero de area tematica incorrecto");
        
        printf("\nIngrese area tematica, finalie con cero: ");
        scanf("%d",&at);
    }
    printf("\n");
    return;
}

void muestramatriz(int ca[c][f]){
    int i,j;
    for(i=0;i<c;i++){
        for(j=0;j<f;j++){
            printf("%d    ",ca[i][j]);
        }
        printf("\n");
    }
    return;
}

void inscriptos(int ca[c][f]){
     int i,j;
    
    printf("\nCantidad de Inscriptos:\n");
    for(i=0;i<c;i++){
        printf("\nArea Tematica Numero %d", i+1);
        for(j=0;j<f;j++){
            printf("\nTurno %d: %d inscriptos", j+1,ca[i][j]);
        }
    }
    printf("\n");
    return;
}

void dapromedio(int ca[c][f], int xat){
    int j,sum,prom;
    sum=0;
    if(xat<=c){
        for(j=0;j<f;j++){
            sum+=ca[xat-1][j];
        }
        prom=(int)sum/f;
        printf("\nCantidad de alumnos promedio del area tematica numero %d: %d", xat,prom);
    }
    else printf("\nArea tematica no existente");
    return;
}

int main(){
    int cantalum[c][f],atem;
    
    cerear(cantalum);
    carga(cantalum);
    muestramatriz(cantalum);
    inscriptos(cantalum);
    
    printf("\nIngrese un area tematica para la busqueda: ");
    scanf("%d",&atem);
    dapromedio(cantalum, atem);
}
