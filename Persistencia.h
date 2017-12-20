#pragma once
#include<stdio.h>
#include<string.h>
#include"Cliente.h"
#include"estados.h"
#include"Algoritmos.h"
#include"Lista.h"
#include"No.h"
typedef struct Dados_de_arquivos {

	FILE* arquivo_clientes;
	char nome_de_arquivo[20];
}Dados_de_arquivos;


/**
retorna sucesso caso o arquivo pode ser aberto
retorna falha caso o arquivo nao pode ser aberto
*/
int  PERSISTENCIA_inicia_status_de_arquivo_fechado(Dados_de_arquivos* dados) {

	if (dados->nome_de_arquivo == NULL || strcmp(dados->nome_de_arquivo, "Arquivo_de_clientes.txt") != 0){
		printf("Voce nao deu init no arquivo!");
		return falha;
		}
	//Abre para leitura e escrita no final
	dados->arquivo_clientes = NULL;
	dados->arquivo_clientes = fopen(dados->nome_de_arquivo, "a+");
	if (dados->arquivo_clientes == NULL) {
		printf("O arquivo  Arquivo_de_clientes.txt nao pode ser aberto");
		return falha;
	}
	fclose(dados->arquivo_clientes);
	return sucesso;
}

void PERSISTENCIA_init(Dados_de_arquivos* dados) {
	strcpy(dados->nome_de_arquivo, "Arquivo_de_clientes.txt");
}

int  PERSISTENCIA_valida_arq_cliente(Dados_de_arquivos* dados_de_arquivo) {

	if (dados_de_arquivo->arquivo_clientes == NULL)
		return falha;
	else return sucesso;
}
/**
	retorna sucesso se o cliente foi gravado com sucesso
	retorna falha caso contrario
*/
int PERSISTENCIA_grava_cliente(Cliente* cliente_a_ser_gravado, Dados_de_arquivos* dados_de_arquivo) {
	dados_de_arquivo->arquivo_clientes = fopen("SAIDA.txt", "a+");

	if (PERSISTENCIA_valida_arq_cliente(dados_de_arquivo) == sucesso) {
		fseek(dados_de_arquivo->arquivo_clientes, 0, SEEK_END);
		fputs(cliente_a_ser_gravado->nome,dados_de_arquivo->arquivo_clientes);
		fprintf(dados_de_arquivo->arquivo_clientes, "\n");
		fprintf(dados_de_arquivo->arquivo_clientes,"%d\n", cliente_a_ser_gravado->conta);
		fprintf(dados_de_arquivo->arquivo_clientes,"%.2lf\n", cliente_a_ser_gravado->saldo);
		fclose(dados_de_arquivo->arquivo_clientes);
		return sucesso;
	}
	else {
		printf("Arquivo %s nao pode ser aberto\n", dados_de_arquivo->nome_de_arquivo);
		fclose(dados_de_arquivo->arquivo_clientes);
		return falha;
	}
}


Lista* PERSISTENCIA_carrega(Dados_de_arquivos* dados_de_arquivo) {
	
	
	dados_de_arquivo->arquivo_clientes = fopen("Arquivo_de_clientes.txt", "r");
	Lista* lista_clientes_arquivo = LISTA_inicia();
	Cliente* cliente_corrente = NULL;
	
	fpos_t posicao_anterior=0;
	fpos_t posicao_corrente=0;

	fgetpos(dados_de_arquivo->arquivo_clientes, &posicao_anterior);
	fseek(dados_de_arquivo->arquivo_clientes, 0, SEEK_SET);
	if (PERSISTENCIA_valida_arq_cliente(dados_de_arquivo) == sucesso) {
		while (!feof(dados_de_arquivo->arquivo_clientes)) {
			cliente_corrente =(Cliente*)realloc(cliente_corrente, sizeof(Cliente));
			//leitura dos dados de arquivo
			fgets(cliente_corrente->nome, 200, dados_de_arquivo->arquivo_clientes);
			fscanf(dados_de_arquivo->arquivo_clientes, "%d", &cliente_corrente->conta);
			fscanf(dados_de_arquivo->arquivo_clientes, "%lf", &cliente_corrente->saldo);
			fgetc(dados_de_arquivo->arquivo_clientes);
			fgetpos(dados_de_arquivo->arquivo_clientes, &posicao_corrente);
			if (posicao_corrente > posicao_anterior ) {
				ALGORITMOS_remover_no_fim(cliente_corrente->nome);
				LISTA_insercao(lista_clientes_arquivo,CLIENTE_clone(cliente_corrente));
			}
			posicao_anterior = posicao_corrente;
		}
		free(cliente_corrente);
		cliente_corrente = NULL;
		fclose(dados_de_arquivo->arquivo_clientes);
		return lista_clientes_arquivo;
	}
	else {
		printf("Arquivo %s nao pode ser aberto\n", dados_de_arquivo->nome_de_arquivo);
		fclose(dados_de_arquivo->arquivo_clientes);
		return NULL;
	}
}

void PERSISTENCIA_gravar_lista(Lista* l,Dados_de_arquivos* dados) {

	No* i;
	fclose(dados->arquivo_clientes);
	fopen("SAIDA.txt", "w");
	fclose(dados->arquivo_clientes);

	for (i = l->head; i != NULL; i=i->proximo)
		PERSISTENCIA_grava_cliente(i->cliente, dados);

}






