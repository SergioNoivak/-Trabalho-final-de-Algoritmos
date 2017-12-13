#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include"Lista.h"
//#include"Cliente.h"
//#include"No.h"
//#include"Persistencia.h"


typedef struct node {

	int data;
	struct node* next;
	struct node* prev;
}node;

void cria_lista(node* head) {
	head = NULL;
}
node* insercao(node* head, node* no) {
	//Caso lista vazia
	if (head == NULL) {
		no->prev = NULL;
		no->next = NULL;
		head = no;
		return head;
	}
	

	//Caso geral
	node* i;
	for (i = head; i->next != NULL; i = i->next)
		continue;
	no->prev = i;
	no->next = NULL;
	i->next = no;
	return head;

}

void exibe_lista(node* head) {
	node* i = head;
	i->prev = NULL;
	for (i = head; i != NULL; i = i->next) {

		 
		printf(" %d ",i->data);
	

			}
}

void exibe_lista_fim(node* head) {
	node* i;
	for (i = head; i->next!= NULL; i = i->next) {
		continue;
	}

	while (i != NULL) {

		printf(" %d ", i->data);
	
		i = i->prev;
	}

}



void swap_data(struct node* node1, struct node* node2) {
	int temp_data = node1->data;
	node1->data = node2->data;
	node2->data = temp_data;
}


struct node* swap(struct node* node1, struct node* node2) {
	struct node* temp;
	temp = node1->next;
	node1->next = node2->next;
	node2->next = temp;
	if (node1->next != NULL)
		node1->next->prev = node1;
	if (node2->next != NULL)
		node2->next->prev = node2;
	temp = node1->prev;
	node1->prev = node2->prev;
	node2->prev = temp;
	if (node1->prev != NULL)
		node1->prev->next = node1;
	if (node2->prev == NULL)
		return node2;
	node2->prev->next = node2;
	return node1;
}
int main() {

	node* head=NULL;
	cria_lista(head);
	node* n1 = malloc(sizeof(node));
	n1->data = 99;
	node* n2 = malloc(sizeof(node));
	n2->data = 9;
	node* n3 = malloc(sizeof(node));
	n3->data = 1;
	node* n4 = malloc(sizeof(node));
	n4->data = 998;
	node* n5 = malloc(sizeof(node));
	n5->data = 5;
	node* n6 = malloc(sizeof(node));
	n6->data = 198;

	


	head = insercao(head,n1);
	head = insercao(head,n2);
	head = insercao(head, n3);
	head = insercao(head, n4);
	head = insercao(head,n5);
	head = insercao(head, n6);

	exibe_lista(head);
	printf("\n");
	//exibe_lista_fim(head);
	swap(n5, n6);
	printf("\n");
	exibe_lista(head);



	system("PAUSE");

}





//	 ///DADOS VAZIO ok
//
//
///*
//	
//	Dados_de_arquivos* dados = malloc(sizeof(Dados_de_arquivos));
//	DADOS_DE_ARQUIVO_init(dados);
//	
//	DADOS_DE_ARQUIVO_inicia_status_de_arquivo_fechado(dados);
//	
//	Lista* l =DADOS_DE_ARQUIVO_carrega(dados);
//	LISTA_exibe_lista(l);
//*/
//	system("Pause");
//}
//
//
//
///*Cliente* c1 =(Cliente*) malloc(sizeof(Cliente));
//Cliente* c2 = (Cliente*)malloc(sizeof(Cliente));
//Cliente* c3 = (Cliente*)malloc(sizeof(Cliente));
//Cliente* c4 = (Cliente*)malloc(sizeof(Cliente));
//
//strcpy(c1->nome, "Rei da identacao");
//c1->conta = 11;
//c1->saldo = 10.10;
//
//strcpy(c2->nome, "Rei da usabilidade");
//c2->conta = 200;
//c2->saldo = 22.22;
//
//strcpy(c3->nome, "Rei do Pagode");
//c3->conta = 33;
//c3->saldo = 33.33;
//
//strcpy(c4->nome, "Rei da Engenharia");
//c4->conta = 44;
//c4->saldo = 44.44;
//
//*/
//
///*DADOS_DE_ARQUIVO_grava_cliente(c1, dados);
//DADOS_DE_ARQUIVO_grava_cliente(c2, dados);
//DADOS_DE_ARQUIVO_grava_cliente(c3, dados);
//DADOS_DE_ARQUIVO_grava_cliente(c4, dados);
//*/