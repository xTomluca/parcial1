#ifndef AVISO_H_INCLUDED
#define AVISO_H_INCLUDED
typedef struct
{
    int idCliente;
    int rubro;
    char texto[64];
    //------------
    int id;
    int isEmpty;
}Aviso;

#include "cliente.h"


int aviso_init(Aviso* array,int limite);
int aviso_alta(Aviso* arrayC,int limite,
              Cliente* pantallas, int lenClientes);

int aviso_baja(Aviso* array,int limite, int id);
int aviso_mostrar(Cliente* array,Aviso* arrayAviso,int limiteC, int limiteA);
int pausarPublicacion(Aviso* array, int limite);
int reanudarPublicacion(Aviso* array, int limite);
int aviso_altaForzada(Aviso* arrayC,int limite,Cliente* pantallas, int lenClientes,int idCliente,char* archivo,char* cuit,int dias);

#endif // PANTALLA_H_INCLUDED


