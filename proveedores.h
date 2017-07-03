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
    char codigo[5];
    char nombre[30];
    char telefono[30];
    char email[30];
}Proveedores; 

void AltaProvs();
void BajaProvs();
void ModifProvs();
void ListadoProvs();