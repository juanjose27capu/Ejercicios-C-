#include<stdio.h>
#include<string.h>
#define P 3
#define C 3

struct productos{
	int codigo;
	float precio;
	int stock;
};

struct proveedores{
	char nombre[20];
	int compras;
};

void cerear(productos a[P],proveedores b[C]){
	
	int i;
	
	for(i=0;i<P;i++){
		
		a[i].codigo=0;
		a[i].precio=0;
		a[i].stock=0;
		if(i<C){
			b[i].compras=0;
		}
	}
	return;
}

void carga(productos prod[P], proveedores prov[C]){
	
	int codprod,numprov,cant;
	
	printf("\nIngrese el codigo de producto, finalice con cero ");
	scanf("%d",&codprod);
	
	while(codprod!=0){
		
		printf("\nIngrese el numero de proveedor ");
		scanf("%d",&numprov);
		
		printf("\nIngrese el nombre de proveedor ");
		fflush(stdin);
		gets(prov[numprov-1000].nombre);
		fflush(stdin);
		
		printf("\nIndique la cantidad de unidades compradas ");
		scanf("%d",&cant);
		
		printf("\nIngrese precio ");
		scanf("%f",&prod[codprod-1].precio);
		
		prod[codprod-1].stock+=cant;
		prov[numprov-1000].compras+=1;
		
		printf("\nIngrese el codigo de producto, finalice con cero ");
		scanf("%d",&codprod);
		
	}
}

void dineroinvertido(productos a[P]){
	
	int i;
	printf("\nDinero invertido en cada producto: ");
	for(i=0;i<P;i++){
		printf("\nProducto nro %d: %10.2f\n",i+1,a[i].stock*a[i].precio);
	}
	return;
}

int subcarga (proveedores prov[C], proveedores prov2[C]){
	
	int i,j;
	j=0;
	for(i=0;i<C;i++){
		if(prov[i].compras>10){
			prov2[j].compras=prov[i].compras;
			strcpy(prov2[j].nombre,prov[i].nombre);
			j++;
		}
	}
	return (j);
}

void ordenar(proveedores prov2[C], int j){
	proveedores aux;
	int k,cota,i;
	k=1;
	cota=j-1;
	
	while(k!=-1){
		k=-1;
		for(i=0;i<cota;i++){
			if(strcmp(prov2[i].nombre,prov2[i+1].nombre)>0){
				aux=prov2[i];
				prov2[i]=prov2[i+1];
				prov2[i+1]=aux;
				k=i;
			}
		}
		cota=k;	
	}
}

void mostrarsub(proveedores prov2[C], int j){
	
	int i;
	
	printf("\nNombres de los proveedores con mas de 10 compras ordenados alfabeticamente:\n");
	for(i=0; i<j; i++){
		printf("\nNombre: %s", prov2[i].nombre);
		printf("\nNumero de proveedor: %d", i+1000);
		printf("\nCantidad de compras realizadas: %d", prov2[i].compras);
	}
}

int main(){
	productos product[P];
	proveedores proveed[C];
	proveedores proveed2[C];
	int c;
	
	cerear(product,proveed);
	carga(product, proveed);
	dineroinvertido(product);
	c = subcarga(proveed, proveed2);
	ordenar(proveed2, c);
	mostrarsub(proveed2, c);
}

/*
1
1000
hola
5
10
2
1001
alo
20
4
3
1002
jello
2
10
0
*/
