/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   presupuesto.h
 * Author: usuario
 *
 * Created on 23 de junio de 2017, 20:53
 */

#ifndef PRESUPUESTO_H
#define PRESUPUESTO_H

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* PRESUPUESTO_H */

typedef struct{
    char codigo[5];
    char fecha[11];
    char cuit[30];
    float total;
    float descuento;
}Presupuesto; 
typedef struct{
    char codigo[5];
    char producto[30];
    int cantidad;
    float precio;
}DetPresupuesto; 

void AltaPresu();
void BajaPresu();
void ModifPresu();
void ListadoPresu();

