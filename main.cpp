#include <iostream>
#include "ordenacoes.h"
#include "ArqVec.h"
using namespace std;


int main(){
    vector<int> vet = lerArquivo();
    ofstream relatorio("relatorio.txt", ios::app);
    int comparacoes = 0;
    int movimentacoes = 0;
    cout << "digite qual metodo de ordenção você quer usar: " << endl;
    cout << "1. Shell Sort" << endl;
    cout << "2. Merge Sort" << endl;
    cout << "3. Heap Sort" << endl;
    int op = validaInt();
    do{
        switch(op){
            case 1: 
                ShellSort(vet,vet.size(),comparacoes,movimentacoes);
                relatorio << "SHELL SORT: " << endl << "Comparações: " << comparacoes << endl << "Movimentações: " << movimentacoes << endl;
                break;
            case 2:
                mergeSort(vet,0,vet.size(),comparacoes,movimentacoes);
                relatorio << "MERGE SORT: " << endl << "Comparações: " << comparacoes << endl << "Movimentações: " << movimentacoes << endl;
                break;
            case 3:
                heapSort(vet,comparacoes,movimentacoes);
                relatorio << "HEAP SORT: " << endl << "Comparações: " << comparacoes << endl <<  "Movimentações: " << movimentacoes << endl;
                break;
            default:
                cout << "opção invalida digite novamente";
                break;
        }
    }while(op > 3 and op < 0);

    relatorio.close();

}



