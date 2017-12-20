#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"Lista.h"
#include"Cliente.h"
#include"No.h"
#include"Persistencia.h"
#include"Cronometro.h"
enum resultados_do_menu {
	
	exibir_lista_desordenada=1,
	ORDENAR_POR_SELECTION_sem_salvar_no_arquivo = 2,
	ORDENAR_POR_INSERTION_sem_salvar_no_arquivo = 3,
	ORDENAR_POR_SELECTION_salvar= 4,
	ORDENAR_POR_INSERTION_salvar = 5,
	sair = 6
};




int menu_() {

	printf(" =========  MENU PRINCIPAL     =============    \n\n");
	printf("          1.exibir lista atual                  \n");
	printf("          2.ORDENAR POR SELECTION (sem salvar)  \n");
	printf("          3.ORDENAR POR INSERTION (sem salvar)  \n");
	printf("          4.ORDENAR POR SELECTION (salvar)      \n");
	printf("          5.ORDENAR POR INSERTION (salvar)      \n");
	printf("          6.sair                                \n");
	
	int resultado;
	scanf("%d", &resultado);
	fflush(stdin);
	getchar();
	system("cls");
	return resultado;
}


void ALGORITMOS_selection(Lista* l)
{
	No *h = l->head, *i, *j, *proximo_i;
	No *min;
	for (i = h; i != NULL && i->proximo != NULL; i = i->proximo)
	{
		min = i;
		for (j = i->proximo; j != NULL; j = j->proximo)
		{	
			if (j->cliente->saldo < min->cliente->saldo)
				min = j;
		}
		if (min != i)
		{
			static Cliente temp;
			temp.conta = min->cliente->conta;
			temp.saldo = min->cliente->saldo;
			strcpy(temp.nome, min->cliente->nome);
			
			
			min->cliente->conta = i->cliente->conta;
			min->cliente->saldo = i->cliente->saldo;
			strcpy(min->cliente->nome, i->cliente->nome);
			
			
			i->cliente->conta = temp.conta;
			i->cliente->saldo = temp.saldo;
			strcpy(i->cliente->nome , temp.nome);
		}
	}
	l->head = h;
}


int main() {

		Cronometro* cronometro = malloc(sizeof(Cronometro));
		Dados_de_arquivos* dados = malloc(sizeof(Dados_de_arquivos));
		PERSISTENCIA_init(dados);
		PERSISTENCIA_inicia_status_de_arquivo_fechado(dados);
		Lista* l = PERSISTENCIA_carrega(dados);

		int controle_menu = -1;
		while (controle_menu != sair) {

			controle_menu = menu_();
			if (controle_menu == sair)
				break;
			system("cls");
			switch (controle_menu)
			{
				case exibir_lista_desordenada:
					cronometro->tempoFinal = 0;
					cronometro->tempoInicial = 0;
					CRONOMETRO_acionar_cronometro(cronometro);
					LISTA_exibe_lista(l);
					CRONOMETRO_pausar_cronometro(cronometro);
				    printf("\n");
					CRONOMETRO_exibe_medicao(cronometro);
					printf("\n");
					system("PAUSE");
				    system("cls");
					
					break;

				case ORDENAR_POR_SELECTION_sem_salvar_no_arquivo:
					cronometro->tempoFinal = 0;
					cronometro->tempoInicial = 0;
					CRONOMETRO_acionar_cronometro(cronometro);
					ALGORITMOS_selection(l);
					CRONOMETRO_pausar_cronometro(cronometro);
					printf("\n");
					LISTA_exibe_lista(l);
					printf("\n");
					CRONOMETRO_exibe_medicao(cronometro);
					printf("\n");
					system("PAUSE");
					system("cls");
					break;
				
				case ORDENAR_POR_INSERTION_sem_salvar_no_arquivo:
					cronometro->tempoFinal = 0;
					cronometro->tempoInicial = 0;
					CRONOMETRO_acionar_cronometro(cronometro);
					l->head = ALGORITMOS_insertion_sort(l->head);
					CRONOMETRO_pausar_cronometro(cronometro);
					LISTA_exibe_lista(l);
					printf("\n");
					CRONOMETRO_exibe_medicao(cronometro);
					printf("\n");
					system("PAUSE");
					system("cls");
					break;

				case ORDENAR_POR_SELECTION_salvar:
					cronometro->tempoFinal = 0;
					cronometro->tempoInicial = 0;
					CRONOMETRO_acionar_cronometro(cronometro);
					ALGORITMOS_selection(l);
					CRONOMETRO_pausar_cronometro(cronometro);
					printf("\n");
					LISTA_exibe_lista(l);
					printf("\n");
					CRONOMETRO_exibe_medicao(cronometro);
					printf("\n");
					PERSISTENCIA_gravar_lista(l, dados);
					system("PAUSE");
					system("cls"); 
					break;


				case ORDENAR_POR_INSERTION_salvar:
					system("cls");
					cronometro->tempoFinal = 0;
					cronometro->tempoInicial = 0;
					CRONOMETRO_acionar_cronometro(cronometro);
					l->head = ALGORITMOS_insertion_sort(l->head);
					CRONOMETRO_pausar_cronometro(cronometro);
					LISTA_exibe_lista(l);
					printf("\n");
					CRONOMETRO_exibe_medicao(cronometro);
					printf("\n");
					PERSISTENCIA_gravar_lista(l, dados);
					system("PAUSE");
					system("cls");
					break;

				case sair:
					system("cls");
					printf("SAINDO DO PROGRAMA");
					system("exit");
					break;
			default:
				break;
			}

		}


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