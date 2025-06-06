#include<stdio.h>
#include<string.h>
#define M 2
#define N 2
struct area{
	char name[50];
	int cupo;
};

void cereo(area a[M],int t[M][N]){
	
	int i,j;
	
	for(i=0;i<M;i++){
		printf("\nIngrese el nombre del area tematica %d ",i+1);
		fflush(stdin);
		gets(a[i].name);
		printf("\nIngrese el cupo de la sala ");
		scanf("%d",&a[i].cupo);
		for(j=0;j<N;j++){
			t[i][j]=0;
		}
	}
	
}

void carga(area a[M],int t[M][N]){	
	
	int i,turno;
	char nomb[50],nombar[50];
	
	printf("\nIngrese nombre del interesado, finalice con 'FIN' ");
	fflush(stdin);
	gets(nomb);
	while(stricmp(nomb,"FIN")){
		
		printf("\nIngrese nombre del area ");
		fflush(stdin);
		gets(nombar);
		i=0;
		while((i<M)&&(stricmp(nombar,a[i].name))){
			
			i++;
		}
		if(i<N){
			
			printf("\nIngrese numero de la conferencia a la que desea asistir ");
			scanf("%d",&turno);
			if((t[i][turno-1]+1)>a[i].cupo){
				
				printf("\nCupo lleno");
			}else t[i][turno-1]++;
		}else printf("\nNombre de area incorrecta ");
		printf("\nIngrese nombre del interesado, finalice con 'FIN' ");
		fflush(stdin);
		gets(nomb);	
	}	
}

void minmax(int t[M][N]){
	
	int i,j,min,max,aux1,aux2;
	for(i=0;i<M;i++){
		min=99999999;
		max=0;
		for(j=0;j<N;j++){
			if(t[i][j]<min){
				min=t[i][j];
				aux1=j+1;
			}
			if(t[i][j]>max){
				max=t[i][j];
				aux2=j+1;
			}
		}
		printf("\nArea tematica nro %d",i+1);
		printf("\nConferencia con menos inscriptos: %d",aux1);
		printf("\nConferencia con mas inscriptos: %d",aux2);			
	}
} 

void menosinsc(int t[M][N], area a[M]){
	
	int sum,i,j,aux,min=999999;
	
	for(i=0;i<M;i++){
		sum=0;
		for(j=0;j<N;j++){
			sum+=t[i][j];
		}
		if(sum<min){
			min=sum;
			aux=i;
		}
	}
	printf("\nArea tematica con menos inscriptos: %s",a[aux].name);
}

void busca(int t[M][N],char n[50],area a[M]){
	
	int i=0,j,sum=0;
	while((i<M)&&(stricmp(n,a[i].name))){
		i++;
	}
	if(i<M){
		for(j=0;j<N;j++){
			sum+=t[i][j];
		}
		printf("\nPromedio de inscriptos del area %s: %d",n,sum/N);
	}else printf("\nNombre de area incorrecto");
}

void cupocompleto(int t[M][N],area a[M]){
	
	bool bandera;
	int i,j=0;
	for(i=0;i<M;i++){
		bandera=false;
		while((j<M)&&(!bandera)){
			if(t[i][j]==a[i].cupo){
				bandera=true;
			}else j++;
		}
		if(bandera){
			printf("\nEl area tematica %s tuvo la sala completa en algun turno",a[i].name);
		}else printf("\nEl area tematica %s NO tuvo la sala completa en ningun turno",a[i].name);
	}
}	

int main(){
	
	area tem[M];
	int tabla[M][N];
	char n[50];
	
	cereo(tem,tabla);
	carga(tem,tabla);
	printf("\n-------------------------");	
	minmax(tabla);
	printf("\n-------------------------");	
	menosinsc(tabla,tem);
	printf("\n-------------------------");	
	printf("\nIngrese un nombre de area tematica ");
	gets(n);
	busca(tabla,n,tem);
	printf("\n-------------------------");
	cupocompleto(tabla,tem);	
}

/*
ola
4
chau
4
*/

/*
juan
ola
1
juan
ola
1
juan
ola
1
juan
ola
1
juan
ola
2
juan
ola
2
juan
chau
1
juan
chau
1
juan
chau
1
juan
chau
2
juan
chau
2
fin
*/
