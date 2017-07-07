/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proveedores.h"

void AltaProvs() {
    FILE *pf;
    Proveedores proveedor;
    //char codigo[5];
    char codigo1[5];
    int bandera = 0;
    pf = fopen("Proveedores.txt", "r+");
    do {
        printf("Ingrese Codigo\n");
        scanf("%s", codigo1);
        bandera = 0;
        while (!feof(pf)) {

            fread(&proveedor, sizeof (Proveedores), 1, pf);
            if (strcmp(proveedor.codigo, codigo1) == 0) {
                printf("el codigo ya existe\n");
                bandera = 1;
            }
        }
    } while (!(bandera == 0));
    strcpy(proveedor.codigo, codigo1);
    bandera = 2;
    while (getchar() != '\n');
    printf("Ingrese Nombre\n");
    fflush(stdin);
    gets(proveedor.nombre);
    printf("Ingrese Email\n");
    fflush(stdin);
    scanf("%s", proveedor.email);
    printf("Ingrese Telefono\n");
    fflush(stdin);
    scanf("%s", proveedor.telefono);
    fseek(pf, 0L, SEEK_END);
    fwrite(&proveedor, sizeof (Proveedores), 1, pf);
    fclose(pf);
    //system("clear");
}

void BajaProvs() {
    FILE *pf, *pfaux;
    Proveedores proveedor;
    char codigoaux[5];
    pf = fopen("Proveedores.txt", "r");
    pfaux = fopen("Proveedoresaux.txt", "a");
    printf("Ingrese Codigo\n");
    scanf("%s", codigoaux);
    fread(&proveedor, sizeof (Proveedores), 1, pf);
    while (!feof(pf)) {
        if (strcmp(proveedor.codigo, codigoaux) != 0) {
            fseek(pfaux, 0l, SEEK_END);
            fwrite(&proveedor, sizeof (Proveedores), 1, pfaux);
        }
        fread(&proveedor, sizeof (Proveedores), 1, pf);
    }
    fclose(pf);
    fclose(pfaux);
    remove("Proveedores.txt");
    rename("Proveedoresaux.txt", "Proveedores.txt");
}

void ModifProvs() {
    FILE *pf, *pfaux;
    Proveedores proveedor;
    char codigoaux[5];
    int opcion;
    pf = fopen("Provedores.txt", "r");
    pfaux = fopen("Proveedoresaux.txt", "a");
    printf("Ingrese Codigo\n");
    scanf("%s", codigoaux);
    fread(&proveedor, sizeof (Proveedores), 1, pf);
    while (!feof(pf)) {
        if (strcmp(proveedor.codigo, codigoaux) == 0) {            
            printf("Ingrese  opcion a modificar: 1 Nombre, 2 Telefono, 3 Email");
            scanf("%i", &opcion);
            switch (opcion) {
                case 1:
                    printf("Ingrese Nombre\n");
                    fflush(stdin);
                    fgets(proveedor.nombre, 28, stdin);
                    fseek(pfaux, 0l, SEEK_END);
                    fwrite(&proveedor, sizeof (Proveedores), 1, pfaux);
                    break;
                case 2:
                    printf("Ingrese Telefono\n");
                    fflush(stdin);
                    scanf("%s", proveedor.telefono);
                    break;
                case 3:
                    printf("Ingrese Email\n");
                    fflush(stdin);
                    scanf("%s", proveedor.email);
                    break;
            }
            fseek(pfaux, 0l, SEEK_END);
            fwrite(&proveedor, sizeof (Proveedores), 1, pfaux);
        } else {
            printf("no esta registrado");           
        }
        fread(&proveedor, sizeof (Proveedores), 1, pf);
        printf("no se k paso");
    }
    fclose(pf);
    fclose(pfaux);
    remove("Proveedores.txt");
    rename("Proveedoresaux.txt", "Proveedores.txt");
}

void ListadoProvs() {
    FILE *pf;
    Proveedores proveedor;
    pf = fopen("Proveedores.txt", "r");
    fread(&proveedor, sizeof (Proveedores), 1, pf);
    while (!feof(pf)) {
        printf("%s ; %s ; %s ; %s \n", proveedor.codigo, proveedor.nombre, proveedor.telefono, proveedor.email);
        fread(&proveedor, sizeof (Proveedores), 1, pf);
    }
    fclose(pf);
}