#include <iostream>
using namespace std;

struct No {
    int valor;
    No* esquerda;
    No* direita;
};

// Cria um novo nó
No* createNode(int val) {
    No* novo = new No;
    novo->valor = val;
    novo->esquerda = nullptr;
    novo->direita = nullptr;
    return novo;
}

// Inserir na árvore
No* insertNode(No* raiz, int val) {
    if (raiz == nullptr) {
        return createNode(val);
    }

    if (val < raiz->valor) {
        raiz->esquerda = insertNode(raiz->esquerda, val);
    } else if (val > raiz->valor) {
        raiz->direita = insertNode(raiz->direita, val);
    }

    return raiz;
}

// Buscar valor na árvore
No* searchNode(No* raiz, int val) {
    if (raiz == nullptr || raiz->valor == val)
        return raiz;

    if (val < raiz->valor)
        return searchNode(raiz->esquerda, val);
    else
        return searchNode(raiz->direita, val);
}

// Exibir em ordem
void showInOrder(No* raiz) {
    if (raiz != nullptr) {
        showInOrder(raiz->esquerda);
        cout << raiz->valor << " ";
        showInOrder(raiz->direita);
    }
}

// Exibir pré-ordem
void showPreOrder(No* raiz) {
    if (raiz != nullptr) {
        cout << raiz->valor << " ";
        showPreOrder(raiz->esquerda);
        showPreOrder(raiz->direita);
    }
}

// Exibir pós-ordem
void showPostOrder(No* raiz) {
    if (raiz != nullptr) {
        showPostOrder(raiz->esquerda);
        showPostOrder(raiz->direita);
        cout << raiz->valor << " ";
    }
}

// Menor valor
No* findMin(No* raiz) {
    while (raiz && raiz->esquerda != nullptr)
        raiz = raiz->esquerda;
    return raiz;
}

// Maior valor
No* findMax(No* raiz) {
    while (raiz && raiz->direita != nullptr)
        raiz = raiz->direita;
    return raiz;
}

// Remover valor
No* deleteNode(No* raiz, int val) {
    if (raiz == nullptr)
        return nullptr;

    if (val < raiz->valor)
        raiz->esquerda = deleteNode(raiz->esquerda, val);
    else if (val > raiz->valor)
        raiz->direita = deleteNode(raiz->direita, val);
    else {
        if (raiz->esquerda == nullptr && raiz->direita == nullptr) {
            delete raiz;
            return nullptr;
        }
        else if (raiz->esquerda == nullptr) {
            No* temp = raiz->direita;
            delete raiz;
            return temp;
        }
        else if (raiz->direita == nullptr) {
            No* temp = raiz->esquerda;
            delete raiz;
            return temp;
        }

        No* temp = findMin(raiz->direita);
        raiz->valor = temp->valor;
        raiz->direita = deleteNode(raiz->direita, temp->valor);
    }

    return raiz;
}

// Contar nós
int countNodes(No* raiz) {
    if (raiz == nullptr) return 0;
    return 1 + countNodes(raiz->esquerda) + countNodes(raiz->direita);
}

// Altura da árvore
int treeHeight(No* raiz) {
    if (raiz == nullptr) return 0;

    int alturaEsq = treeHeight(raiz->esquerda);
    int alturaDir = treeHeight(raiz->direita);

    return 1 + (alturaEsq > alturaDir ? alturaEsq : alturaDir);
}

int main() {
    No* raiz = nullptr;
    int opcao, valor;

    do {
        cout << "\n===== MENU ARVORE BINARIA DE BUSCA =====\n";
        cout << "1 - Inserir produto\n";
        cout << "2 - Remover produto\n";
        cout << "3 - Buscar produto\n";
        cout << "4 - Exibir em-ordem\n";
        cout << "5 - Exibir pre-ordem\n";
        cout << "6 - Exibir pos-ordem\n";
        cout << "7 - Mostrar total de produtos\n";
        cout << "8 - Mostrar menor valor\n";
        cout << "9 - Mostrar maior valor\n";
        cout << "10 - Mostrar altura da arvore\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        switch(opcao) {
            case 1:
                cout << "Digite o codigo: ";
                cin >> valor;
                raiz = insertNode(raiz, valor);
                break;

            case 2:
                cout << "Digite o codigo para remover: ";
                cin >> valor;
                raiz = deleteNode(raiz, valor);
                break;

            case 3:
                cout << "Digite o codigo para buscar: ";
                cin >> valor;
                if (searchNode(raiz, valor))
                    cout << "Produto encontrado!\n";
                else
                    cout << "Nao encontrado.\n";
                break;

            case 4:
                cout << "Em-ordem: ";
                showInOrder(raiz);
                cout << endl;
                break;

            case 5:
                cout << "Pre-ordem: ";
                showPreOrder(raiz);
                cout << endl;
                break;

            case 6:
                cout << "Pos-ordem: ";
                showPostOrder(raiz);
                cout << endl;
                break;

            case 7:
                cout << "Total de produtos: " << countNodes(raiz) << endl;
                break;

            case 8:
                if (raiz)
                    cout << "Menor valor: " << findMin(raiz)->valor << endl;
                else
                    cout << "Arvore vazia\n";
                break;

            case 9:
                if (raiz)
                    cout << "Maior valor: " << findMax(raiz)->valor << endl;
                else
                    cout << "Arvore vazia\n";
                break;

            case 10:
                cout << "Altura: " << treeHeight(raiz) << endl;
                break;
        }

    } while(opcao != 0);

    return 0;
}
