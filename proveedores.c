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
    Proveedores proveedor;
    int band =1;
    pf = fopen("Proveedores.dat", "a");  
    do {
    printf("Ingrese Codigo\n");
    scanf("%i", &proveedor.codigo);
    fflush(stdin);
     //while (!feof(pf)
    
                if (proveedor.codigo != proveedor.codigo){
                                        
                    band=0;
                }else{
                    printf("Re-ingrese nuevo codigo\n");
                    band=1;
                }
    }while((band != 0));
    printf("Ingrese Nombre\n");
    fflush(stdin);
    scanf("%s", proveedor.nombre);
    printf("Ingrese Email\n");
    fflush(stdin);
    scanf("%s", proveedor.email);    
    printf("Ingrese Telefono\n");
    fflush(stdin);
    scanf("%s", proveedor.telefono);
        
     
    fseek(pf, 0L, SEEK_END);
    fwrite(&proveedor, sizeof (Proveedores), 1, pf);
    fclose(pf);
    system("clear");
        
 }
void BajaProvs(){
    FILE *pf,*pfaux;
    Proveedores proveedor;
    int codigoaux;
    pf = fopen("Proveedores.dat","r");
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
    int opcion;
    pf = fopen("Provedores.dat","r");
    pfaux = fopen("Proveedoresaux.dat","a");
    printf("Ingrese Codigo\n");
    scanf("%i",&codigoaux);
    fread(&proveedor, sizeof (Proveedores), 1, pf);
        while (!feof(pf)){
                if (proveedor.codigo != codigoaux){
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&proveedor,sizeof(Proveedores),1,pfaux);
                }else{
                    printf("Ingrese  opcion a modificar: 1 Nombre, 2 Telefono, 3 Email");
                    scanf("%i",opcion);
                    switch (opcion){
                        case 1:
                    printf("Ingrese Nombre\n");
                    fflush(stdin);
                    scanf("%s",proveedor.nombre);
                    break;
                        case 2:
                    printf("Ingrese Telefono\n");
                    fflush(stdin);
                    scanf("%s",proveedor.telefono);
                    break;
                        case 3:
                    printf("Ingrese Email\n");
                    fflush(stdin);
                    scanf("%s",proveedor.email);  
                    break;
                    }
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&proveedor, sizeof (Proveedores), 1,pfaux);
                }
            fread(&proveedor, sizeof (Proveedores), 1,pf);
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