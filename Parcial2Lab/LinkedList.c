#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int i;
    int size = ll_len(this);

    if(this != NULL){
        if(nodeIndex >= 0 && nodeIndex < size)
        {
            pNode = this->pFirstNode;

            if(pNode != NULL)
            {
                for(i = 0; i < size; i++)
                {
                    if(i == nodeIndex)
                    {
                        break;
                    }
                    else
                    {
                        pNode = pNode->pNextNode;
                    }
                }

            }
        }
   }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNewNode = malloc(sizeof(Node));
    Node* pNode;
    int size = ll_len(this);
    pNewNode->pElement = pElement;
    if(this!= NULL && nodeIndex >= 0 && nodeIndex <= size)
    {
        if(nodeIndex > 0)
        {
            pNode = getNode(this,nodeIndex-1);
            pNewNode->pNextNode = pNode->pNextNode;
            pNode->pNextNode = pNewNode;
            this->size++;
            returnAux = 0;
        }else if(nodeIndex == 0)
        {
            pNewNode->pNextNode=this->pFirstNode;
            this->pFirstNode=pNewNode;
            this->size++;
            returnAux=0;
        }

    }
    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int size;

    if(this != NULL)
    {
        size = ll_len(this);
        addNode(this, size, pElement);
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    int size = ll_len(this);
    Node* pNode;
    void* returnAux = NULL;

    if(this != NULL && index >= 0 && index <= size)
    {
        pNode = getNode(this, index);
        if(pNode != NULL)
        {
            returnAux = pNode->pElement;
        }
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNode;
    int size = ll_len(this);

    if(this != NULL && index >= 0 && index <= size)
    {
        pNode = getNode(this, index);

        if(pNode != NULL)
        {
            pNode->pElement = pElement;
            returnAux = 0;
        }
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNodeUno;
    Node* pNodeDos;
    int size = ll_len(this);
    if(this != NULL && index >= 0 && index < size)
    {
            if(index > 0)
            {
                pNodeUno = getNode(this, index);
                pNodeDos = getNode(this, index -1);
                pNodeDos->pNextNode = pNodeUno->pNextNode;
                free(pNodeUno);
                this->size--;
                returnAux = 0;
            }else if(index == 0)
            {
                pNodeUno = this->pFirstNode;
                this->pFirstNode = pNodeUno->pNextNode;
                this->size--;
                free(pNodeUno);
                returnAux=0;
            }

    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int size = ll_len(this);
    int i;

    if(this != NULL)
    {
       for(i = 0; i < size; i++)
       {
           ll_remove(this, i);
       }

       returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        ll_clear(this);
        free(this);
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* pNode;
    int size = ll_len(this);
    int i;

    if(this != NULL)
    {
        for(i = 0; i < size; i++)
        {
           pNode = getNode(this, i);

            if(pNode != NULL)
            {
                if(pElement == pNode->pElement)
                {
                    returnAux = i;
                    break;
                }
            }
        }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int size = ll_len(this);

    if(this != NULL)
    {
        if(size > 0)
        {
            returnAux = 0;
        }else
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int auxAdd;
    int size = ll_len(this);

    if(this != NULL && index >= 0 && index <= size)
    {
        auxAdd = addNode(this, index, pElement);

        if(auxAdd == 0 && this->size > size)
        {
            returnAux = 0;
        }
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int size = ll_len(this);
    Node* pNode;

    if(this != NULL && index >= 0 && index <= size)
    {
        pNode = ll_get(this, index);

        if(pNode != NULL)
        {
           ll_remove(this, index);
           returnAux = pNode;
        }
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* pNode;
    int size = ll_len(this);
    int i;

    if(this != NULL)
    {
        for(i = 0; i < size; i++)
        {
            pNode = getNode(this, i);

            if(pNode != NULL)
            {
                if(pElement == pNode->pElement)
                {
                    returnAux = 1;
                    break;
                }

            }
        }

        if(i == size)
        {
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
    int cantidad = 0;
    int sizeUno = ll_len(this);
    int sizeDos = ll_len(this2);
    Node* pNodeUno;
    Node* pNodeDos;

    if(this != NULL && this2 != NULL)
    {
        for(i = 0; i < sizeUno; i++)
        {
           pNodeUno = getNode(this, i);
           pNodeDos = getNode(this2, i);

            if(pNodeUno->pElement == pNodeDos->pElement)
            {
                cantidad++;
            }
        }

        if(cantidad == sizeUno && sizeUno == sizeDos)
        {
            returnAux = 1;
        }
        else
        {
            returnAux = 0;
        }

    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pAuxElement;
    int i;
    int auxAdd;
    int size = ll_len(this);

    cloneArray = ll_newLinkedList();

    if(this != NULL && from >= 0 && to >= 0 && from <= size && to <= size)
    {
        for(i = from; i < to; i++)
        {
            pAuxElement = ll_get(this, i);
            auxAdd = ll_add(cloneArray, pAuxElement);

            if(auxAdd == 0)
            {
                continue;
            }
            else
            {
                free(cloneArray);
                cloneArray = NULL;
                break;
            }

        }

    }
    else
    {
        free(cloneArray);
        cloneArray = NULL;
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    void* pAuxElement;
    int i;
    int auxAdd;
    int size = ll_len(this);

    cloneArray = ll_newLinkedList();

    if(this != NULL)
    {
        for(i = 0; i < size; i++)
        {
            pAuxElement = ll_get(this, i);
            auxAdd = ll_add(cloneArray, pAuxElement);

            if(auxAdd == 0)
            {
                continue;
            }
            else
            {
                free(cloneArray);
                cloneArray = NULL;
                break;
            }

        }

    }
    else
    {
        free(cloneArray);
        cloneArray = NULL;
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int i;
    void* pAuxFuncUno;
    void* pAuxFuncDos;
    int flag;
    int size = ll_len(this);
    int auxValue;
    if(this != NULL && size > 0 && pFunc != NULL && (order == 0 || order == 1))
    {
        do
        {
            flag = 0;

            for(i = 0; i < size; i++)
            {
                pAuxFuncUno = ll_get(this, i);
                pAuxFuncDos = ll_get(this, i+1);

                if(pAuxFuncUno != NULL && pAuxFuncDos != NULL)
                {
                    auxValue = pFunc(pAuxFuncUno,pAuxFuncDos);

                    if((auxValue == -1 && order == 0) || (auxValue == 1 && order == 1))
                    {
                        flag = 1;
                        ll_set(this, i, pAuxFuncDos);
                        ll_set(this, i+1, pAuxFuncUno);
                    }

                }

            }
        }while(flag == 1);

        returnAux = 0;
    }
    return returnAux;

}

int ll_map(LinkedList* this, int (*pFunc)(int*))
{
    int returnAux = -1;
    int i;
    int* pAuxFunc;
    int size = ll_len(this);
    int auxValue;
    int flag;

    if(this != NULL && size > 0 && pFunc != NULL)
    {
        do
        {
            flag = 0;
            for(i = 0; i < size; i++)
            {
                pAuxFunc = ll_get(this, i);

                if(pAuxFunc != NULL)
                {
                    auxValue = pFunc(pAuxFunc);

                    if(auxValue == 1 || auxValue == 2 || auxValue == 3)
                    {
                        flag = 1;
                        ll_set(this, i, pAuxFunc);
                    }
                }
            }

        }while(flag == 1);

        returnAux = 0;
    }

    return returnAux;
}
