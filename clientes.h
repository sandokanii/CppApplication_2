/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   clientes.h
 * Author: usuario
 *
 * Created on 23 de junio de 2017, 20:53
 */

#ifndef CLIENTES_H
#define CLIENTES_H

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* CLIENTES_H */
typedef struct{
    int cuit;
    char cliente[30];
    char fechaalta[11];
    char email[30];
    char telefono[30];
}Clientes;

void AltaClientes();
void BajaClientes();
void ModifClientes();
void ListadoClientes();
