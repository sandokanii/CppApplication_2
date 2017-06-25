/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   proveedores.h
 * Author: usuario
 *
 * Created on 23 de junio de 2017, 20:36
 */

#ifndef PROVEEDORES_H
#define PROVEEDORES_H

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* PROVEEDORES_H */

typedef struct{
    int codigo;
    char nombre[30];
    char telefono[30];
    char email[30];
}Proveedores; 

void AltaProvs();
void BajaProvs();
void ModifProvs();
void ListadoProvs();