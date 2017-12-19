#pragma once
#include<stdio.h>
#include<string.h>
#include"Cliente.h"
#include"estados.h"
#include"Algoritmos.h"
#include<time.h>

typedef struct Cronometro {

	clock_t tempoInicial;
	clock_t tempoFinal;
}Cronometro;

	
void CRONOMETRO_acionar_cronometro(Cronometro* cronometro) {
	cronometro->tempoInicial = clock();
	cronometro->tempoFinal = -1;
}

void CRONOMETRO_pausar_cronometro(Cronometro* cronometro) {
	cronometro->tempoFinal = clock();
}

double CRONOMETRO_get_tempo_milisegundos(Cronometro* cronometro) {
	return (cronometro->tempoFinal -cronometro->tempoInicial) / (CLOCKS_PER_SEC / 1000);
}
void CRONOMETRO_exibe_medicao(Cronometro* cronometro) {
	printf("O CRONOMETRO REGISTROU %.5f MICROSEGUNDOS PARA ESTA OPERACAO\n", CRONOMETRO_get_tempo_milisegundos(cronometro));

}


