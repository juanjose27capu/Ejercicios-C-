#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef char cadena[50];
struct datos{
    int num,cant,cuotas;
    cadena apellido,nombre;
    float imp;
};
struct integrantes{
    cadena nom,ape;
    int cant;
};
void carga(FILE *archivo){

    datos c;
    
    printf("\nIngrese numero de aspirante, finalice con cero: ");
    scanf("%d",&c.num);
    while(c.num){
    
        printf("\nIngrese apellido: ");
        fflush(stdin);
        scanf("%s",&c.apellido);
        fflush(stdin);
        printf("\nIngrese nombre: ");
        fflush(stdin);
        scanf("%s",&c.nombre);
        fflush(stdin);
        printf("\nIngrese cantidad de integrantes del grupo familiar: ");
        scanf("%d",&c.cant);
        printf("\nIngrese cantidad de cuotas: ");
        scanf("%d",&c.cuotas);
        printf("\nIngrese importe de la cuota: ");
        scanf("%f",&c.imp);
        fwrite(&c,sizeof(datos),1,archivo);
        printf("\nIngrese numero de aspirante, finalice con cero: ");
        scanf("%d",&c.num);
    }
}
void listar(FILE *archivo){

    datos c;
    
    rewind(archivo);
    while(fread(&c,sizeof(datos),1,archivo)){
    
        if((c.imp*c.cuotas)>77500){
        
            printf("Nombre: %s, Apellido: %s,Cantidad de cuotas: %d, Importe total abonado: %.2f\n",c.nombre,c.apellido,c.cuotas,c.cuotas*c.imp);
        }
    }
}
void busca(FILE *archivo,cadena n,cadena a){

    datos c;
    
    rewind(archivo);
    while((fread(&c,sizeof(datos),1,archivo)&&(strcmp(c.nombre,n))&&(strcmp(c.apellido,a)))){
    }
    if((strcmp(c.nombre,n)==0)&&(strcmp(c.apellido,a)==0)){
        printf("\nCantidad de cuotas: %d, Cantidad de integrantes: %d",c.cuotas,c.cant);
    }else printf("\nNombre y apellido no encontrado");
}
void carga2(integrantes *&p,int c){

    int i;
    
    for(i=0;i<c;i++){
        
        printf("\nIntegrante nro %d",i+1);
        printf("\nIngrese nombre: ");
        fflush(stdin);
        scanf("%s",&p[i].nom);
        fflush(stdin);
        printf("\nIngrese apellido: ");
        fflush(stdin);
        scanf("%s",&p[i].ape);
        fflush(stdin);
        printf("\nIngrese cantidad de integrantes: ");
        scanf("%d",&p[i].cant);
    }
}
void ordena(integrantes *&p,int c){

    int i,k=1,cota=c-1;
    integrantes aux;
    
    while(k!=-1){
    
        k=-1;
        for(i=0;i<cota-1;i++){
        
            if(strcmp(p[i].nom,p[i+1].nom)>0){
            
                aux=p[i];
                p[i]=p[i+1];
                p[i+1]=aux;
                k=i;
            }
        }
        cota=k;
    }
    printf("\nListado ordenado por nombre:\n");
    for(i=0;i<c;i++){
    
        printf("\nNombre: %s,Apellido: %s\n",p[i].nom,p[i].ape);
    }
}
int main(){

    FILE *archi;
    int op;
    datos c;
    integrantes *p;
    cadena nom,ap;
    do{
        
        printf("\n*********MENU DE OPCIONES*********");
        printf("\n1-Cargar datos de aspirantes");
        printf("\n2-Listar");
        printf("\n3-Buscar por nombre y apellido");
        printf("\n4-Generar estructura");
        printf("\n5-Salir");
        printf("\nIngrese una opcion: ");
        scanf("%d",&op);
        switch(op){
        
            case 1:{
                archi=fopen("ASPIRANTES.DAT","wb");
                carga(archi);
                fclose(archi);
            }
            break;
            case 2:{
                archi=fopen("ASPIRANTE.DAT","rb");
                printf("\nAspirantes que abonaron mas de 77.500 pesos: \n");
                listar(archi);
                fclose(archi);
            }
            break;
            case 3:{
                archi=fopen("ASPIRANTE.DAT","rb");
                printf("\nIngrese apellido: ");
                scanf("%s",&ap);
                printf("\nIngrese nombre: ");
                scanf("%s",&nom);
                busca(archi,nom,ap);
                fclose(archi);
            }
            break;
            case 4:{
                archi=fopen("ASPIRANTE.DAT","rb");
                rewind(archi);
                
                printf("\nCarga de aspirantes con mas de 5 integrantes familiares:\n");
                while(fread(&c,sizeof(datos),1,archi)){
                    
                    if(c.cant>5){
                        
                        printf("\nFamilia de %s %s: ",c.nombre,c.apellido);
                        p=(integrantes*)malloc(sizeof(integrantes)*c.cant);
                        carga2(p,c.cant);
                        ordena(p,c.cant);
                    }
                }
                fclose(archi);
            }
            break;
        }
    }while(op!=5);
}