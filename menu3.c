/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "proveedores.h"
//#include "clientes.h"
//#include "productos.h"
//#include "presupuesto.h"
//#include "main.c"
#include "DatoEmpresa.h"
void DatoEmpresa();
void menu();

void menu3() {
    FILE *pf;
    registro regist;
    pf = fopen("Registracion.txt", "r");
    char nombre_empresa[30];
    fread(&regist, sizeof (registro), 1, pf);
    while (!feof(pf)) {
        sprintf(nombre_empresa, "%s", regist.reg_entidad);
        fread(&regist, sizeof (registro), 1, pf);
    }
    fclose(pf);
    int opcion3 /*opcion2*/;
    do {

        printf("                          %s \n",nombre_empresa);
        printf("             -------------Proveedores-------------------\n");
        printf("                          1) Alta\n");
        printf("                          2) Baja\n");
        printf("                          3) Modificación\n");
        printf("                          4) Listado\n");
        printf("                          5) Volver al Menú\n");
        printf("             -------------------------------------------\n");
        scanf("%d", &opcion3);
        system("clear");
        switch (opcion3) {
            case 1:
                AltaProvs();
                break;
            case 2:
                BajaProvs();
                break;
            case 3:
                ModifProvs();
                break;
            case 4:
                ListadoProvs();
                break;
            case 5:
                menu();
                break;
        }
    } while (opcion3 != 5);
}

