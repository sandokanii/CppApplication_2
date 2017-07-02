/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
//#include "proveedores.h"
//#include "clientes.h"
#include "facturacion.h"
#include "presupuesto.h"
//#include "main.c"
void menu();

void menu1(){
    int opcion3;
    do{
        printf("             -------------Presupuesto y Factura---------\n");
        printf("                          1) Alta\n");
        printf("                          2) Baja\n");
        printf("                          3) Modificación\n");
        printf("                          4) Listado\n");
        printf("                          5) Facturacion\n");
        printf("                          6) Volver al Menú\n");
        printf("             -------------------------------------------\n");
        scanf("%d",&opcion3);
        system("clear");
                        switch(opcion3){
                            case 1:
                                AltaPresu();
                                break;
                            case 2:
                                BajaPresu();
                                break;
                            case 3:
                                ModifPresu();
                                break;
                            case 4:
                                ListadoPresu();
                                break;
                            case 5:
                                //AltaFactura();
                                printf("\t\t-----------------\n");
                                printf("\t\t-  Version 2.0  -\n");
                                printf("\t\t-    paypal     -\n");
                                printf("\t\t-----------------\n");
                                break;
                                case 6:
                                menu();
                                break;
                        }
    }while (opcion3!=6);
}
