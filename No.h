#pragma once
#include"Cliente.h"
#include<stdio.h>
#include<stdlib.h>
#include"estados.h"
typedef struct No {
	Cliente* cliente;
	struct No* proximo;
	struct No* anterior;

}No;

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

