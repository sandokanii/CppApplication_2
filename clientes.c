/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "clientes.h"

void ModifClientes() {
    FILE *pf, *pfaux;
    Clientes cliente;
    char cuitaux[30];
    pf = fopen("Clientes.dat", "r");
    pfaux = fopen("Clientesaux.dat", "a");
    printf("Ingrese CUIT\n");
    scanf("%s", cuitaux);
    fread(&cliente, sizeof (Clientes), 1, pf);
    while (!feof(pf)) {
        if (cliente.cuit != cuitaux) {
            fseek(pfaux, 0l, SEEK_END);
            fwrite(&cliente, sizeof (Clientes), 1, pfaux);
        } else {
            printf("Ingrese CUIT\n");
            scanf("%s", cliente.cuit);
            printf("Ingrese Denominacio Cliente\n");
            scanf("%s", cliente.cliente);
            fflush(stdin);
            printf("Ingrese Fecha de alta\n");
            fflush(stdin);
            scanf("%s", cliente.fechaalta);
            printf("Ingrese Email\n");
            scanf("%s", cliente.email);
            printf("Ingrese Telefono\n");
            scanf("%s", cliente.telefono);
            fseek(pf, 0L, SEEK_END);
            fwrite(&cliente, sizeof (Clientes), 1, pf);
            fclose(pf);
            system("clear");
        }
        fread(&cliente, sizeof (Clientes), 1, pf);
    }
    fclose(pf);
    fclose(pfaux);
    remove("Clientes.dat");
    rename("Clientesaux.dat", "Clientes.dat");
}

void ListadoClientes() {
    FILE *pf;
    Clientes cliente;
    pf = fopen("Clientes.dat", "r");
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
    pf = fopen("clientes.dat", "r+");
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
    printf("Ingrese CUIT\n");
    printf("Ingrese Cliente\n");
    scanf("%s", cliente.cliente);
    printf("Ingrese Fecha de alta\n");
    scanf("%s", cliente.fechaalta);
    printf("Ingrese Email\n");
    scanf("%s", cliente.email);
    printf("Ingrese Telefono\n");
    scanf("%s", cliente.telefono);
    fseek(pf, 0L, SEEK_END);
    fwrite(&cliente, sizeof (Clientes), 1, pf);
    fclose(pf);
    system("clear");


}

void BajaClientes() {
    FILE *pf, *pfaux;
    Clientes cliente;
    char cuitaux[30];
    pf = fopen("Clientes.dat", "r");
    pfaux = fopen("Clientesaux.dat", "a");
    printf("Ingrese CUIT\n");
    scanf("%s", cuitaux);
    fread(&cliente, sizeof (Clientes), 1, pf);
    while (!feof(pf)) {
        if (cliente.cuit != cuitaux) {
            fseek(pfaux, 0l, SEEK_END);
            fwrite(&cliente, sizeof (Clientes), 1, pfaux);
        }
        fread(&cliente, sizeof (Clientes), 1, pf);
    }
    fclose(pf);
    fclose(pfaux);
    remove("Clientes.dat");
    rename("Clientesaux.dat", "Clientes.dat");
}