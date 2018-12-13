#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct
{
    int idEnvio;
    char nombreProducto[128];
    int idCamion;
    char zonaDestino[128];
    int kilometros;
    int tipoEntrega;

}eLogica;

eLogica* logica_new();
int logica_controllerLogica(char* fileName, LinkedList* pArrayListLogica);
eLogica* logica_newParametros(char* idStrUno, char* idStrDos, char* nombreStr,char* destinoStr, char* kilometroStr, char* entregaStr);
int parser_logicaFromText(FILE* pFile , LinkedList* pArrayListLogica);
void logica_logicaList(LinkedList* pArrayList);


//Seters.
int logica_setIdEnvio(eLogica* this,int envio);
int logica_setIdCamion(eLogica* this,int camion);
int logica_setNombre(eLogica* this,char* nombre);
int logica_setKilometros(eLogica* this,int kilometros);
int logica_setDestino(eLogica* this,char* destino);
int logica_setEntrega(eLogica* this,int entrega);

//Getters.
int logica_getIdEnvio(eLogica* this,int* id);
int logica_getIdCamion(eLogica* this,int* id);
int logica_getNombre(eLogica* this,char* nombre);
int logica_getDestino(eLogica* this,char* destino);
int logica_getKilometros(eLogica* this,int* kilometros);
int logica_getEntrega(eLogica* this,int* entrega);



#endif // employee_H_INCLUDED
