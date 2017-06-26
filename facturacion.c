/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int numero;
    char fecha[11];
    char cuit[30];
    char cliente[30];
    char producto[30];
    int cantidad;
    float precio;
    float total;
    float descuento;
}Factura;

void AltaFactura();

void AltaFactura(){   
    FILE *pf;
    Factura factu;
    pf = fopen("Factura.dat","a");
    printf("Ingrese Numero de factura\n");
    scanf("%i",&factu.numero);
    printf("Ingrese Fecha\n");
    scanf("%s",factu.fecha);
    printf("Ingrese CUIT\n");
    scanf("%s",factu.cuit);
    printf("Ingrese Total\n");
    scanf("%f",&factu.total);
    printf("Ingrese Descuento\n");
    scanf("%f",&factu.descuento);
    fseek(pf,0L,SEEK_END);
    fwrite(&factu,sizeof(Factura),1,pf);
    fclose(pf);
    system("clear");
  }
    