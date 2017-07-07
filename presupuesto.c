/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "presupuesto.h"

void AltaPresu() {
    FILE *pf;
    Presupuesto presu;
    pf = fopen("Presupuesto.txt", "r+");
    //char codigo[5];
    char codigo1[5];
    int bandera = 0;
    do {
        printf("Ingrese Codigo\n");
        scanf("%s", codigo1);
        bandera = 0;
        while (!feof(pf)) {
            fread(&presu, sizeof (Presupuesto), 1, pf);
            if (strcmp(presu.codigo, codigo1) == 0) {
                printf("el codigo ya existe\n");
                bandera = 1;
            }
        }
    } while (!(bandera == 0));
    strcpy(presu.codigo, codigo1);
    bandera = 2;
    printf("Ingrese Fecha\n");
    scanf("%s", presu.fecha);
    printf("Ingrese CUIT\n");
    scanf("%s", presu.cuit);
    printf("Ingrese Total\n");
    scanf("%f", &presu.total);
    printf("Ingrese Descuento\n");
    scanf("%f", &presu.descuento);
    fseek(pf, 0L, SEEK_END);
    fwrite(&presu, sizeof (Presupuesto), 1, pf);
    fclose(pf);
    system("clear");



}

void ListadoPresu() {
    FILE *pf;
    Presupuesto presu;
    pf = fopen("Presupuesto.txt", "r");
    fread(&presu, sizeof (Presupuesto), 1, pf);
    while (!feof(pf)) {
        printf("\n\t\t%s ; %s ; %s ; %.2f ; %.2f\n", presu.codigo, presu.fecha, presu.cuit, presu.total, presu.descuento);

        fread(&presu, sizeof (Presupuesto), 1, pf);
    }

    fclose(pf);
}

void ModifPresu() {
    FILE *pf, *pfaux;
    Presupuesto presu;
    char codigoaux[5];
    int opcion;
    pf = fopen("Presupuesto.txt", "r+");
    pfaux = fopen("Presupuestoaux.txt", "r+");
    printf("Ingrese Código\n");
    scanf("%s", codigoaux);
    fread(&presu, sizeof (Presupuesto), 1, pf);
    while (!feof(pf)) {
        if (strcmp(presu.codigo, codigoaux) == 0) {
            fseek(pfaux, 0l, SEEK_END);
            fwrite(&presu, sizeof (Presupuesto), 1, pfaux);
        
            printf("Ingrese  opcion a modificar: 1 Fecha, 2 Cuit, 3 Total, 4 Descuento\n");
            scanf("%i", &opcion);
            switch (opcion) {
                case 1:
                    printf("Ingrese Fecha\n");
                    scanf("%s", presu.fecha);
                    break;
                case 2:
                    printf("Ingrese CUIT\n");
                    scanf("%s", presu.cuit);
                    break;
                case 3: 
                    printf("Ingrese Total\n");
                    scanf("%f", &presu.total);
                    break;
                case 4:  
                    printf("Ingrese Descuento\n");
                    scanf("%f", &presu.descuento);
                   break; 
            }
        }
                    fseek(pfaux, 0l, SEEK_END);
                    fwrite(&presu, sizeof (Presupuesto), 1, pfaux);
            }
            fread(&presu, sizeof (Presupuesto), 1, pf);
        
    
        fclose(pf);
        fclose(pfaux);
        remove("Presupuesto.txt");
        rename("Presupuestoaux.txt", "Presupuesto.txt");
    }

    void BajaPresu() {
        FILE *pf, *pfaux;
        Presupuesto presu;
        char codigoaux[5];
        pf = fopen("Presupuesto.txt", "r");
        pfaux = fopen("Presupuestoaux.txt", "a");
        printf("Ingrese Código\n");
        scanf("%s", codigoaux);
        fread(&presu, sizeof (Presupuesto), 1, pf);
        while (!feof(pf)) {
            if (strcmp(presu.codigo, codigoaux) != 0) {
                fseek(pfaux, 0l, SEEK_END);
                fwrite(&presu, sizeof (Presupuesto), 1, pfaux);
            }
            fread(&presu, sizeof (Presupuesto), 1, pf);
        }
        fclose(pf);
        fclose(pfaux);
        remove("Presupuesto.txt");
        rename("Presupuestoaux.txt", "Presupuesto.txt");
    }
