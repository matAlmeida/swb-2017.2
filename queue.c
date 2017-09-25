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
  char *error_text = "The queue adress can't be NULL\n";
  if (!q_allocated(q, error_text)) {
    return;
  }
  list_ele_t *fe;
  while (q->head->next != NULL) {
    fe = q->head;
    q->head = q->head->next;
    free(fe);
  }
  free(q->head);
  free(q);
}

/*
  Tenta inserir o elemento na cabeça da fila.
  Retorna true se houve sucesso
  Retorna false se q é NULL ou não foi possível alocar espaço
*/
bool q_insert_head(queue_t *q, int v)
{
  list_ele_t *newE;
  newE = malloc(sizeof(list_ele_t));

  if (q && newE) {
    newE->value = v;
    
    q->head ? (newE->next = q->head) : (newE->next = NULL);

    q->head = newE;

    if (!q->tail && (q->tail = q->head));

    q->size++;

    return true;
  }
  
  return false;
}


/*
  Tenta inserir o elemento na calda da fila.
  Retorna true se houve sucesso
  Retorna false se q é NULL ou não foi possível alocar espaço
*/
bool q_insert_tail(queue_t *q, int v)
{
  list_ele_t *newE;
  newE = malloc(sizeof(list_ele_t));
  
  if (q && newE) {
    newE->value = v;
    newE->next = NULL;

    if (q->tail && (q->tail->next = newE));

    q->tail = newE;

    if (!q->head && (q->head = q->tail));

    q->size++;

    return true;
  }

  return false;
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
  list_ele_t *remE;
  
  if (q && q->head) {
    if(vp && (*vp = q->head->value));

    remE = q->head;
    q->head = remE->next;
    q->size--;

    free(remE);
    return true;
  }

  return false;
}

/*
  Retorna o número de elementos na fila.
  Retorna 0 se q é NULL ou vazia
*/
int q_size(queue_t *q)
{
    if(q) return q->size;
    else return 0;
}

/*
  Inverte os elementos na fila.

  Sua implementação não dever alocar ou liberar quaisquer elementos (e.g., pela
  chamada de q_insert_head ou q_remove_head). Ao invés disso, ela deverá
  modificar os ponteiros na estrutura de dados existente.
*/
void q_reverse(queue_t *q)
{
    if ( q != NULL || q->size <=1 )
      return;

    list_ele_t *pre, *mid, *pos;

    pre = q->head;
    mid = pre->next;
    pos = mid->next;

    pre->next = NULL;
    mid->next = pre;
    pre = mid;
    mid = pos;
    
    while (pos != NULL) {
      pos = pos->next;
      mid->next = pre;
      pre = mid;
      mid = pos;
    }

    q->tail = q->head;
    q->head = pre;
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