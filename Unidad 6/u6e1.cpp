#include<stdio.h>
#include<string.h>
typedef char cadena[50];
struct datos{
	cadena nomb;
	int edad;
};

void carga(FILE *archi){
	
	datos a;
	
	printf("\nIngrese el nombre del asistente, finalice con FIN: ");
	fflush(stdin);
	gets(a.nomb);
	fflush(stdin);
	
	while(stricmp(a.nomb,"FIN")){
		
		printf("\nIngrese edad del asistente: ");
		scanf("%d",&a.edad);
		fwrite(&a,sizeof(a),1,archi);
		printf("\nIngrese el nombre del asistente, finalice con FIN: ");
		fflush(stdin);
		gets(a.nomb);
		fflush(stdin);			
	}
}
void mostrar(FILE *xarchi){

	datos a;
	rewind(xarchi);
	while(fread(&a,sizeof(a),1,xarchi)!=0 ){
		
		if(a.edad>40){
			printf("\n Nombre: %s, Edad: %d\n",a.nomb,a.edad);
		}
	}
}
int prom(FILE *xarchi){

	datos a;
	int sum=0,cont=0;
	rewind(xarchi);
	while(fread(&a,sizeof(a),1,xarchi)!=0 ){
		sum+=a.edad;
		cont++;
	}	
	return (int)sum/cont;
}
int main(){
	
	FILE *archi;
	
	if((archi=fopen("asistentes.dat","wb"))==NULL){
		printf("hay error1 \n");
	}
	else{
		
		carga(archi);
		fclose(archi);
	}
	if ((archi=fopen("asistentes.dat","rb"))==NULL){
		
		printf("hay error1 \n");
	}
	else{
		printf("\nAsistentes mayores a 40 años:");
		mostrar(archi);
		printf("\nEdad promedio: %d años",prom(archi));
	}
}

/*
juan
50
igna
26
jeronimo
100
alejandra
30
fin
*/
