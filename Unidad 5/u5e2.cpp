#include<stdio.h>
#include<malloc.h>
struct fab{
    int dni;
    char cat;
    float peso;
};
void carga(fab *x,int i,int j){

    if(i<j){
    
        printf("\nIngrese DNI del participante %d: ",i+1);
        scanf("%d",&x[i].dni);       
        printf("\nIngrese categoria: ");
        fflush(stdin); 
		scanf("%c",&x[i].cat);
        while(((x[i].cat<'a')||(x[i].cat>'a'))&&(x[i].cat<'h')||(x[i].cat>'h')){
            printf("\nCategoria incorrecta");
            printf("\nIngrese categoria: ");
            fflush(stdin);
            scanf("%c",&x[i].cat);
        }        
        printf("\nIngrese peso: ");
        scanf("%f",&x[i].peso);
        carga(x,i+1,j);
        } else return;
}
float pesomax(fab *x,int i,int j,float max,char ce){

	if(i<j){
		
		if(x[i].cat==ce){
			
			if(x[i].peso>max){
				
				max=x[i].peso;
				pesomax(x,i+1,j,max,ce);
			}else pesomax(x,i+1,j,max,ce);
		}else pesomax(x,i+1,j,max,ce);
	}else return max;
}
int comparar(fab *x,int i,int j,char ce,int *y,float max){
    static int c=0;
    if(i<j){
        if(x[i].cat==ce){
            if(x[i].peso==max){
                printf("\nParticipante %d,DNI: %d",i+1,x[i].dni);
                y[c]=x[i].dni;
                c++;
                comparar(x,i+1,j,ce,y,max);
            }else comparar(x,i+1,j,ce,y,max);
        }else comparar(x,i+1,j,ce,y,max);
    }else return c;
}
void cereopesos(int *x,int i,int j){
	
	if(i<j){
		
		x[i]=0;
		cereopesos(x,i+1,j);
	}else return;
}
void cuantopeso(fab *x,int i,int j,int *cp){
	
	if(i<j){
		
		if((x[i].peso>=47)&&(x[i].peso<=90)){
			
			cp[(int)x[i].peso-47]++;
			cuantopeso(x,i+1,j,cp);
		}else cuantopeso(x,i+1,j,cp);
	}else return;
}
void muestra(int *x,int i,int j){
	
	if(i<j){
		
		printf("\nPeso: %d Kg",i+47);
		printf("\nBoxeadores: %d",x[i]);
		printf("\n");
		muestra(x,i+1,j);
	}else return;
}
int main(){

    fab *p;
    int *cc,cant,aux,*pesos;
    char catt;
    
    printf("\nIngrese la cantidad de ingresantes: ");
    scanf("%d",&cant);
    p=(fab*)malloc(sizeof(fab)*cant);
    cc=(int*)malloc(sizeof(int)*cant);
    pesos=(int*)malloc(sizeof(int)*43);
    carga(p,0,cant);    
    printf("\nIngrese una categoria: ");
    fflush(stdin);
    scanf("%c",&catt);
    while(((catt<'a')||(catt>'a'))&&(catt<'h')||(catt>'h')){
        printf("\nCategoria incorrecta");
        printf("\nIngrese una categoria: ");
        fflush(stdin);
        scanf("%c",&catt);
    }     
	printf("\nBoxeadores con peso maximo de la categoria %c",catt);    
    aux=comparar(p,0,cant,catt,cc,pesomax(p,0,cant,0,catt));
    cereopesos(pesos,0,43);
	cuantopeso(p,0,cant,pesos);
	printf("\n");
    printf("\nCantidad de boxeadores por peso");
    muestra(pesos,0,43);
}
