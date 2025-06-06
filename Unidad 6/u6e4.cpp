#include<stdio.h>
#include<string.h>
#include<windows.h>
#define N 4

typedef char cadena[50];

struct datos{
	cadena titulo;
	cadena autor;
	int cant;
};

void carga(FILE *p){
	
	datos c;
	int i;
	fpos_t x;
	
	for(i=0;i<N;i++){
		fseek(p,0,SEEK_END);
		fgetpos(p,&x);
		int cod=(int)(x/sizeof(datos))+1;		
		printf("\nCodigo de libro: %d \n",cod);
		printf("\nIngrese titulo: ");
		fflush(stdin);
		gets(c.titulo);
		fflush(stdin);
		printf("\nIngrese autor: ");
		fflush(stdin);
		gets(c.autor);
		fflush(stdin);
		printf("\nIngrese cantidad de ejemplares: ");
		scanf("%d",&c.cant);
		fflush(stdin);
		fwrite(&c,sizeof(datos),1,p);
	}
	
}
void busca1(FILE *p,cadena s){
	
	datos a;
	rewind(p);
	;
	while((fread(&a,sizeof(datos),1,p))&&(stricmp(a.titulo,s))){
	}
	if((stricmp(a.titulo,s))==0){
		printf("\nAutor del libro %s: %s",s,a.autor);
	}else printf("\nNo se encontro el titulo");
}
void busca2(FILE *p,cadena s){

	datos a;
	rewind(p);
	while((fread(&a,sizeof(datos),1,p))&&(stricmp(a.autor,s))){
		
	}
	if((stricmp(a.autor,s))==0){
		printf("\nLibros del autor %s: \n",s);
		rewind(p);
		while((fread(&a,sizeof(datos),1,p))){
			
			if(stricmp(a.autor,s)==0){
				
				printf("\n %s",a.titulo);
			}
		}
	}else printf("\nNo se encontro el titulo");
}
void informa(FILE *p,int c){
	
	datos a;
	rewind(p);
	fseek(p,c*sizeof(datos),SEEK_SET);
	fread(&a,sizeof(datos),1,p);
	printf("\nTitulo: %s",a.titulo);
	printf("\nCantidad de ejemplares: %d",a.cant);
}	
void insertar(FILE *p){
	
	datos c;
	fpos_t x;
	printf("\nIngrese titulo: ");
	fflush(stdin);
	gets(c.titulo);
	fflush(stdin);
	fseek(p,0,SEEK_END);
	fgetpos(p,&x);
	int cod=(int)(x/sizeof(datos))+1;	
	printf("\nCodigo del libro %s: %d",c.titulo,cod);
	printf("\nIngrese autor: ");
	fflush(stdin);
	gets(c.autor);
	fflush(stdin);
	printf("\nIngrese cantidad de ejemplares: ");
	scanf("%d",&c.cant);
	fflush(stdin);
	fwrite(&c,sizeof(datos),1,p);
	printf("\nLibro añadido con exito ;)");	
}
int main(){
	
	int i,cod,op;
	FILE *archi;  
	cadena tit;
	system("color 2");

	
	printf("\n ******** MENU DE OPCIONES ***********\n");
	do{
		printf("\n 1- Cargar libros: ");
		printf("\n 2- Buscar por codigo: ");
		printf("\n 3- Buscar por titulo: ");
		printf("\n 4- Buscar por autor: ");
		printf("\n 5- Agregar un libro: ");
		printf("\n 6- Salir: ");
		scanf("%d", &op);
		switch (op){
			case 1: {
				if((archi=fopen("TITULOS.DAT","wb"))==NULL){
					printf("\nError: No se pudo abrir el archivo");
				}
				else{
					carga(archi);
					fclose(archi);
				}
			break;
			}		
			case 2: { 
				if((archi=fopen("TITULOS.DAT","rb"))==NULL){
					printf("\nError: No se pudo abrir el archivo");
				}
				else{
					
					printf("\nIngrese codigo a buscar: ");
					scanf("%d",&cod);
					informa(archi,cod-1);
					fclose(archi);
				}			
			break;
			}
			case 3: {
				if((archi=fopen("TITULOS.DAT","rb"))==NULL){
					printf("\nError: No se pudo abrir el archivo");
				}
				else{
					
					printf("\nIngrese titulo a buscar: ");
					fflush(stdin);
					gets(tit);
					fflush(stdin);
					busca1(archi,tit);	
					fclose(archi);
				}				

			break;
			}
			case 4: { 
				if((archi=fopen("TITULOS.DAT","rb"))==NULL){
					printf("\nError: No se pudo abrir el archivo");
				}
				else{
					
					printf("\nIngrese autor a buscar: ");
					fflush(stdin);
					gets(tit);
					fflush(stdin);
					busca2(archi,tit);
					fclose(archi);	
					}
				
			break;
			}
			
			case 5: { 
				if((archi=fopen("TITULOS.DAT","ab"))==NULL){
					printf("\nError: No se pudo abrir el archivo");
				}
				else insertar(archi);
				fclose(archi);
			break;
			}
		}
		
		Sleep(3000);
		system("cls");
	} while (op !=6);
}

/*
1
como hacer una mesa de luz
ignacio aguilar
900
como no hacer una mesa de luz
ignacio aguilar
3
como hacer pan
peter pan
700
como perder amigos
uni
62
*/