/*
 * Código para diagnostico de conhecimento básico em C.
 * Desenvolvido para o curso CET-088, CET-082
 * Modificado por Leard Fernandes, 2017
 * Developed by R. E. Bryant, 2017
*/

 /*
  * Este programa implementa uma fila que suporta ambas as operações FIFO e LILO.
  *
  * Ele utiliza uma lista unicamente ligada para representar o conjunto de
  * elementos da fila
*/

#include <stdlib.h>
#include <stdio.h>

#include "harness.h"
#include "queue.h"

/*
  Cria uma fila vazia.
  Retorna NULL se o espaço na puder ser alocado.
*/
queue_t *q_new()
{
    char *error_text = "An error occurred on malloc\n";
    queue_t *q = malloc(sizeof(queue_t));
    if (!q_allocated(q, error_text)) {
      return false;
    }

    q->head = NULL;
    q->tail = NULL;
    q->size = 0;

    return q;
}

/*  Libera todo o espaço utilizado pela fila. */
void q_free(queue_t *q)
{
    /* Como liberar os elementos da lista? */
    /* Libera a estrutura da fila */
    free(q);
}

/*
  Tenta inserir o elemento na cabeça da fila.
  Retorna true se houve sucesso
  Retorna false se q é NULL ou não foi possível alocar espaço
*/
bool q_insert_head(queue_t *q, int v)
{
    char *error_text = "The queue adress can't be NULL\n";
    if (!q_allocated(q, error_text)) {
      return false;
    }

    error_text = "An error occurred on malloc\n";
    list_ele_t *newh;
    newh = malloc(sizeof(list_ele_t));
    if (!ele_allocated(newh, error_text)) {
      return false;
    }

    newh->value = v;
    newh->next = q->head;
    q->head = newh;
    q->size += 1;

    if (q->size == 0)
      q->tail = q->head;

    return true;
}


/*
  Tenta inserir o elemento na calda da fila.
  Retorna true se houve sucesso
  Retorna false se q é NULL ou não foi possível alocar espaço
*/
bool q_insert_tail(queue_t *q, int v)
{
    char *error_text = "The queue adress can't be NULL\n";
    if (!q_allocated(q, error_text)) {
      return false;
    }

    error_text = "An error occurred on malloc\n";
    list_ele_t *newt;
    newt = malloc(sizeof(list_ele_t));
    if (!ele_allocated(newt, error_text)) {
      return false;
    }

    newt->value = v;
    newt->next = NULL;

    if (q->tail != NULL)
      q->tail->next = newt;
      
      q->tail = newt;
    if(q->head == NULL)
      q->head = q->tail;
    q->size += 1;


    return true;
}

/*
  Tenta remover o elemento na cabeça da fila.
  Retorna true se houve sucesso
  Retorna false se q é NULL ou vazia
  Se vp é não-NULL e o elemento removido, armazena o valor removido em *vp
  Qualquer armazenamento não utilizado deve ser liberado
*/
bool q_remove_head(queue_t *q, int *vp)
{
    char *error_text = "The queue adress can't be NULL\n";
    if (!q_allocated(q, error_text)) {
      return false;
    }
    error_text = "The queue is empty\n";
    if (!ele_allocated(q->head, error_text)) {
      return false;
    }
    error_text = "The removed element adress can't be NULL\n";
    if (vp == NULL) {
      printf("%s", error_text);
      return false;
    }

    list_ele_t *vp_adr;
    vp_adr = q->head;
    *vp = vp_adr->value;
    q->head = vp_adr->next;
    q->size -= 1;
    
    free(vp_adr);
    return true;
}

/*
  Retorna o número de elementos na fila.
  Retorna 0 se q é NULL ou vazia
*/
int q_size(queue_t *q)
{
    char *error_text = "The queue adress can't be NULL\n";
    if (!q_allocated(q, error_text)) {
      return false;
    }

    return q->size;
}

/*
  Inverte os elementos na fila.

  Sua implementação não dever alocar ou liberar quaisquer elementos (e.g., pela
  chamada de q_insert_head ou q_remove_head). Ao invés disso, ela deverá
  modificar os ponteiros na estrutura de dados existente.
*/
void q_reverse(queue_t *q)
{
    return;
}

bool q_allocated(queue_t *q, char *error_text)
{
  if (q == NULL) {
    printf("%s\n", error_text);
    return false;
  }

  return true;
}

bool ele_allocated(list_ele_t *q, char *error_text)
{
  if (q == NULL) {
    printf("%s", error_text);
    return false;
  }

  return true;
}