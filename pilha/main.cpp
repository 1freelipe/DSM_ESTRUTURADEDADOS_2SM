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

void top() {
    cout << "Último valor empilhado: " << topo->numero << endl;
}

void pop() {
    Node* temp = topo;
    topo = topo->proximo;
    cout << "Valor: " << temp->numero << " deletado." << endl;
    delete temp;
}

void isEmpty() {
    Node* atual = topo;
    if(atual == NULL) {
        cout << "A pilha está vazia." << endl;
    } else {
        cout << "A pilha não está vazia. Esses são os números contidos nela: ";
        while(atual != NULL) {
            cout << atual->numero << " ";
            atual = atual->proximo;
        }
        cout << endl;
    }
}

bool isFull() {
    Node* atual = topo;
    int count = 0;

    while(atual != NULL) {
        count++;
        atual = atual->proximo;
    }

    int espaco = 5 - count;

    if(count >= 5) {
        cout << "A pilha está cheia." << endl;
        return true;
    } else {
        cout << "Restam ainda " << espaco << " espaços na pilha." << endl;
        return false;
    }
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    int opc = 0, valor = 0;

    do {
        cout << "Digite um número entre as opções: " << endl;
        cout << "1 - Push" << endl;
        cout << "2 - Top" << endl;
        cout << "3 - Pop" << endl;
        cout << "4 - Verificar se a pilha está vazia" << endl;
        cout << "5 - Verificar se a pilha está cheia" << endl;
        cout << "0 - Sair" << endl;
        cin >> opc;

        switch(opc) {
            case 1:
            if(isFull()) {
                cout << "Não é possível mais alocar novos números." << endl;
                break;
            }

            cout << "Digite um valor para ser empilhado: ";
            cin >> valor;
            push(valor);
            break;

            case 2:
            top();
            break;

            case 3:
            pop();
            break;

            case 4:
            isEmpty();
            break;

            case 5:
            isFull();
        }


    } while(opc != 0);

    return 0;
}
