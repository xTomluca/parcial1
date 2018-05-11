#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "aviso.h"
#include "utn.h"
#include "cliente.h"




static int proximoId(void);
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
            getValidInt("\nID?\n","\nNumero no valido\n",&idPant,0,999999,2);
            posPant = cliente_buscarPorIdCliente(clientes,lenClientes,idPant);
            if(posPant>=0)
            {
                if(!getValidInt("\nRUBRO?","\nNumero no valido\n",&rubro,0,999999,2))
                {
                    if(!getValidString("\nINGRESE TEXTO AVISO: \n","INVALIDO\n","MAXIMO 64 CAR\n",texto,64,2))
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

int pausarPublicacion(Aviso* array, int limite){
    int id,retorno=1,confirmar=0;
    if(limite > 0 && array != NULL)
    {
        if(!getValidInt("ID?","\nNumero no valido\n",&id,0,1000,2))
        {
            if(array[id].id==id && array[id].isEmpty != 1 && array[id].isEmpty == 0)
            {
                getValidInt("DESEA CONTINUAR?? 1 = (SI) / 8 (NO): ","\nINVALIDO\n",&confirmar,0,1,2);
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
        if(!getValidInt("ID?","\nNumero no valido\n",&id,0,1000,2))
        {
            if(array[id].id==id && array[id].isEmpty != 1 && array[id].isEmpty == 2)
            {
                getValidInt("DESEA CONTINUAR?? 1 = (SI) / 8 (NO): ","\nINVALIDO\n",&confirmar,0,1,2);
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

int aviso_mostrar(Cliente* array,Aviso* arrayAviso,int limiteC, int limiteA)
{
    int retorno = -1;
    int i,j,cantidad;
    if(limiteC > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limiteC;i++)
        {
            for(j=0;j<limiteA;i++)
            {
                if(array[i].idCliente==arrayAviso[j].id)
                {
                    cantidad+=1;
                }
            }
            if(cantidad>=0)
            {
                if(!array[i].isEmpty)
                printf("ID US: - %d - NOMBRE: %s - APELLIDO: %s - CUIT: %.0f - ESTADO = %d\n",array[i].idCliente, array[i].nombre, array[i].apellido, array[i].cuit, array[i].isEmpty);
            }

        }
    }
    return retorno;
}










