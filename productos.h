/* 
 * File:   productos.h
 * Author: usuario
 *
 * Created on 23 de junio de 2017, 20:53
 */

#ifndef PRODUCTOS_H
#define PRODUCTOS_H

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* PRODUCTOS_H */

typedef struct{
    char codigo[5];
    char detalle[30];
    float precio;
    float costo;
    char prov[30];
}Producto; 
void AltaProds();
void BajaProds();
void ModifProds();
void ListadoProds();

