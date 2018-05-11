#ifndef CONTRATACION_H_INCLUDED
#define CONTRATACION_H_INCLUDED
typedef struct
{
    int idCliente;
    int rubro;
    char texto[64];
    //------------
    int id;
    int isEmpty;
}Aviso;

#include "pantalla.h"


int aviso_init(Aviso* array,int limite);
int aviso_mostrar(Aviso* array,int limite);
int aviso_mostrarDebug(Aviso* array,int limite);

int aviso_alta(Aviso* arrayC,int limite,
              Cliente* pantallas, int lenClientes);

int aviso_baja(Aviso* array,int limite, int id);
int aviso_modificacion(Aviso* array,int limite, int id);
int aviso_ordenar(Aviso* array,int limite, int orden);
int aviso_ordenarCuit(Aviso* array,int limite, int orden);
int pausarPublicacion(Aviso* array, int limite);
int reanudarPublicacion(Aviso* array, int limite);

int aviso_altaForzada(Aviso* arrayC,int limite,Cliente* pantallas, int lenClientes,int idCliente,char* archivo,char* cuit,int dias);

#endif // PANTALLA_H_INCLUDED


