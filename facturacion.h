/* 
 * File:   facturacion.h
 * Author: usuario
 *
 * Created on 26 de junio de 2017, 16:41
 */

#ifndef FACTURACION_H
#define FACTURACION_H

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* FACTURACION_H */

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
