#include <iostream>
#include <cstring>
#include <locale>

using namespace std;

struct Node {
    char letra;
    Node* proximo;
};

Node* topo = NULL;

void push(char c) {
    Node* novo = new Node;
    novo->letra = c;
    novo->proximo = topo;
    topo = novo;
}

void inverterEEmpilhar(const char* str) {
    int n = strlen(str);
    for(int i = 0; i < n; i++){
        push(str[i]);
    }
}

void imprimirPilha() {
    Node* atual = topo;
    while (atual != NULL) {
        cout << atual->letra;
        atual = atual->proximo;
    }
    cout << endl;
}

string palindromo() {
    Node* atual = topo;
    string palindromo = "";
    while(atual != NULL) {
        palindromo += atual->letra;
        atual = atual->proximo;
    }

    return palindromo;
}

int main() {
    setlocale(LC_ALL, "portuguese");
    char letra[100];

    cout << "Digite uma palavra: ";
    cin >> letra;

    inverterEEmpilhar(letra);

    cout << "Palavra armazenada na pilha: ";
    imprimirPilha();

    if(palindromo() == letra) {
        cout << "É um palíndromo." << endl;
    } else {
        cout << "Não é um palíndromo." << endl;
    }

    return 0;
}
