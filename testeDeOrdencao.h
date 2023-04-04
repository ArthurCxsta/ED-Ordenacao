#include <iostream>
#include "sort.h"
//#include "item.h"
#include <cstdlib> // para as funções rand() e srand()
#include <ctime> // para as funções time() e clock()

using namespace std;
class TestaOrdenacao{


public:
    TestaOrdenacao(){}

    int Teste()
    {
        int metodo = 0, tamanho = 0;


        srand(time(nullptr)); // inicializa o gerador de números aleatórios
        cout << "Insira o tamanho do array: ";
        cin >> tamanho;
        cout << endl;

        // aloca memória para o array de ponteiros para itens
        Item** arr = new Item*[tamanho];

        // inicializa cada item com um número aleatório entre 0 e 500.000
        for (int i = 0; i < tamanho; i++) {
            arr[i] = new Item();
            arr[i]->setChave(rand() % 500001);
        }

        bool continuar = true;

        while (continuar) {

            cout << "Insira qual metodo deseja utilizar:" << endl;
            cout << "1- Ordenacao por Selecao" << endl;
            cout << "2- Ordenacao por Insercao" << endl;
            cout << "3- Ordenacao por Bubblesort" << endl;
            cout << "4- Ordenacao por Shellsort" << endl;
            cout << "5- Ordenacao por Mergesort" << endl;
            cout << "6- Ordenacao por Quicksort" << endl << endl;

            cout << "Metodo numero: ";
            cin >> metodo;
            cout<<endl;

            clock_t start = clock(); // marca o tempo de início da ordenação

            if(metodo == 0 || metodo > 6){
                cout << "Metodo invalido!!!" << endl << endl;
                continuar = false;
                break;
            }

            // realiza a ordenação escolhida pelo usuário
            switch(metodo) {

                case 1: {
                    clock_t start = clock();
                    Sort::selectionSort(arr, tamanho);
                    break;
                }
                case 2: {
                    Sort::insertionSort(arr, tamanho);
                    break;
                }
                case 3: {
                    Sort::bubbleSort(arr, tamanho);
                    break;
                }
                case 4: {
                    Sort::shellSort(arr, tamanho);
                    break;
                }
                case 5: {
                    Sort::mergesort(arr, tamanho);
                    break;
                }
                case 6: {
                    Sort::quickSort(arr,tamanho);

                }
            }

            // exibe o array ordenado
            cout << "Array ordenado: ";
            for (int i = 0; i < tamanho; i++) {
                cout << arr[i]->getChave() << " ";
            }
            cout << endl << endl;

            clock_t end = clock(); // marca o tempo de fim da ordenação

            double elapsed_time = double(end - start) / CLOCKS_PER_SEC; // calcula o tempo decorrido em segundos

            cout << "Tempo decorrido: " << elapsed_time << " segundos" << endl << endl;

            cout << "Deseja ordenar novamente? (s/n): ";
            char resposta;
            cin >> resposta;
            continuar = (resposta == 's' || resposta == 'S');
            cout<<endl;

        }

        // desaloca os itens e o array de ponteiros
        for (int i = 0; i < tamanho; i++) {
            delete arr[i];
        }
        delete[] arr;

        return 0;
    }

};


