/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdlib.h>
#include <stdio.h>
#include "clientes.h"
void ModifClientes(){
FILE *pf,*pfaux;
    Clientes  cliente;
    char cuitaux;
    pf = fopen("Clientes.dat","r");
    pfaux = fopen("Clientesaux.dat","a");
    printf("Ingrese CUIT\n");
    scanf("%s",&cuitaux);
    fread(&cliente,sizeof(Clientes),1,pf);
        while (!feof(pf)){
                if (cliente.cuit != cuitaux){
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&cliente,sizeof(Clientes),1,pfaux);
                }else{
					printf("Ingrese CUIT\n");
					scanf("%s",cliente.cuit);
					printf("Ingrese Cliente\n");
					scanf("%s",cliente.cliente);
					printf("Ingrese Fecha de alta\n");
					scanf("%s",cliente.fechaalta);
					printf("Ingrese Email\n");
					scanf("%s",cliente.email);
					printf("Ingrese Telefono\n");
					scanf("%s",cliente.telefono);
					fseek(pf,0L,SEEK_END);
					fwrite(&cliente,sizeof(Clientes),1,pf);
					fclose(pf);
					system("clear");
                   }
            fread(&cliente,sizeof(Clientes),1,pf);
        }
    fclose(pf);
    fclose(pfaux);
    remove("Clientes.dat");
    rename("Clientesaux.dat","Clientes.dat");
}
void ListadoClientes(){
FILE *pf;
    Clientes cliente;
    pf = fopen("Clientes.dat","r");
    fread(&cliente,sizeof(Clientes),1,pf);
    while(!feof(pf)){
        printf("%i ; %s ; %s ; %s ; %s \n",cliente.cuit,cliente.cliente,cliente.fechaalta,cliente.email,cliente.telefono);
        fread(&cliente,sizeof(Clientes),1,pf);
    }
    fclose(pf);
}
void AltaClientes(){
    FILE *pf;
    Clientes  cliente;
    pf = fopen("clientes.dat","ab");
    printf("Ingrese CUIT\n");
    scanf("%i",&cliente.cuit);
    printf("Ingrese Cliente\n");
    scanf("%s",cliente.cliente);
    printf("Ingrese Fecha de alta\n");
    scanf("%s",cliente.fechaalta);
    printf("Ingrese Email\n");
    scanf("%s",cliente.email);
    printf("Ingrese Telefono\n");
    scanf("%s",cliente.telefono);
    fseek(pf,0L,SEEK_END);
    fwrite(&cliente,sizeof(Clientes),1,pf);
    fclose(pf);
    system("clear");
   
     
 }
void BajaClientes(){
    FILE *pf,*pfaux;
    Clientes  cliente;
    int cuitaux;
    pf = fopen("Clientes.dat","r");
    pfaux = fopen("Clientesaux.dat","a");
    printf("Ingrese CUIT\n");
    scanf("%i",&cuitaux);
    fread(&cliente,sizeof(Clientes),1,pf);
        while (!feof(pf)){
                if (cliente.cuit != cuitaux){
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&cliente,sizeof(Clientes),1,pfaux);
                }
            fread(&cliente,sizeof(Clientes),1,pf);
        }
    fclose(pf);
    fclose(pfaux);
    remove("Clientes.dat");
    rename("Clientesaux.dat","Clientes.dat");  
 }