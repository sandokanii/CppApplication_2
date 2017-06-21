/*
 * TP_expediente.c
 * 
 * Copyright 2017 usuario <usuario@ROBERTO>
 * Declare una estructura expediente que contenga: numero, aÃ±o, y 
 * cÃ³digo de oficina (hasta 3 letras).
 * Ejemplo: 25-2017-MCG.
 * Declare un arreglo que permita guardar hasta 10 expedientes.
 * Lea la lista de expedientes creados desde un archivo ("expedientes.txt").
 * Permita al usuario elegir un nÃºmero de expediente. 
 * Busque el expediente en el arreglo.
 * En caso de encontrarlo, ingrese un texto de hasta 5000 caracteres,
 * y guÃ¡rdelo en un archivo que se llame: numero-aÃ±o-codigo_oficina.txt.
 * Ejemplo: "expte-25-2017-MCG.txt" 
 * Reemplace el contenido del archivo si Ã©ste existe previamente.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BASE 10

struct Expediente {
    int numero;
    int anio;
    char cod_oficina[3];
    char texto[5000];
}; //ojo con punto y coma
typedef struct Expediente Expe; // tipo de dato usuario

int main(void) {
    char jose[5000];
    Expe bdatos[BASE];
    int i, reg = 0;
    char nombrearchivo[12];
    FILE* fp;
    FILE* fp2;


    //abrir el archivo
    fp = fopen("Expedientes.txt", "r");


    //comprobamos que se pudo abrir
    if (fp == NULL) {
        fprintf(stderr, "Error al abrir :(\n");
        return -1;
    }

    while (!feof(fp)) {

        for (i = 0; i < BASE; i++) {
            fscanf(fp, "%d-%d-%s", &bdatos[i].numero, &bdatos[i].anio, bdatos[i].cod_oficina);
        }
    }


    //~ //mostramos los datos en pantalla (para comprobar)
    for (i = 0; i < BASE; i++) {
        printf("registro en posicion %i. numero %d-%d de oficina %s\n", i + 1, bdatos[i].numero, bdatos[i].anio, bdatos[i].cod_oficina);
    }
    printf("Que registro desea guardar en el archivo: ");
    scanf("%i", &reg);
    printf("que dato de texto desea agregarle: ");
    fflush(stdin);
    fgets(jose, 4998, stdin);
    //strcpy(bdatos[reg-1].texto,jose);
    //donde le cambio el nombreee  nombrearchivo !!!!!!!!! /////////
    //guardamos el resultado en el 2do archivo


    sprintf(nombrearchivo, "%d-%d-%s.txt", bdatos[reg - 1].numero, bdatos[reg - 1].anio, bdatos[reg - 1].cod_oficina);
    printf("%s", nombrearchivo);
    fp2 = fopen(nombrearchivo, "w");
    if (fp2 == NULL) {
        perror("Error al abrir :(\n");

        return -1;
    }
    //fprintf(fp2,"registro: %s  \n", jose);
    fprintf(fp2, "registro en posicion %i. numero %d-%d de oficina %s\n", i, bdatos[i].numero, bdatos[i].anio, bdatos[i].cod_oficina);
    //cerramos los archivos (no olvidar!)
    fclose(fp);
    fclose(fp2);

    puts("\n\nfin del programa");


    return 0;
}

