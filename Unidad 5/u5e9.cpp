#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<windows.h>
typedef char cadena[50];
struct nodo1{
	cadena carrera;
	cadena nombre;
	nodo1 *sig;
};
typedef nodo1 *puntero1;
struct nodo2{
	int cod;
	nodo1 *alumnos;
	nodo2 *sig;
};
typedef nodo2 *puntero2;
void crear2(puntero2 &xp2){
	xp2=NULL;
}
puntero2 busca2(puntero2 p2,int c){
	while((p2!=NULL)&&(p2->cod!=c)){
		p2=p2->sig;
	}return p2;
}
void insertar1(puntero1 &xp1){
	
	puntero1 nuevo1,p1,anterior1;
	nuevo1=(puntero1)malloc(sizeof(nodo1));
	printf("\nIngrese nombre del alumno: ");
	fflush(stdin);
	gets(nuevo1->nombre);
	fflush(stdin);
	printf("\nIngrese carrera del alumno: ");
	fflush(stdin);
	gets(nuevo1->carrera);
	fflush(stdin);			
	nuevo1->sig = NULL;
	if (xp1==NULL){ 
	xp1=nuevo1;
	}	
	else{
		p1=xp1; 
		while (p1!=NULL){ 
			anterior1=p1;
			p1=p1->sig;
		}
		anterior1->sig=nuevo1;
	}
	return;
}
void cargaalum(puntero2 &xp2,int c){
	puntero2 p2;
	if(xp2!=NULL){
		p2=busca2(xp2,c);
		if(p2!=NULL){
			insertar1(p2->alumnos);
			printf("\nEl alumno %s, carrera %s, ha sido ingresado en espera para el libro %d",p2->alumnos->nombre,p2->alumnos->carrera,c);
			Sleep(1000);
		}else printf("\nCodigo de libro no encontrado");
		return;
	}else {printf("\nLista vacia");}
	return;
}
void insertar2(puntero2 &xp2,int c){
	
	puntero2 nuevo2;
	nuevo2=(puntero2)malloc(sizeof(nodo2));
	nuevo2->cod=c;
	nuevo2->sig=xp2;
	xp2=nuevo2;
	xp2->alumnos=NULL;
}
void elimina(puntero1 &xp1){
	
	puntero1 p;
	p=xp1;
	xp1=xp1->sig;
	free(p);
	return;
}
void prestar(puntero2 &xp2, int c){
	
	puntero2 p2;
	if(xp2!=NULL){
		p2=busca2(xp2,c);
		if(p2!=NULL){
			if(p2->alumnos!=NULL){
				printf("\nSe ha prestado el libro %d al alumno %s de la carrera %s",c,p2->alumnos->nombre,p2->alumnos->carrera);
				elimina(p2->alumnos);
				Sleep(1000);
			}else {printf("\nNo hay alumnos en lista de espera para este libro");}
		}else printf("\nCodigo de libro no encontrado");
	}else {printf("\nLista vacia");}
	return;	
}
void listar1(puntero1 xp1,cadena cr){

	if(xp1!=NULL){
		if(stricmp(xp1->carrera,cr)==0)
			printf("\nNombre: %s", xp1->nombre);
			printf("\nCarrera: %s", xp1->carrera);
			printf("\n");
			listar1(xp1->sig,cr);
	}else return;
}
void listar2(puntero2 xp2,int c){
	
	puntero2 p2;
	cadena cr;
	if(xp2!=NULL){
		p2=busca2(xp2,c);
		if(p2!=NULL){
			if(p2->alumnos!=NULL){	
				printf("\nIngrese carrera: ");
				fflush(stdin);
				gets(cr);
				fflush(stdin);			
				printf("\nAlumnos de la carrea %s en lista de espera para el libro %d \n",cr,c);			
				listar1(p2->alumnos,cr);
				Sleep(1000);
			}else {printf("\nNo hay alumnos en lista de espera para el libro %d",c);}
		}else printf("\nCodigo de libro no encontrado");
	}else {printf("\nLista vacia");}
	return;			
}
int main(){
	
	puntero2 cabeza;
	int op,codigo;
	long dni;
	cadena name,car;
	
	printf("\n ******** MENU DE OPCIONES ***********\n");
	do{
		printf("\n 1- Crear una lista de libros: ");
		printf("\n 2- Ingresar a un alumno en la cola de espera: ");
		printf("\n 3- Ingresar un nuevo libro: ");
		printf("\n 4- Prestar un libro: ");
		printf("\n 5- Mostrar alumnos de una carrera en espera de un libro: ");
		printf("\n 6- Salir del Menu: ");
		scanf("%d", &op);
		switch (op){
			case 1: {	
			crear2(cabeza);
			fflush(stdin);
			break;
			}
			case 2:{ 
			printf("\nIngrese codigo de libro: ");
			scanf("%d", &codigo);
			cargaalum(cabeza,codigo);
			fflush(stdin);
			break;
			}
			case 3:{ 
			printf("\nIngrese codigo de libro: ");
			scanf("%d", &codigo);
			insertar2(cabeza,codigo);
			fflush(stdin);
			break;
			}
			case 4:{
			printf("\nIngrese codigo de libro a prestar: ");
			scanf("%d",&codigo);			
			prestar(cabeza,codigo);
			fflush(stdin);
			break;
			} 
			case 5:{
			printf("\nIngrese codigo de libro: ");
			scanf("%d",&codigo);			
			listar2(cabeza,codigo);
			fflush(stdin);
			break;                                                                                
			}	
		}
		Sleep(1000);
		system("cls");
	} while (op !=6);		
}