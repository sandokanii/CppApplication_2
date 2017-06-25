/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdlib.h>
#include <stdio.h>
#include "productos.h"

void AltaProds(){
    FILE *pf;
    Producto prod;
    pf = fopen("Productos.dat","a");
    printf("Ingrese Codigo\n");
    scanf("%i",&prod.codigo);
    printf("Ingrese Detalle\n");
    scanf("%s",prod.detalle);
    printf("Ingrese Precio\n");
    scanf("%f",&prod.precio);
    printf("Ingrese Costo\n");
    scanf("%f",&prod.costo);
    printf("Ingrese Proveedor\n");
    scanf("%s",prod.prov);
    fseek(pf,0L,SEEK_END);
    fwrite(&prod,sizeof(Producto),1,pf);
    fclose(pf);
    system("clear");
   
} 
void ListadoProds(){
    FILE *pf;
    Producto prod;
    pf = fopen("Productos.dat","r");
    fread(&prod,sizeof(Producto),1,pf);
    while(!feof(pf)){
        printf("%i ; %s ; %.2f ; %.2f ; %s\n",prod.codigo,prod.detalle,prod.precio,prod.costo,prod.prov);
        fread(&prod,sizeof(Producto),1,pf);
    }
    fclose(pf);
} 
void ModifProds(){
    FILE *pf,*pfaux;
    Producto prod;
    int codigoaux;
    pf = fopen("Productos.dat","r");
    pfaux = fopen("Productosaux.dat","a");
    printf("Ingrese Código\n");
    scanf("%i",&codigoaux);
    fread(&prod,sizeof(Producto),1,pf);
        while (!feof(pf)){
                if (prod.codigo != codigoaux){
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&prod,sizeof(Producto),1,pfaux);
                }else{
                    printf("Ingrese Detalle\n");
                    scanf("%s",prod.detalle);
                    printf("Ingrese Precio\n");
                    scanf("%f",&prod.precio);
                    printf("Ingrese Costo\n");
                    scanf("%f",&prod.costo);
                    printf("Ingrese Proveedor\n");
                    scanf("%s",prod.prov);
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&prod,sizeof(Producto),1,pfaux);
                }
            fread(&prod,sizeof(Producto),1,pf);
        }
    fclose(pf);
    fclose(pfaux);
    remove("Productos.dat");
    rename("Productosaux.dat","Productos.dat");
} 
void BajaProds(){
    FILE *pf,*pfaux;
    Producto prod;
    int codigoaux;
    pf = fopen("Productos.dat","r");
    pfaux = fopen("Productosaux.dat","a");
    printf("Ingrese Código\n");
    scanf("%i",&codigoaux);
    fread(&prod,sizeof(Producto),1,pf);
        while (!feof(pf)){
                if (prod.codigo != codigoaux){
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&prod,sizeof(Producto),1,pfaux);
                }
            fread(&prod,sizeof(Producto),1,pf);
        }
    fclose(pf);
    fclose(pfaux);
    remove("Productos.dat");
    rename("Productosaux.dat","Productos.dat");
}
