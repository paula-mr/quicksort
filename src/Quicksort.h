#ifndef QUICKSORT_H
#define QUICKSORT_H

class Quicksort {
    public:
        int* lista;
        int tamanho;
        int tipoPivo;
        int** iteracoes;
        bool exibirVetores;
        int porcentagemInsercao;
        long unsigned int numeroTrocas = 0;
        long unsigned int numeroComparacoes = 0;

        void quicksort();
        void quicksortInsercao();
        void quicksortNaoRecursivo();

        void ordena(int esquerda, int direita);
        void ordenaInsercao(int esquerda, int direita, int quantidadeElementosInsercao);

        void guardarIteracoes();
        int selecionaPivo(int *i, int *j);
        int calculaMediana(int *i, int *j);
};

#endif