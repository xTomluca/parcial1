#ifndef AVISO_H_INCLUDED
#define AVISO_H_INCLUDED
#include "cliente.h"
typedef struct
{
    char nombre[50];
    //------------
    int idAviso;
    int isEmpty;
}Aviso;
#endif // FANTASMA_H_INCLUDED


int aviso_init(Aviso* array,int limite);
int aviso_mostrar(Aviso* array,int limite);
int aviso_mostrarDebug(Aviso* array,int limite);
int aviso_alta(Aviso* array,int limite);
int aviso_baja(Aviso* array,int limite, int id);
int aviso_modificacion(Aviso* array,int limite, int id);
int aviso_ordenar(Aviso* array,int limite, int orden);
int buscarLugarLibreAviso(Aviso* array,int limite);
int proximoId();
int aviso_altaForzada();


