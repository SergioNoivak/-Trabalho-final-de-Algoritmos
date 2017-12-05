
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Lista.h"
#include"Cliente.h"
#include"No.h"

int main() {

	 Cliente* c1 = malloc(sizeof(Cliente));
	 Cliente* c2 = malloc(sizeof(Cliente));
	 c1->saldo = 12.1;
	 c2->saldo = 33.3;
	 Lista* lista = LISTA_inicia();
     LISTA_insercao(lista, c1);   
     LISTA_insercao(lista, c2);
    if(!LISTA_lista_vazia(lista))
	 LISTA_exibe_lista(lista);
    
    



	system("Pause");
}