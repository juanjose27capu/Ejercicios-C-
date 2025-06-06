#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef char cadena[50];
struct datos{
    int nro;
    float consumo;
    cadena dpto;
};
struct nodo{
    datos info;
    nodo *sig;
};
typedef nodo *puntero;
void carga(FILE *archivo){

    datos c;
    printf("\nIngrese numero de cuenta, finalice con cero: ");
    scanf("%d",&c.nro);
    while(c.nro){
        printf("\nIngrese consumo en KB: ");
        scanf("%f",&c.consumo);
        printf("\nIngrese departamento en el que reside: ");
        fflush(stdin);
        scanf("%s",&c.dpto);
        fflush(stdin);
        fwrite(&c,sizeof(datos),1,archivo);
        printf("\nIngrese numero de cuenta, finalice con cero");
        scanf("%d",&c.nro);
    }    
}
void generalistas(FILE *archivo,puntero &xp1,puntero &xp2){

    puntero nuevo;
    datos c;
    rewind(archivo);
    while(fread(&c,sizeof(datos),1,archivo)){
        if(c.consumo<100){
            nuevo=(puntero)malloc(sizeof(nodo));
            nuevo->info=c;
            nuevo->sig=xp1;
            xp1=nuevo;
        }else{
            nuevo=(puntero)malloc(sizeof(nodo));
            nuevo->info=c;
            nuevo->sig=xp2;
            xp2=nuevo;
        }
    }
}
void generasubsi(FILE *archivo, puntero xp){

    while(xp!=NULL){
        fwrite(&xp->info,sizeof(datos),1,archivo);
    }
}
int consumoprom(FILE *archivo,float prom){

    datos c;
    int aux,cont=0;
    float sum=0,min=99999999;
    rewind(archivo);
    while(fread(&c,sizeof(datos),1,archivo)){
        cont++;
        sum+=c.consumo;
        if(c.consumo<min){
            min=c.consumo;
            aux=c.nro;
        }
    }
    prom=(float)sum/cont;
    return aux;
}
void generasinsubsi(FILE *archivo,puntero xp){

    while(xp!=NULL){
        fseek(archivo,0,SEEK_END);
        fwrite(&xp->info,sizeof(datos),1,archivo);
    }
}
void informa(FILE *archivo){

    datos c;
    fseek(archivo,4*sizeof(datos),SEEK_SET);
    fread(&c,sizeof(datos),1,archivo);
    printf("\nCliente 5: Numero de cuenta: %d, Consumo: %.2f KB, Departamento: %s",c.nro,c.consumo,c.dpto);    
}
int main(){

    FILE *archi1,*archi2,*archi3;
    puntero cabeza1=NULL,cabeza2=NULL;
    float cprom;
    int usuario;
    
    archi1=fopen("energiasj.dat","wb");
    carga(archi1);
    fclose(archi1);
    archi1=fopen("energiasj.dat","rb");
    generalistas(archi1,cabeza1,cabeza2);
    fclose(archi1);
    archi2=fopen("Subsidiados.dat","wb");
    generasubsi(archi2,cabeza1);
    fclose(archi2);
    archi2=fopen("Subsidiados.dat","rb");
    usuario=consumoprom(archi2,cprom);
    printf("\nConsumo promedio de los subsidiados: %.2f KB",cprom);
    printf("\nEl usuario con menor consumo fue el numero %d",usuario);
    fclose(archi2);
    archi3=fopen("SinSubsidio.dat","wb");
    generasinsubsi(archi3,cabeza2);
    fclose(archi3);
    archi3=fopen("SinSubsidio.dat","rb");
    informa(archi3);
    fclose(archi3);
}