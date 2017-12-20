#pragma once

#include<stdio.h>
#include<string.h>
#include"Cliente.h"
#include"estados.h"
#include"Lista.h"
#include"No.h"

char* ALGORITMOS_remover_no_fim(char* string) {
	string[strlen(string) - 1] = '\0';	
}

No* ALGORITMOS_swap(No* no1, No* no2) {
	Cliente* aux = (Cliente*)malloc(sizeof(Cliente));
	aux->conta = no1->cliente->conta;
	aux->saldo = no1->cliente->saldo;
	strcpy(aux->nome, no1->cliente->nome);

	no1->cliente->conta = no2->cliente->conta;
	no1->cliente->saldo = no2->cliente->saldo;
	strcpy(no1->cliente->nome, no2->cliente->nome);

	no2->cliente->conta = aux->conta;
	no2->cliente->saldo = aux->saldo;
	strcpy(no2->cliente->nome, aux->nome);
}


void ALGORITMOS_selection_sort(Lista* lista) {
	No* i = NULL, *j = NULL, *min = NULL, *aux = NULL;

	if (lista->head->proximo == NULL) {
		printf("l->head da lista eh NULL");
		return;
	}

	for (i = lista->head; i != NULL; i = i->proximo) {
		min = i;
		for (j = i->proximo; j != NULL; j = j->proximo)
			if (j->cliente->saldo < min->cliente->saldo)
				min = j;

		ALGORITMOS_swap(i, min,lista);

	}

	printf("\n ============resposta=======\n");
	LISTA_exibe_lista(lista);
	printf("\n ============resposta=======\n");

}


No* funcao_auxiliar_insertion(No* inicio, No* posicao, No* novo) {
	if (inicio == posicao) {
		novo->proximo = inicio;
		return novo;
	}

	No* pom = inicio;
	while (pom->proximo != posicao) {
		pom = pom->proximo;
	}
	novo->proximo = pom->proximo;
	pom->proximo = novo;
	return inicio;
}


No* ALGORITMOS_insertion_sort(No* begin)
{

	No* eleito = begin;
	No* j = begin;
	No* p1;
	No* p2;

	while (j->proximo != NULL) {
		p1 = eleito;
		while (j->proximo != NULL && p1 != j->proximo && p1->cliente->saldo < j->proximo->cliente->saldo)
			p1 = p1->proximo;

		if (j->proximo != p1) {
			p2 = j->proximo;
			j->proximo = j->proximo->proximo;
			eleito = funcao_auxiliar_insertion(eleito, p1, p2);

		}
		else {

			j = j->proximo;
		}

	}
	return eleito;
}
