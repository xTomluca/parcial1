#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"
#include "aviso.h"


int main()
{
    Cliente array[100];
    Aviso aviso[1000];
    int menu;
    int auxiliarId;

    cliente_init(array,100);
    aviso_init(aviso,1000);

    cliente_altaForzada(array,100,"Pepe","Cabrera",305359554);
    cliente_altaForzada(array,100,"Josesito","Belgrano",301212054);
    cliente_altaForzada(array,100,"Martin","Cerrito",333554780);
    cliente_altaForzada(array,100,"Mario","Lavalle",32554896);
    cliente_altaForzada(array,100,"Dimitri","Mitre",35335673);
    cliente_altaForzada(array,100,"Arturito","Cerrito",33335600);

    do
    {
        getValidInt("\n\n1.Alta\n2.Baja\n3.Modificar\n4.Publicar\n5.Pausar Publicacion\n6.Reanudar\n7.Imprimir clientes\n9.Salir\n\n","\nNo valida\n",&menu,1,15,1);
        switch(menu)
        {
            case 1:
                cliente_alta(array, 100);
                break;
            case 2:
                if(!getValidInt("\nINGRESE ID: ","ID INVALIDO", &auxiliarId, 0,100,2))
                {
                    cliente_modificacion(array, 100,auxiliarId);
                }
                break;
            case 3:
                if(!getValidInt("\nINGRESE ID","ID INVALIDO", &auxiliarId, 0,100,2))
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
                aviso_mostrar(array,aviso, 100, 1000);
                break;
        }

    }while(menu != 9);

    return 0;
}
