#include <iostream>

using namespace std;

const int TAMANHO = 20;
int vetor[TAMANHO];
int topo1 = -1;
int topo2 = TAMANHO;


bool pushPilha1(int valor) {
    if (topo1 + 1 == topo2) {
        cout << "Pilha 1 cheia! Não é possível empilhar." << endl;
        return false;
    }
    topo1++;
    vetor[topo1] = valor;
    return true;
}


bool pushPilha2(int valor) {
    if (topo2 - 1 == topo1) {
        cout << "Pilha 2 cheia! Não é possível empilhar." << endl;
        return false;
    }
    topo2--;
    vetor[topo2] = valor;
    return true;
}


int popPilha1() {
    if (topo1 == -1) {
        cout << "Pilha 1 vazia!" << endl;
        return -1;
    }
    int valor = vetor[topo1];
    topo1--;
    return valor;
}


int popPilha2() {
    if (topo2 == TAMANHO) {
        cout << "Pilha 2 vazia!" << endl;
        return -1;
    }
    int valor = vetor[topo2];
    topo2++;
    return valor;
}


void mostrarPilhas() {
    cout << "Pilha 1: ";
    for (int i = 0; i <= topo1; i++) {
        cout << vetor[i] << " ";
    }
    cout << endl;

    cout << "Pilha 2: ";
    for (int i = TAMANHO - 1; i >= topo2; i--) {
        cout << vetor[i] << " ";
    }
    cout << endl;
}

int main() {
    int opcao, valor;

    do {
        cout << "\nMenu de Opções:" << endl;
        cout << "1 - Push Pilha 1" << endl;
        cout << "2 - Pop Pilha 1" << endl;
        cout << "3 - Push Pilha 2" << endl;
        cout << "4 - Pop Pilha 2" << endl;
        cout << "5 - Mostrar Pilhas" << endl;
        cout << "0 - Sair" << endl;
        cout << "Opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite o valor para a Pilha 1: ";
                cin >> valor;
                pushPilha1(valor);
                break;
            case 2:
                cout << "Valor removido da Pilha 1: " << popPilha1() << endl;
                break;
            case 3:
                cout << "Digite o valor para a Pilha 2: ";
                cin >> valor;
                pushPilha2(valor);
                break;
            case 4:
                cout << "Valor removido da Pilha 2: " << popPilha2() << endl;
                break;
            case 5:
                mostrarPilhas();
                break;
            case 0:
                cout << "Encerrando o programa." << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
        }
    } while (opcao != 0);

    return 0;
}
