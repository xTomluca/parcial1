#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pantalla.h"
#include "utn.h"
#include "Contratacion.h"
#include "informar.h"

int main()
{
    Cliente array[100];
    Aviso aviso[1000];
    int menu;
    int auxiliarId;

    cliente_init(array,100);
    aviso_init(aviso,1000);

    cliente_altaForzada(array,100,"Pepe","Cabrera",305359554);
    cliente_altaForzada(array,100,"Josesito","Belgrano 250",301212054);
    cliente_altaForzada(array,100,"Martin","Cerrito 300",333554780);
    cliente_altaForzada(array,100,"Mario","Lavalle 450",32554896);
    cliente_altaForzada(array,100,"Dimitri","Mitre 150",35335673);
    cliente_altaForzada(array,100,"Arturito","Cerrito 300",33335600);





    do
    {
        getValidInt("\n\n1.Alta\n2.Baja\n3.Modificar\n4.Mostrar\n5.Ordenar\n6.Mostrar Debug\n7.Contratar\n9.Salir\n","\nNo valida\n",&menu,1,15,1);
        switch(menu)
        {
            case 1:
                cliente_alta(array, 100);
                break;
            case 2:
                if(!getValidInt("INGRESE ID","ID INVALIDO", &auxiliarId, 0,100,2))
                {
                    cliente_modificacion(array, 100,auxiliarId);
                }

                break;
            case 3:
                if(!getValidInt("INGRESE ID","ID INVALIDO", &auxiliarId, 0,100,2))
                {
                    cliente_baja(array, 100,auxiliarId);
                }
                break;
            case 4:
                aviso_alta(aviso, 1000, array, 100);
                break;
            case 5:
                pausarPublicacion(aviso, 1000);
                break;
            case 6:
                reanudarPublicacion(aviso, 1000);
                break;
            case 7:
                cliente_mostrar(array, 100);
                break;
            case 8:

                break;
            case 10:

                break;
        }

    }while(menu != 9);

    return 0;
}
