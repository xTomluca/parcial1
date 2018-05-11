#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "aviso.h"
#include "cliente.h"
#include "utn.h"

#define DEFINE_DEL_ARCHIVO  "hola"

static int proximoId(void);
static int buscarLugarLibre(Cliente* array,int limite);
//__________________



/** \brief
 * \param array Cliente*
 * \param limite int
 * \return int
 *
 */
int cliente_init(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty=1;
        }
    }
    return retorno;
}

int cliente_alta(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    char nombre[50];
    char apellido[50];
    float cuit;
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",nombre,40,2))
            {
                if(!getValidString("\nApellido? ","\nEso no es un Apellido","El maximo es 40",apellido,40,2))
                {
                    if(!getValidFloat("\nCUIT? ","\nEso no es un CUIT",&cuit,0,99999999999999999,2))
                    {

                            retorno = 0;
                            strcpy(array[i].nombre,nombre);
                            strcpy(array[i].apellido,apellido);
                            array[i].cuit=cuit;
                            array[i].idCliente = proximoId();
                            array[i].isEmpty = 0;

                    }
                }
            }
            else
            {
                retorno = -3;
            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}


int cliente_baja(Cliente* array,int limite, int id)
{
    int indiceAEliminar;
    int retorno=-1;
    int confirmar=0;
    indiceAEliminar = cliente_buscarPorIdCliente(array,limite,id);
    printf("INGRESE 1 PARA CONFIRMAR: \n");
    fflush(stdin);
    scanf("%d", &confirmar);
    if(confirmar){
        if(indiceAEliminar>=0)
        {
            array[indiceAEliminar].isEmpty=1;
            retorno=0;
        }
    }
    else
    {
        printf("CANCELO BAJA\n");
    }
    return retorno;
}




int cliente_modificacion(Cliente* array,int limite, int id)
{
    int retorno = -1;
    int indiceAModificar;
    char nombre[50];
    char apellido[50];
    float cuit;

    indiceAModificar = cliente_buscarPorIdCliente(array,limite,id);
    if(indiceAModificar>=0)
    {
        if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",nombre,40,2))
        {
            if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",apellido,40,2))
            {
                if(!getValidFloat("\nCUIT? ","\nEso no es un CUIT",&cuit,0,99999999999999999,2))
                {
                    retorno = 0;
                    strcpy(array[indiceAModificar].nombre,nombre);
                    strcpy(array[indiceAModificar].apellido,apellido);
                    array[indiceAModificar].cuit=cuit;
                }
            }
        }
        else
        {
            retorno = -3;
        }
    }
    return retorno;
}


static int buscarLugarLibre(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}



static int proximoId(void)
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}


int cliente_buscarPorIdCliente(Cliente* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idCliente==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}



int cliente_altaForzada(Cliente* array,int limite,char* nombre,char* direccion, float precio)
{
    int retorno = -1;
    int i;

    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(array[i].nombre,nombre);
            strcpy(array[i].apellido,direccion);
            array[i].cuit=precio;

            //------------------------------
            //------------------------------
            array[i].idCliente = proximoId();
            array[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}






