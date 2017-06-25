/* 
 * File:   TPfinal.c
 * Author: sandro ivanovich y roberto calisto
 *
 * Created on 19 de junio de 2017, 15:41
 */

#include <stdio.h>
#include <stdlib.h>
#include "proveedores.h"
#include "clientes.h"
#include "productos.h"
#include "presupuesto.h"

void menu();
 
int main(){
    menu();
    return 0;
}
 
void menu(){
    int opcion,opcion2;
    do{
        printf("             -------------------------------------------\n");
        printf("             -------------------------------------------\n");
        printf("             -------------------------------------------\n");        
        printf("             -------------------------------------------\n");
        printf("                          1) Presupuestos\n");
        printf("                          2) Productos\n");
        printf("                          3) Proveedores\n");
        printf("                          4) Clientes\n");
        printf("                          5) Salir\n");
        printf("             -------------------------------------------\n");
        printf("             -------------------------------------------\n");
        printf("             -------------------------------------------\n");
        printf("             -------------------------------------------\n");
        scanf("%d",&opcion);
        system("clear");
        printf("             -------------------------------------------\n");
        printf("             -------------------------------------------\n");
        printf("             -------------------------------------------\n");
        printf("             -------------------------------------------\n");
        printf("                          1) Alta\n");
        printf("                          2) Baja\n");
        printf("                          3) Modificación\n");
        printf("                          4) Listado\n");
        printf("                          5) Volver al Menú\n");
        printf("             -------------------------------------------\n");
        printf("             -------------------------------------------\n");
        printf("             -------------------------------------------\n");
        printf("             -------------------------------------------\n");
        scanf("%d",&opcion2);
        system("clear");
            switch (opcion){
                case 1:
                        switch(opcion2){
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
                                menu();
                                break;
                        }
                    break;
                case 2:
                        switch(opcion2){
                            case 1:
                                AltaProds();
                                break;
                            case 2:
                                BajaProds();
                                break;
                            case 3:
                                ModifProds();
                                break;
                            case 4:
                                ListadoProds();
                                break;
                            case 5:
                                menu();
                                break;
                        }
                    break;
                case 3:
                        switch(opcion2){
                            case 1:
                                //AltaProvs();
                                break;
                            case 2:
                                //BajaProvs();
                                break;
                            case 3:
                                //ModifProvs();
                                break;
                            case 4:
                                //ListadoProvs();
                                break;
                            case 5:
                                menu();
                                break;
                        }
                    break;
                case 4:
                        switch(opcion2){
                            case 1:
                                AltaClientes();
                                break;
                            case 2:
                                //BajaClientes();
                                break;
                            case 3:
                                //ModifClientes();
                                break;
                            case 4:
                                //ListadoClientes();
                                break;
                            case 5:
                                menu();
                                break;
                        }
                    break;
                case 5:
                    break;
 
            }
    }while (opcion!=5);
}
 




