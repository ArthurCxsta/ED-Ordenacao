#include "item.h"

class Sort {


public:
    Sort()    {

    }

// //////////////////////////////////////////////////////////////////////////////////////////////////////

    void static selectionSort(Item **VET, int n){

        if(VET == nullptr) return;

        //Atributos
        int i, j, imin;
        Item * T = nullptr;

        //Código da função de Ordenação por Seleção
        for(i=0; i<n-1; i++){
            imin = i;
            for(j=i+1; j<n; j++){
                if(VET[imin]->getChave() > VET[j]->getChave()){
                    imin = j;
                }
            }
            if(i != imin){T = VET[i];
                VET[i] = VET[imin];
                VET[imin] = T;
            }
        }
    }

// //////////////////////////////////////////////////////////////////////////////////////////////////////

    void static insertionSort(Item **VET, int n){

        //Atributos
        long int i,j;
        Item *T = nullptr;

        //Código da função de Ordenação por Inserção
        if(VET != nullptr){
            for(j = 1; j < n; j++){
                T = VET[j];
                i = j-1;
                while(i>=0 && VET[i]->getChave()>T->getChave()){
                    VET[i+1] = VET[i];i--;
                }
                VET[i+1] = T;
            }
        }
    }

// //////////////////////////////////////////////////////////////////////////////////////////////////////

    void static bubbleSort(Item ** A, int n) {
        if (A == nullptr) return;
        int Lsup = n - 1;
        int Bolha;
        Item *Aux = nullptr;
        do {
            Bolha = 0;
            for (int i = 0; i < Lsup; i++) {
                if ((A[i])->getChave() > (A[i+1])->getChave()) {
                    Aux = A[i];
                    A[i] = A[i+1];
                    A[i+1] = Aux;
                    Bolha = i+1;
                }
            }
            Lsup = Bolha;
        } while (Lsup > 0);
    }

// //////////////////////////////////////////////////////////////////////////////////////////////////////

    void static shellSort(Item **VET, int n)
    {
        // Definindo os intervalos de divisão do vetor
        int intervalo = 1;
        while (intervalo < n / 3) {
            intervalo = intervalo * 3 + 1;
        }

        // Aplicando o método de inserção para cada intervalo
        while (intervalo >= 1) {
            for (int i = intervalo; i < n; i++) {
                Item *atual = VET[i];
                int j = i;

                while (j >= intervalo && VET[j - intervalo]->getChave() > atual->getChave()) {
                    VET[j] = VET[j - intervalo];
                    j -= intervalo;
                }

                VET[j] = atual;
            }

            intervalo /= 3;
        }
    }

 // //////////////////////////////////////////////////////////////////////////////////////////////////////

    // Função auxiliar para mesclar dois subarrays em ordem crescente
    void static merge(Item **A, Item **B, int ini, int meio, int fim) {
        int i = ini;
        int j = meio + 1;
        int k = ini;

        // Mesclar as metades em ordem crescente
        while (i <= meio && j <= fim) {
            if ((A[i])->getChave() < (A[j])->getChave()) {
                B[k++] = A[i++];
            } else {
                B[k++] = A[j++];
            }
        }

        // Adicionar quaisquer elementos restantes do primeiro subarray
        while (i <= meio) {
            B[k++] = A[i++];
        }

        // Adicionar quaisquer elementos restantes do segundo subarray
        while (j <= fim) {
            B[k++] = A[j++];
        }

        // Copiar elementos classificados de volta para o array original
        for (int i = ini; i <= fim; i++) {
            A[i] = B[i];
        }
    }

    // Função principal mergesort
    void static mergesort(Item **A, Item **B, int ini, int fim) {
        if (ini < fim) {
            // Encontre o meio do array
            int meio = (ini + fim) / 2;

            // Classifique as duas metades recursivamente
            mergesort(A, B, ini, meio);
            mergesort(A, B, meio + 1, fim);

            // Mesclar as metades classificadas
            merge(A, B, ini, meio, fim);
        }
    }

    // Wrapper function para chamar mergesort
    void static mergesort(Item **A, int tam) {
        if (A) {
            Item **B = new Item*[tam];
            mergesort(A, B, 0, tam - 1);
            delete [] B;
        }
    }

// //////////////////////////////////////////////////////////////////////////////////////////////////////

    void static quickSort(Item ** V, int tam){
        int inicio = 0, fim = tam-1;
        quickSort(V, inicio, fim);
    }


    void static quickSort(Item **vetor, int Esq, int Dir){
        Item *x = nullptr, *aux= nullptr, *t = nullptr; /* Pivô e auxiliares*/
        int i = 0, j = 0; /* Apontadores para o sub-vetor*/
        if(Dir> Esq) { /* ????Subvetoresvazios???? */
            x = vetor[Dir]; /* Define o pivô */
            i = Esq; /* Inicializa apontador da esq*/
            j = Dir-1; /* Inicializa apontador da dir*/
            for (;;) { /* Faz a varredura no vetor */
                aux= vetor[i];/* Percorre a partir da esquerda */
                while(i < Dir&& aux->getChave() < x->getChave()) {
                    i++;
                    aux= vetor[i];
                }
                aux= vetor[j];/* Percorre a partir da direita */
                while(j >= Esq&& aux->getChave() > x->getChave()) {
                    j--;
                    aux= vetor[j];
                }
                if(i >= j) break; /* ????Apontadores se cruzaram???? *//* Faz a troca entre os elementos */
                t = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = t;
                i++;
                j--;
            }/* Coloca o pivô na posição ordenada */
            t = vetor[i];
            vetor[i] = vetor[Dir];
            vetor[Dir] = t;
            quickSort(vetor, Esq, i-1); /* Ordena sub-vetorda esquerda */
            quickSort(vetor, i+1, Dir); /* Ordena sub-vetorda direita */
        }
    }


// //////////////////////////////////////////////////////////////////////////////////////////////////////


};
