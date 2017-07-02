/* 
 * File:   TPfinal.c
 * Author: sandro ivanovich y roberto calisto
 *
 * Created on 19 de junio de 2017, 15:41

fgetc -> fputc
fgets -> fputs
fscanf -> fprintf
fread -> fwrite (binarios)


 */

#include <stdio.h>
#include <stdlib.h>
#include "proveedores.h"
#include "clientes.h"
#include "productos.h"
#include "presupuesto.h"
#include "menu1.h"
#include "menu2.h"
#include "menu3.h"
#include "menu4.h"
void menu();

int main() {
   // char proveedor[]
    menu();   
    return 0;
}

void menu() {
    int opcion /*opcion2*/;
    do {

        printf("             -------------------------------------------\n");
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





