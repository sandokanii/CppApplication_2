#ifndef DATOEMPRESA_H
#define DATOEMPRESA_H

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* DATOEMPRESA_H */

typedef struct{
    char reg_entidad[30];
    char domicilio[30];
    int telefono;
    int cuit;
}registro;

void DatoEmpresa();