/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"

void ModifClientes() {
    FILE *pf, *pfaux;
    Clientes cliente;
    char cuitaux[30];
    int opcion;
    pf = fopen("Clientes.txt", "r+");
   // pfaux = fopen("Clientesaux.txt", "a");
    printf("Ingrese CUIT\n");
    scanf("%s", cuitaux);
    fread(&cliente, sizeof (Clientes), 1, pf);
    while (!feof(pf)) {
        if (strcmp(cliente.cuit, cuitaux) == 0) {
            printf("Ingrese  opcion a modificar: 1 denominacion, 2 fecha alta, 3 Email, 4 telefono\n");
            scanf("%i", &opcion);
            switch (opcion) {
                case 1 :          
            printf("Ingrese Denominacion Cliente\n");
            scanf("%s", cliente.cliente);
            break;
                case 2:
            fflush(stdin);
            printf("Ingrese Fecha de alta\n");
            fflush(stdin);
            scanf("%s", cliente.fechaalta);
            break;
                case 3:
            printf("Ingrese Email\n");
            scanf("%s", cliente.email);
            break;
                case 4:
            printf("Ingrese Telefono\n");
            scanf("%s", cliente.telefono);
            break;
            }
            fseek(pf, 0l, SEEK_END);
            fwrite(&cliente, sizeof (Clientes), 1, pf);
        } else {
            printf("no existe el solicitado\n");
           /* printf("Ingrese  opcion a modificar: 1 denominacion, 2 fecha alta, 3 Email, 4 telefono\n");
            scanf("%i", &opcion);
            switch (opcion) {
                case 1 :          
            printf("Ingrese Denominacion Cliente\n");
            scanf("%s", cliente.cliente);
            break;
                case 2:
            fflush(stdin);
            printf("Ingrese Fecha de alta\n");
            fflush(stdin);
            scanf("%s", cliente.fechaalta);
            break;
                case 3:
            printf("Ingrese Email\n");
            scanf("%s", cliente.email);
            break;
                case 4:
            printf("Ingrese Telefono\n");
            scanf("%s", cliente.telefono);
            break;*/
        
           // fseek(pf, 0L, SEEK_END);
          //  fwrite(&cliente, sizeof (Clientes), 1, pf);
         //   fclose(pf);
            system("clear");
            
        }
        fread(&cliente, sizeof (Clientes), 1, pf);
    }
    fclose(pf);
    //fclose(pfaux);
   // remove("Clientes.txt");
   // rename("Clientesaux.txt", "Clientes.txt");
}

void ListadoClientes() {
    FILE *pf;
    Clientes cliente;
    pf = fopen("Clientes.txt", "r");
    fread(&cliente, sizeof (Clientes), 1, pf);
    while (!feof(pf)) {
        printf("%s ; %s ; %s ; %s ; %s \n", cliente.cuit, cliente.cliente, cliente.fechaalta, cliente.email, cliente.telefono);
        fread(&cliente, sizeof (Clientes), 1, pf);
    }
    fclose(pf);
}

void AltaClientes() {
    FILE *pf;
    Clientes cliente;
    pf = fopen("clientes.txt", "r+");
    char cuit[30];
    char cuit1[30];
    int bandera = 0;        
    do{
    printf("Ingrese CUIT\n");
    scanf("%s", cuit1);  
    bandera = 0;
    while (!feof(pf)) {
        fread(&cliente, sizeof (Clientes), 1, pf);
        if (strcmp(cliente.cuit, cuit1) == 0) {
            printf("el codigo ya existe\n");
            bandera = 1;
        }
    }
    } while(!(bandera == 0));
        strcpy(cliente.cuit , cuit1);
        bandera = 2;
 while (getchar() != '\n');
    printf("Ingrese Cliente\n");
    gets(cliente.cliente);
    fflush(stdin);
    printf("Ingrese Fecha de alta\n");
    gets( cliente.fechaalta);
    fflush(stdin);
    printf("Ingrese Email\n");
    scanf("%s", cliente.email);
    fflush(stdin);
    printf("Ingrese Telefono\n");
    scanf("%s", cliente.telefono);
    fflush(stdin);
    fseek(pf, 0L, SEEK_END);
    fwrite(&cliente, sizeof (Clientes), 1, pf);
    fclose(pf);
    system("clear");


}

void BajaClientes() {
    FILE *pf, *pfaux;
    Clientes cliente;
    char cuitaux[30];
    pf = fopen("Clientes.txt", "r");
    pfaux = fopen("Clientesaux.txt", "a");
    printf("Ingrese CUIT\n");
    scanf("%s", cuitaux);
    fread(&cliente, sizeof (Clientes), 1, pf);
    while (!feof(pf)) {
        if (strcmp(cliente.cuit, cuitaux) != 0) {
            fseek(pfaux, 0l, SEEK_END);
            fwrite(&cliente, sizeof (Clientes), 1, pfaux);
        }
        fread(&cliente, sizeof (Clientes), 1, pf);
    }
    fclose(pf);
    fclose(pfaux);
    remove("Clientes.txt");
    rename("Clientesaux.txt", "Clientes.txt");
}