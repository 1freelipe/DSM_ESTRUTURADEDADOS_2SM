#include <iostream>
#include <string>

using namespace std;

struct No {
    char simbolo;
    No* proximo;
};

No* topo = NULL;

void push(char caractere) {
    No* novoNo = new No;
    novoNo->simbolo = caractere;
    novoNo->proximo = topo;
    topo = novoNo;
}

void pop() {
    if (topo != NULL) {
        No* temp = topo;
        topo = topo->proximo;
        delete temp;
    }
}

bool pilhaVazia() {
    return topo == NULL;
}

bool verificarParenteses(const string& expressao) {
    for (int i = 0; i < expressao.length(); i++) {
        char caractere = expressao[i];

        if (caractere == '(') {
            push(caractere);
        } else if (caractere == ')') {
            if (pilhaVazia()) {
                return false;
            }
            pop();
        }
    }

    return pilhaVazia();
}

int main() {
    string expressao;

    cout << "Digite uma expressão matemática: ";
    getline(cin, expressao);

    if (verificarParenteses(expressao)) {
        cout << "Os parenteses estao balanceados!" << endl;
    } else {
        cout << "Os parenteses NÃO estão balanceados!" << endl;
    }

    return 0;
}
