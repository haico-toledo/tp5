// TAD Fila de prioridades (FPRIO) genérica
// Carlos Maziero, DINF/UFPR, Out 2024
// Marcos Castilho, inclui as structs no arquivo.c, Out 2025
// Implementação com lista encadeada simples

#include <stdio.h>
#include <stdlib.h>
#include "fprio.h"

// descreve um nodo da fila de prioridades
// NAO altere estas estruturas
struct fpnodo_t
{
  void *item ;          // item associado ao nodo
  int   tipo ;          // tipo do item
  int   prio ;          // prioridade do item
  struct fpnodo_t *prox;    // próximo nodo
};

// descreve uma fila de prioridades
struct fprio_t
{
  struct fpnodo_t *prim ;   // primeiro nodo da fila
  int num ;         // número de itens na fila
} ;

// A COMPLETAR

struct fprio_t *fprio_cria ()
{
	struct fprio_t *fp;
	fp = malloc(sizeof(struct fprio_t));
	
	if (!fp)
		return NULL;
		
	fp->num = 0;
	fp->prim = NULL;
	
	return fp;
}


struct fprio_t *fprio_destroi (struct fprio_t *f)
{
	if (!f)
		return NULL;
		
	struct fpnodo_t *aux;
	struct fpnodo_t *ptr;
	
    ptr = f->prim;

	/*incrementa iterador e libera nodo anterior*/
    while ((ptr != NULL))
    {
        aux = ptr;
        ptr = ptr->prox;
        free(aux);    
    }

    free(f);
    f = NULL;
    
    return NULL;
}

//int fprio_insere (struct fprio_t *f, void *item, int tipo, int prio)


//void *fprio_retira (struct fprio_t *f, int *tipo, int *prio)


int fprio_tamanho (struct fprio_t *f)
{
	if (!f)
		return -1;
	
	return f->num;
}


void fprio_imprime (struct fprio_t *f)
{	
	if (!f)
		return;

	struct fpnodo_t *aux;
	
	/*fp de tamanho 0*/
	if (!f->prim)
		return;

	aux = f->prim;
	
	/*fp de tamanho 1*/
	if (!aux->prox->prox)
	{
		printf("(%d %d)", aux->tipo, aux->prio);
		return;
	}	
	
	/*caso geral*/
	while (aux->prox->prox != NULL)
	{
		printf("(%d %d) ", aux->tipo, aux->prio);
		
		aux = aux->prox;
	}
	
	printf("(%d %d) ", aux->tipo, aux->prio);	
	printf("(%d %d)", aux->prox->tipo, aux->prox->prio);
	
	return;
}

