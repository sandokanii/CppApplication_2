/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"

void menu();

void menu4() {
    int opcion3;
    do {
        printf("             -------------Clientes----------------------\n");
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
                AltaClientes();
                break;
            case 2:
                BajaClientes();
                break;
            case 3:
                ModifClientes();
                break;
            case 4:
                ListadoClientes();
                break;
            case 5:
                menu();
                break;
        }
    } while (opcion3 != 5);
}

