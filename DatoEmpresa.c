/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DatoEmpresa.h"
/*typedef struct{
    char reg_entidad[30];
    char domicilio[30];
    int telefono;
    int cuit;
}registro;*/
void DatoEmpresa(){
 char nombre_empresa[30];
    FILE *pf;
    registro regist;
    pf = fopen("Registracion.dat", "a");
    //registro base[1];
    while (getchar() != '\n');
    printf("Registre la entidad\n");
    fflush(stdin);
    gets(regist.reg_entidad);
    sprintf(nombre_empresa, "%s", regist.reg_entidad);
    printf("Domicilio\n");
    gets(regist.domicilio);
    printf("Telefono\n");
    scanf("%i",&regist.telefono);
    printf("Cuit\n");
    scanf("%i",&regist.cuit);
    fseek(pf, 0L, SEEK_END);
    fwrite(&regist, sizeof (registro), 1, pf);
    fclose(pf);
}