#pragma once
#include"Cliente.h"
#include<stdio.h>
#include<stdlib.h>
#include"estados.h"
#include"Lista.h"
typedef struct No {
	Cliente* cliente;
	struct No* proximo;
	struct No* anterior;

}No;


void NO_Replace_values(No* destination, No* source) {

	destination->cliente->conta = source->cliente->conta;
	destination->cliente->saldo = source->cliente->saldo;
	strcpy(destination->cliente->nome, source->cliente->nome);

}
int NO_equals(No* n1, No* n2) {

	int igual = 1;
	if (n1->cliente->saldo != n2->cliente->saldo || n1->cliente->conta != n2->cliente->conta || strcmp(n1->cliente->nome, n2->cliente->nome) != 0)
		igual = 0;
	return igual;
}

 int NO_criar_novo_no(No* destino, Cliente* cliente, No* proximo, No* anterior) {
	 destino = NULL;
	 destino =(No*) malloc(sizeof(No));
	 if (destino != NULL) {
		 destino->cliente = cliente;
		 destino->anterior = anterior;
		 destino->proximo = proximo;
		 return sucesso;
	 }
	 return falha;
}

 void NO_copia(No* n1, No* n2) {

	 n1->cliente->conta = n2->cliente->conta;
	 n1->cliente->saldo = n2->cliente->saldo;
	 strcpy(n1->cliente->nome, n2->cliente->nome);
 }

 