/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "proveedores.h"

void AltaProvs(){
    FILE *pf;
    Proveedores  proveedor;
    pf = fopen("proveedores.dat","a");
    printf("Ingrese Codigo\n");
    scanf("%i",proveedor.codigo);
    printf("Ingrese Nombre\n");
    scanf("%c",&proveedor.nombre);
    printf("Ingrese Telefono\n");
    scanf("%c",&proveedor.telefono);
    printf("Ingrese Email\n");
    scanf("%c",&proveedor.email);
    fseek(pf,0L,SEEK_END);
    fwrite(&proveedor,sizeof(Proveedores),1,pf);
    fclose(pf);
    system("clear");
   
 }
void BajaProvs(){
    FILE *pf,*pfaux;
    Proveedores proveedor;
    int codigoaux;
    pf = fopen("Provedores.dat","r");
    pfaux = fopen("Proveedoresaux.dat","a");
    printf("Ingrese Codigo\n");
    scanf("%i",&codigoaux);
    fread(&proveedor,sizeof(Proveedores),1,pf);
        while (!feof(pf)){
                if (proveedor.codigo != codigoaux){
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&proveedor,sizeof(Proveedores),1,pfaux);
                }
            fread(&proveedor,sizeof(Proveedores),1,pf);
        }
    fclose(pf);
    fclose(pfaux);
    remove("Proveedores.dat");
    rename("Proveedoresaux.dat","Proveedores.dat");
} 
void ModifProvs(){
    FILE *pf,*pfaux;
    Proveedores proveedor;
    int codigoaux;
    pf = fopen("Provedores.dat","r");
    pfaux = fopen("Proveedoresaux.dat","a");
    printf("Ingrese Codigo\n");
    scanf("%i",&codigoaux);
    fread(&proveedor,sizeof(Proveedores),1,pf);
        while (!feof(pf)){
                if (proveedor.codigo != codigoaux){
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&proveedor,sizeof(Proveedores),1,pfaux);
                }else{
                    printf("Ingrese Nombre\n");
                    scanf("%s",proveedor.nombre);
                    printf("Ingrese Telefono\n");
                    scanf("%s",proveedor.telefono);
                    printf("Ingrese Email\n");
                    scanf("%s",proveedor.email);
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&proveedor,sizeof(Proveedores),1,pfaux);
                }
            fread(&proveedor,sizeof(Proveedores),1,pf);
        }
    fclose(pf);
    fclose(pfaux);
    remove("Proveedores.dat");
    rename("Proveedoresaux.dat","Proveedores.dat");
}
void ListadoProvs(){
    FILE *pf;
    Proveedores proveedor;
    pf = fopen("Proveedores.dat","r");
    fread(&proveedor,sizeof(Proveedores),1,pf);
    while(!feof(pf)){
        printf("%i ; %s ; %s ; %s \n",proveedor.codigo,proveedor.nombre,proveedor.telefono,proveedor.email);
        fread(&proveedor,sizeof(Proveedores),1,pf);
    }
    fclose(pf);
}