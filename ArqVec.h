#include <fstream>
#include <vector>
#include <iostream>
#include <stdlib.h>
using namespace std;

int validaInt() {
    string info;
    int x;
    unsigned int i;
    bool validada = true;
    do {
        cout << "Numero invalido, digite novamente." << std::endl;
        getline(std::cin, info);
        if (info == "") {
            validada = false;
        } else if (!isdigit(info[0])) {
            validada = false;
        } else {
            for (i = 1; i < info.length(); i++) {
                if (!isdigit(info[i])) {
                    validada = false;
                    break;
                }
            }
        }
    } while (!validada);
    x = atoi(info.c_str());
    return x;
}


vector<int> lerArquivo() {
    fstream arq;
    vector<int> vet;
    do {
        cout << "Digite o nome do seu arquivo" << std::endl;
        string nome;
        getline(std::cin, nome);
        arq.open(nome);
    } while (!arq.is_open());

    cout << "digite o numero de dados que você quer ler: " << std::endl
              << "1. 100" << std::endl
              << "2. 500" << std::endl
              << "3. 1000" << std::endl;
    int op = validaInt();
    
    int n;
    switch (op) {
        case 1:
            n = 100;
            break;
        case 2:
            n = 500;
            break;
        case 3:
            n = 1000;
            break;
        default:
            break;
    }
    string valor;
    for (int i = 0; i < n; i++) {
        getline(arq, valor);
        int num = atoi(valor.c_str());
        vet.push_back(num);
    }
    arq.close();
    return vet;
}
