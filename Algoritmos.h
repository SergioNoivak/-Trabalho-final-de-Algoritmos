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

Lista* ALGORITMOS_selection_sort(Lista* lista) {

	if (lista->head->proximo == NULL)
		return lista;
	No* i = lista->head;
	while (i->proximo != NULL) {
		No* min = i->anterior;
		No* j = i->proximo;
		while (j!=NULL) {
			if (j->cliente->saldo < min->cliente->saldo)
				min = j;
		}
		if (i != min) {
			No* swap = i;
			i = min;
			min = swap;
		}
	}

}