#include <iostream>
#include "Orquestrador.h"
#include "Quicksort.h"
#include <stdlib.h>
#include <iostream>
#include <chrono>
#include <string>
#include <stdio.h>

using namespace std::chrono;

void rodarTestes(FILE *pont_arq, int *lista, int tamanho);

int main() {

    int *lista, tamanhoBase = 50000;

    FILE *pont_arq;

    pont_arq = fopen("resultados.txt", "a");

    for (int j = 1; j <= 1; j++) {
        fprintf(pont_arq, "%s%d%s", "Executando teste para vetor de tamanho ", tamanhoBase*j, "\n");
        for (int i = 0; i < 20; i++) {
            fprintf(pont_arq, "%s", "\nVetor aleatorio \n");
            lista = gerarVetor(3, tamanhoBase*j);
            rodarTestes(pont_arq, lista, tamanhoBase*j);

            fprintf(pont_arq, "%s", "\nVetor crescente \n");
            lista = gerarVetor(1, tamanhoBase*j);
            rodarTestes(pont_arq, lista, tamanhoBase*j);

            fprintf(pont_arq, "%s", "\nVetor decrescente \n");
            lista = gerarVetor(2, tamanhoBase*j);
            rodarTestes(pont_arq, lista, tamanhoBase*j);
        }
    }

    fclose(pont_arq);

    return 0;
}

void rodarTestes(FILE *pont_arq, int *lista, int tamanho) {
    unsigned long int numeroComparacoes = 0, numeroTrocas = 0;

    fprintf(pont_arq, "%s", "Quicksort nao recursivo \n");
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    quicksortNaoRecursivo(lista, tamanho, &numeroComparacoes, &numeroTrocas);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double, std::micro> elapsed_time = duration_cast<duration<double>>(t2 - t1);
    fprintf(pont_arq, "%s%d%s%d%s%s%s", "Comparacoes ", numeroComparacoes, " Trocas ", numeroTrocas, " Tempo ", elapsed_time.count(), "\n\n");
    numeroComparacoes = 0; numeroTrocas = 0;


    fprintf(pont_arq, "%s", "Quicksort recursivo pivo central\n");
    t1 = high_resolution_clock::now();
    quicksort(lista, tamanho, 1, &numeroComparacoes, &numeroTrocas);
    t2 = high_resolution_clock::now();
    elapsed_time = duration_cast<duration<double>>(t2 - t1);
    fprintf(pont_arq, "%s%d%s%d%s%s%s", "Comparacoes ", numeroComparacoes, " Trocas ", numeroTrocas, " Tempo ", elapsed_time.count(), "\n\n");
    numeroComparacoes = 0; numeroTrocas = 0;

    fprintf(pont_arq, "%s", "Quicksort recursivo pivo mediana\n");
    t1 = high_resolution_clock::now();
    quicksort(lista, tamanho, 2, &numeroComparacoes, &numeroTrocas);
    t2 = high_resolution_clock::now();
    elapsed_time = duration_cast<duration<double>>(t2 - t1);
    fprintf(pont_arq, "%s%d%s%d%s%s%s", "Comparacoes ", numeroComparacoes, " Trocas ", numeroTrocas, " Tempo ", elapsed_time.count(), "\n\n");
    numeroComparacoes = 0; numeroTrocas = 0;

    fprintf(pont_arq, "%s", "Quicksort recursivo pivo primeiro elemento\n");
    t1 = high_resolution_clock::now();
    quicksort(lista, tamanho, 3, &numeroComparacoes, &numeroTrocas);
    t2 = high_resolution_clock::now();
    elapsed_time = duration_cast<duration<double>>(t2 - t1);
    fprintf(pont_arq, "%s%d%s%d%s%s%s", "Comparacoes ", numeroComparacoes, " Trocas ", numeroTrocas, " Tempo ", elapsed_time.count(), "\n\n");
    numeroComparacoes = 0; numeroTrocas = 0;

    fprintf(pont_arq, "%s", "Quicksort com insercao 1%\n");
    t1 = high_resolution_clock::now();
    quicksortInsercao(lista, tamanho, 1, &numeroComparacoes, &numeroTrocas);
    t2 = high_resolution_clock::now();
    elapsed_time = duration_cast<duration<double>>(t2 - t1);
    fprintf(pont_arq, "%s%d%s%d%s%s%s", "Comparacoes ", numeroComparacoes, " Trocas ", numeroTrocas, " Tempo ", elapsed_time.count(), "\n\n");
    numeroComparacoes = 0; numeroTrocas = 0;

    fprintf(pont_arq, "%s", "Quicksort com insercao 5%\n");
    t1 = high_resolution_clock::now();
    quicksortInsercao(lista, tamanho, 1, &numeroComparacoes, &numeroTrocas);
    t2 = high_resolution_clock::now();
    elapsed_time = duration_cast<duration<double>>(t2 - t1);
    fprintf(pont_arq, "%s%d%s%d%s%s%s", "Comparacoes ", numeroComparacoes, " Trocas ", numeroTrocas, " Tempo ", elapsed_time.count(), "\n\n");
    numeroComparacoes = 0; numeroTrocas = 0;

    fprintf(pont_arq, "%s", "Quicksort com insercao 10%\n");
    t1 = high_resolution_clock::now();
    quicksortInsercao(lista, tamanho, 1, &numeroComparacoes, &numeroTrocas);
    t2 = high_resolution_clock::now();
    elapsed_time = duration_cast<duration<double>>(t2 - t1);
    fprintf(pont_arq, "%s%d%s%d%s%s%s", "Comparacoes ", numeroComparacoes, " Trocas ", numeroTrocas, " Tempo ", elapsed_time.count(), "\n\n");
    numeroComparacoes = 0; numeroTrocas = 0;
}
