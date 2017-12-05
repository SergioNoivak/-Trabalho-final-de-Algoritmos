#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"No.h"
#include"Cliente.h"
#include"estados.h"
typedef struct Lista {
	struct No*head;
}Lista;


 Lista* LISTA_inicia() {
	 Lista * minha_lista =(Lista*) malloc(sizeof(Lista));
	 minha_lista->head = NULL;
	 return minha_lista;
}

 /**
	retorna 0 se lista não esta vazia
	retorna 1 se esta vazia
 */
 int LISTA_lista_vazia(Lista* lista) {

	 if (lista == NULL || lista->head == NULL)
		 return sucesso;
	 return falha;
 }


 int LISTA_insercao(Lista *lista, Cliente *cliente) {
	 //Caso que nao foi criada estrutura de lista
	 if (lista == NULL) {
		 return falha;
	 }
	 //Caso lista vazia
	 if (lista->head == NULL) {
		 No *novo =(No*) malloc(sizeof(No));
		 novo->anterior = NULL;
		 novo->proximo = NULL;
		 novo->cliente = cliente;
		 lista->head = novo;
		 return sucesso;
	 }

	 //Caso geral
	 No* i;
	 for (i = lista->head; i->proximo != NULL; i = i->proximo)
		 continue;
	 No *novo = (No*)malloc(sizeof(No));
	 novo->anterior = i;
	 novo->proximo = NULL;
	 novo->cliente = cliente;
	 i->proximo = novo;
	 return sucesso;
 }

 void LISTA_exibe_lista(Lista *lista) {
	 No* i;
	 for (i = lista->head; i != NULL; i = i->proximo) {
		 CLIENTE_exibir(i->cliente);
		 printf("\n");
	 }
 }