/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "menu1.h"
#include "menu2.h"
#include "menu3.h"
#include "menu4.h"
#include "DatoEmpresa.h"
void DatoEmpresa();
void menu() {
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
    int opcion /*opcion2*/;
    do {

        printf("                          %s \n",nombre_empresa);
        printf("                          1) Productos\n");
        printf("                          2) Proveedores\n");
        printf("                          3) Clientes\n");
        printf("                          4) Presupuestos y Facturas\n");
        printf("                          5) Salir\n");
        printf("             -------------------------------------------\n");
        scanf("%d", &opcion);
        system("clear");
      
        switch (opcion) {
            case 4:
                menu1();
               
                break;
            case 1:
                menu2();
               
                break;
            case 2:
                menu3();
              
                break;
            case 3:
                menu4();
              
                break;
            case 5:
                break;

        }
    } while (opcion != 5);
}