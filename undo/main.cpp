#include <iostream>
#include <locale>

using namespace std;

struct Node {
    string palavra;
    Node* proximo;
};

Node* topo = NULL;

void push(string letras) {
    Node* novo = new Node;
    novo->palavra = letras;
    novo->proximo = topo;
    topo = novo;
    cout << "Palavra: " << letras << " armazenada." << endl;
}

void index() {
    Node* atual = topo;

    cout << "Palavras armazenadas: ";
    while(atual != NULL) {
        cout << atual->palavra << " ";
        atual = atual->proximo;
    }
    cout << endl;
}

void undo() {
    Node* temp = topo;
    topo = topo->proximo;
    cout << "Palavra: " << temp->palavra << " deletada." << endl;
    delete temp;
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    string letras;
    int opc = 0;

    do {
        cout << "Digite uma opção" << endl;
        cout << "1 - Digitar uma palavra" << endl;
        cout << "2 - Apagar a última palavra" << endl;
        cout << "0 - Sair" << endl;
        cin >> opc;

        switch(opc) {
        case 1:
            cout << "Digite uma palavra: ";
            cin >> letras;
            push(letras);
            break;

        case 2:
            undo();
            index();
            break;
        }


    }while(opc != 0);



    return 0;
}
