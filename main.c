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
#include "DatoEmpresa.h"
#include "menu0.h"
void menu();

int main() {

    int opcion2 = 0;
    int bande =0;
    do {
        printf("Ya a registrado su empresa (1-Si, 2-No)\n");
        scanf("%d", &opcion2);
        fflush(stdin);
        switch (opcion2) {
            case 1:
                menu();
                break;
            case 2:
                DatoEmpresa();
                menu();
                break;
            default: printf("seleccione opcion 1 o 2 ");
                bande = 1;
        }
    } while (!(bande = 1));
    return 0;
}
