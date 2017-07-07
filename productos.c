/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "productos.h"

void AltaProds() {
    FILE *pf;
    Producto prod;
    pf = fopen("Productos.txt", "r+");
    //char codigo[5];
    char codigo1[5];
    int bandera = 0;
    do {
        printf("Ingrese Codigo\n");
        scanf("%s", codigo1);
        bandera = 0;
        while (!feof(pf)) {
            fread(&prod, sizeof (Producto), 1, pf);
            if (strcmp(prod.codigo, codigo1) == 0) {
                printf("el codigo ya existe\n");
                bandera = 1;
            }
        }
    } while (!(bandera == 0));
    strcpy(prod.codigo, codigo1);
    bandera = 2;
    fflush(stdin);
    while (getchar() != '\n');
    printf("Ingrese Detalle\n");
    fgets(prod.detalle, 28, stdin);
    fflush(stdin);
    printf("Ingrese Precio\n");
    scanf("%f", &prod.precio);
    fflush(stdin);
    printf("Ingrese Costo\n");
    scanf("%f", &prod.costo);
    fflush(stdin);
    printf("Ingrese Proveedor\n");
    scanf("%s", prod.prov);
    fseek(pf, 0L, SEEK_END);
    fwrite(&prod, sizeof (Producto), 1, pf);
    fclose(pf);
    system("clear");

}

void ListadoProds() {
    FILE *pf;
    Producto prod;
    pf = fopen("Productos.txt", "r");
    fread(&prod, sizeof (Producto), 1, pf);
    while (!feof(pf)) {
        printf("%s ; %s ; %.2f ; %.2f ; %s\n", prod.codigo, prod.detalle, prod.precio, prod.costo, prod.prov);
        fread(&prod, sizeof (Producto), 1, pf);
    }
    fclose(pf);
}

void ModifProds() {
    FILE *pf, *pfaux;
    Producto prod;
    char codigoaux[5];
    int opcion;
    pf = fopen("Productos.txt", "r");
    pfaux = fopen("Productosaux.txt", "a");
    printf("Ingrese Código\n");
    scanf("%s", codigoaux);
    fread(&prod, sizeof (Producto), 1, pf);
    while (!feof(pf)) {
        if (strcmp(prod.codigo, codigoaux) == 0) {
            fseek(pfaux, 0l, SEEK_END);
            fwrite(&prod, sizeof (Producto), 1, pfaux);
        } else {
            printf("Ingrese  opcion a modificar: 1 detalle, 2 Precio, 3 Costo, 4 Proveedor\n");
            scanf("%i", &opcion);
            switch (opcion) {
                case 1:
                    while (getchar() != '\n');
                    printf("Ingrese Detalle\n");
                    gets(prod.detalle);
                 break;
                case 2:
                    printf("Ingrese Precio\n");
                    scanf("%f", &prod.precio);
                  break;
                case 3:
                    printf("Ingrese Costo\n");
                    scanf("%f", &prod.costo);
                  break;
                case 4:
                    printf("Ingrese Proveedor\n");
                    scanf("%s", prod.prov);
                 break;   
                    fseek(pfaux, 0l, SEEK_END);
                    fwrite(&prod, sizeof (Producto), 1, pfaux);
            }
            fread(&prod, sizeof (Producto), 1, pf);
        }
    }
        fclose(pf);
        fclose(pfaux);
        remove("Productos.txt");
        rename("Productosaux.txt", "Productos.txt");
    }

void BajaProds() {
        FILE *pf, *pfaux;
        Producto prod;
        char codigoaux[5];
        pf = fopen("Productos.txt", "r");
        pfaux = fopen("Productosaux.txt", "a");
        printf("Ingrese Código\n");
        scanf("%s", codigoaux);
        fread(&prod, sizeof (Producto), 1, pf);
        while (!feof(pf)) {
            if (strcmp(prod.codigo, codigoaux) != 0) {
                fseek(pfaux, 0l, SEEK_END);
                fwrite(&prod, sizeof (Producto), 1, pfaux);
            }
            fread(&prod, sizeof (Producto), 1, pf);
        }
        fclose(pf);
        fclose(pfaux);
        remove("Productos.txt");
        rename("Productosaux.txt", "Productos.txt");
    }
