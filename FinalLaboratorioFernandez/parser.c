#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "logistica.h"

int parser_logicaFromText(FILE* pFile , LinkedList* pArrayListLogica)
{
    char idAuxEnvio[2000];
    char nombreAux[2000];
    char idAuxCamion[2000];
    char destinoAux[2000];
    char kilometroAux[2000];
    char entregaAux[2000];

    eLogica* logicaAux;
    int r, retorno = 0;

    r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idAuxEnvio,
                                                               nombreAux,
                                                               idAuxCamion,
                                                               destinoAux,
                                                               kilometroAux,
                                                               entregaAux);

    while(!feof(pFile))
    {
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",  idAuxEnvio,
                                                                    nombreAux,
                                                                    idAuxCamion,
                                                                    destinoAux,
                                                                    kilometroAux,
                                                                    entregaAux);

          if(r == 6)
          {
              logicaAux = logica_newParametros(idAuxEnvio, idAuxCamion, nombreAux, destinoAux, kilometroAux, entregaAux);
                if(logicaAux != NULL)
                {
                    ll_add(pArrayListLogica, logicaAux);
                    retorno = 1;
                }
          }
    }
    return retorno;
}
