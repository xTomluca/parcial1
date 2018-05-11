#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"
#define QTY 10

int main()
{
    Cliente array[QTY];
    //int i;
    int menu;
    int auxiliarId;

    cliente_init(array,QTY);
    do
    {
        getValidInt("1.Alta\n2.Baja\n3.Modificar\n4.Mostrar\n5.Ordenar\n6.Mostrar Debug\n9.Salir\n","\nNo valida\n",&menu,1,9,1);
        switch(menu)
        {
            case 1:
                cliente_alta(array,QTY);
                break;
            case 2:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                cliente_baja(array,QTY,auxiliarId);
                break;
            case 3:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                cliente_modificacion(array,QTY,auxiliarId);
                break;
            case 4:
                cliente_mostrar(array,QTY);
                break;
            case 5:
                cliente_ordenar(array,QTY,0);
                break;
            case 6:
                cliente_mostrarDebug(array,QTY);
                break;
        }

    }while(menu != 9);

    return 0;
}
