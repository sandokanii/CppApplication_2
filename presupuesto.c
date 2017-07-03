/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "presupuesto.h"

void AltaPresu(){
    FILE *pf;
    Presupuesto presu;
    pf = fopen("Presupuesto.dat", "r+");
    char codigo[5];
    char codigo1[5];
    int bandera = 0;        
    do{
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
    } while(!(bandera == 0));
        strcpy(presu.codigo , codigo1);
        bandera = 2;
    printf("Ingrese Fecha\n");
    scanf("%s",presu.fecha);
    printf("Ingrese CUIT\n");
    scanf("%s",presu.cuit);
    printf("Ingrese Total\n");
    scanf("%f",&presu.total);
    printf("Ingrese Descuento\n");
    scanf("%f",&presu.descuento);
    fseek(pf,0L,SEEK_END);
    fwrite(&presu,sizeof(Presupuesto),1,pf);
    fclose(pf);
    system("clear");
    
    
    
}
void ListadoPresu(){
    FILE *pf;
    Presupuesto presu;
    pf = fopen("Presupuesto.dat","r");
    fread(&presu,sizeof(Presupuesto),1,pf);
    while(!feof(pf)){
        printf("\n\t\t%s ; %s ; %s ; %.2f ; %.2f\n",presu.codigo,presu.fecha,presu.cuit,presu.total,presu.descuento);
 
        fread(&presu,sizeof(Presupuesto),1,pf);
    }
   // system("color C");
  //  printf("presione [INTRO] para continuar...");
   // getchar();
    fclose(pf);
} 
void ModifPresu(){
    FILE *pf,*pfaux;
    Presupuesto presu;
    char codigoaux[5];
    pf = fopen("Presupuesto.dat","r+");
    pfaux = fopen("Presupuestoaux.dat","r+");
    printf("Ingrese Código\n");
    scanf("%s",codigoaux);
    fread(&presu,sizeof(Presupuesto),1,pf);
        while (!feof(pf)){
                if (presu.codigo != codigoaux){
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&presu,sizeof(Presupuesto),1,pfaux);
                }else{
                    printf("Ingrese Fecha\n");
                    scanf("%s",presu.fecha);
                    printf("Ingrese CUIT\n");
                    scanf("%s",presu.cuit);
                    printf("Ingrese Total\n");
                    scanf("%f",&presu.total);
                    printf("Ingrese Descuento\n");
                    scanf("%f",&presu.descuento);
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&presu,sizeof(Presupuesto),1,pfaux);
                }
            fread(&presu,sizeof(Presupuesto),1,pf);
        }
    fclose(pf);
    fclose(pfaux);
    remove("Presupuesto.dat");
    rename("Presupuestoaux.dat","Presupuesto.dat");
} 
void BajaPresu(){
    FILE *pf,*pfaux;
    Presupuesto presu;
    char codigoaux[5];
    pf = fopen("Presupuesto.dat","r");
    pfaux = fopen("Presupuestoaux.dat","a");
    printf("Ingrese Código\n");
    scanf("%s",codigoaux);
    fread(&presu,sizeof(Presupuesto),1,pf);
        while (!feof(pf)){
                if (presu.codigo != codigoaux){
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&presu,sizeof(Presupuesto),1,pfaux);
                }
            fread(&presu,sizeof(Presupuesto),1,pf);
        }
    fclose(pf);
    fclose(pfaux);
    remove("Presupuesto.dat");
    rename("Presupuestoaux.dat","Presupuesto.dat");
} 
