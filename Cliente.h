#pragma once
#include<stdio.h>

typedef struct Cliente {
	char nome[200];
	int conta;
	double saldo;
}Cliente;



void CLIENTE_exibir(Cliente *cliente) {
	if (cliente == NULL)
		return;
	printf("NOME:  %s\n", cliente->nome);
	printf("CONTA:  %d\n", cliente->conta);
	printf("SALDO: %.2lf\n", cliente->saldo);
}

Cliente* CLIENTE_clone(Cliente* cliente) {
	if (cliente == NULL)
		return NULL;

	Cliente* cliente_clone = malloc(sizeof(Cliente));
	strcpy(cliente_clone->nome, cliente->nome);
	cliente_clone->conta = cliente->conta;
	cliente_clone->saldo = cliente->saldo;

	return cliente_clone;
}