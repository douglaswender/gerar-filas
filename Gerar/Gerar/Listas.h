#include <stdlib.h>
typedef struct NODO
{
        int dado;
        struct NODO *proximo;
        } LISTA;

LISTA *crialista()
{
      struct NODO *cabeca;
      cabeca = (LISTA *)malloc(sizeof (LISTA));
      cabeca -> proximo = NULL;
      return cabeca;
      }

int listavazia(LISTA *cabeca)
{
    return cabeca -> proximo == NULL;
}

int inserir(LISTA *cabeca, int posicao, int elemento)
{
    struct NODO *p, *q = cabeca;
    int i;
    for (i = 0; i < posicao && q != NULL; i++)
        q = q -> proximo;
    if (q == NULL)
          return 0;
    p = (struct NODO *)malloc(sizeof (struct NODO));
    p -> dado = elemento;
    p -> proximo = q -> proximo;
    q -> proximo = p;
    return 1;
}
int retirar(LISTA *cabeca, int posicao)
{
    struct NODO *p = cabeca, *anterior;
    int aux, i;
    for (i = 0; i <= posicao && p != NULL; i++)
    {
        anterior = p;
        p = p -> proximo;
        }
    if (p == NULL)
           return 0;
    aux = p -> dado;
    anterior -> proximo = p -> proximo;
    free(p);
    return aux;
}
