#include <iostream>

using namespace std;

struct Node {
    int numero;
    Node* proximo;
};

Node* topo = NULL;

void push(int valor) {
    Node* novo = new Node;
    novo->numero = valor;
    novo->proximo = topo;
    topo = novo;
    cout << "Valor: " << valor << " empilhado." << endl;
}

void index() {
    Node* atual = topo;

    cout << "N�mero em bin�rio: ";
    while(atual != NULL) {
        cout << atual->numero << " ";
        atual = atual->proximo;
    }
}

int main()
{
    int valor = 0;

    cout << "Digite um valor: ";
    cin >> valor;

    while(valor > 0) {
        push(valor % 2);
        valor /= 2;
    }

    index();

    return 0;
}
