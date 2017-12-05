#pragma once
#include<stdio.h>

typedef struct Cliente {
	char nome[200];
	int conta;
	float saldo;
}Cliente;

void CLIENTE_exibir(Cliente *cliente) {
	if (cliente == NULL)
		return;
	printf("NOME:  %s\n", cliente->nome);
	printf("CONTA:  %d\n", cliente->conta);
	printf("SALDO: %.2f\n", cliente->saldo);
}

