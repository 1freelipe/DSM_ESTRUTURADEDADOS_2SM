#include <iostream>
#include <locale>

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

    while(atual != NULL) {
        cout << atual->numero << " ";
        atual = atual->proximo;
    }

    cout << " || Fim da pilha." << endl;
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    int tamanho = 20, vetor[tamanho];

    for(int i=0; i < 5; i++) {
        cout << "Digite o " << i+1 << "º número" << endl;
        cin >> vetor[i];
        push(vetor[i]);
    }

    index();

    return 0;
}
