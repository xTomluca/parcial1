#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Contratacion.h"
#include "utn.h"
#include "Pantalla.h"



//Funciones privadas
static int proximoId(void);
static int buscarPorId(Aviso* array,int limite, int id);
static int buscarLugarLibre(Aviso* array,int limite);
//__________________



/** \brief
 * \param array Cliente*
 * \param limite int
 * \return int
 *
 */
int aviso_init(Aviso* array,int limite)
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

int aviso_mostrarDebug(Aviso* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            //printf("[DEBUG] - %d - %s - %s - %d - %d\n",array[i].id, array[i].cuit,array[i].archivo,array[i].dias, array[i].isEmpty);
        }
    }
    return retorno;
}

int aviso_mostrar(Aviso* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            //if(!array[i].isEmpty)
               // printf("[RELEASE] - %d - %s - %s - %d - %d\n",array[i].id, array[i].cuit,array[i].archivo,array[i].dias, array[i].isEmpty);
        }
    }
    return retorno;
}

int aviso_alta(Aviso* arrayC,int limite,
              Cliente* clientes, int lenClientes)
{
    int retorno = -1;
    int i;
    int idPant;
    int rubro;
    char texto[64];
    int posPant;



    if(limite > 0 && arrayC != NULL)
    {
        i = buscarLugarLibre(arrayC,limite);
        if(i >= 0)
        {
            getValidInt("ID?","\nNumero no valido\n",&idPant,0,999999,2);
            posPant = cliente_buscarPorIdCliente(clientes,lenClientes,idPant);
            if(posPant>=0)
            {
                if(!getValidInt("ID?","\nNumero no valido\n",&rubro,0,999999,2))
                {
                    if(!getValidString("Ingrese texto\n","INVALIDO\n","MAXIMO 64 CAR\n",texto,64,2))
                    {
                        retorno = 0;
                        arrayC[i].idCliente = idPant;
                        arrayC[i].rubro=rubro;
                        strcpy(arrayC[i].texto,texto);
                        arrayC[i].isEmpty=0;
                        arrayC[i].id = proximoId();
                        printf("\nID AVISO: %d\n",arrayC[i].id);
                    }
                }
            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}


int aviso_baja(Aviso* array,int limite, int id)
{
    int indiceAEliminar;
    int retorno=-1;
    indiceAEliminar = buscarPorId(array,limite,id);
    if(indiceAEliminar>=0)
    {
        array[indiceAEliminar].isEmpty=1;
        retorno=0;
    }
    return retorno;
}


static int buscarLugarLibre(Aviso* array,int limite)
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


//int cliente_buscarPorId(Cliente* array,int limite, int id)
static int buscarPorId(Aviso* array,int limite, int id)
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

int pausarPublicacion(Aviso* array, int limite){
    int id,retorno=1,confirmar=0;
    if(limite > 0 && array != NULL)
    {
        if(getValidInt("ID?","\nNumero no valido\n",&id,0,999999,2))
        {
            if(array[id].idCliente==id && array[id].isEmpty != 1 && array[id].isEmpty == 0)
            {
                getValidInt("DESEA CONTINUAR?? 1 = (SI) / 8 (NO)","\nINVALIDO\n",&confirmar,0,1,2);
                if(confirmar)
                {
                    retorno=0;
                    array[id].isEmpty=2;
                }
            }


        }
    }
    return retorno;
}

int reanudarPublicacion(Aviso* array, int limite){
    int id,retorno=1,confirmar=0;
    if(limite > 0 && array != NULL)
    {
        if(getValidInt("ID?","\nNumero no valido\n",&id,0,999999,2))
        {
            if(array[id].idCliente==id && array[id].isEmpty != 1 && array[id].isEmpty == 2)
            {
                getValidInt("DESEA CONTINUAR?? 1 = (SI) / 8 (NO)","\nINVALIDO\n",&confirmar,0,1,2);
                if(confirmar)
                {
                    retorno=0;
                    array[id].isEmpty=0;
                }
            }

        }
    }
    return retorno;
}












