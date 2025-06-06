#include <stdio.h>
#include <string.h>

void carga(char pp[40]){
      printf("\n Introduce la palabra: ");
      gets(pp);
      printf("\n");
      puts(pp);
}
void remplaza(char pp[40]){
	int i;int j;int c;
	j=0;
	for (i=0;i<40;i++){
		if(pp[i]=='2'){
			j++;
			c=i;
		}
	}
	if(j==3){
		pp[c]='0';
	}	
	printf("\nla nueva palabra es ");
	puts(pp);
}
void copia(char pp[40],char pp2[12]){
	int j;
	for (j=0;j<12;j++){
		pp2[j]=pp[j];
	}
	printf("\nLa palabra copiada es: ");
	for (j=0;j<12;j++){
		printf("%c",pp2[j]);
	}

void vocales(char pp[40]){
	int i;int cont;
	for (i=0;i<40;i++){
		switch(pp[i]){
			case 'a':
				cont ++;
			break;	
			case 'e':
				cont ++;
			break;	
			case 'i':
				cont ++;
			break;
			case 'o':
				cont ++;
			break;
			case 'u':
				cont ++;
			break;
		}
	}
	printf("la cantidad de vocales es %d ",cont);
}

int main(){
	char palabra[40];
	char palabra2[12];
	carga(palabra);
	copia(palabra,palabra2);
	remplaza(palabra);
	vocales(palabra);
}
// “Programacion Procedural 2022”
/*            ó
void carga (char arr[40],int i){
	if(i<40){
		gets(arr);
		fflush(stdin);
		carga(arr,i+1);
	}
}
int main(){
	char nomb[40];
	int i;
	carga (nomb,i);
	printf("cadena es %s ", nomb);
}
*/