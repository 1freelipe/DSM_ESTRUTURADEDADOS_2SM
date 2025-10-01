#include <iostream>
#include <limits>
#include <sstream>
#include <locale>

using namespace std;

struct RPN {
    int numero;
    RPN* proximo;
};

RPN* topo = NULL;

void push(int valor){
    RPN* novo = new RPN;
    novo->numero = valor;
    novo->proximo = topo;
    topo = novo;
    cout << "Valor " << valor << " empilhado" << endl;
}

int countSize() {
    RPN* atual = topo;
    int count = 0;

    while(atual != NULL) {
        count++;
        atual = atual->proximo;
    }

    return count;
}

void index() {
    RPN* atual = topo;
    while(atual != NULL) {
        cout << atual->numero << " ";
        atual = atual->proximo;
    }
        cout << endl;
}

bool isEmpty() {
    if(topo == NULL) return true;

    return false;
}

void pop() {
    RPN* temp = topo;
    topo = topo->proximo;
    cout << "Valor: " << temp->numero << " deletado" << endl;
    delete temp;
}

void plusOP() {
    RPN* temp = topo;
    RPN* op2 = topo->proximo;
    int result = op2->numero + temp->numero;
    cout << "Operação: " << op2->numero << " " << temp->numero << " + " << endl;
    cout << "Resultado: " << result << endl;
    op2->numero = result;
    topo = op2;
    delete temp;
}

void lessOP() {
    RPN* temp = topo;
    RPN* op2 = topo->proximo;
    int result = op2->numero - temp->numero;
    cout << "Operação: " << op2->numero << " " << temp->numero << " - " << endl;
    cout << "Resultado: " << result << endl;
    op2->numero = result;
    topo = op2;
    delete temp;
}

void divOP() {
    RPN* temp = topo;
    RPN* op2 = topo->proximo;
    if(op2->numero == 0) {
        cout << "Não é possível dividir um número por zero." << endl;
        return;
    } else {
        cout << "Operação: " << op2->numero << " " << temp->numero << " / " << endl;
        int result = op2->numero / temp->numero;
        cout << "Resultado: " << result << endl;
        op2->numero = result;
        topo = op2;
        delete temp;
    }
}

void multOP() {
    RPN* temp = topo;
    RPN* op2 = topo->proximo;
    int result = op2->numero * temp->numero;
    cout << "Operação: " << op2->numero << " " << temp->numero << " * " << endl;
    cout << "Resultado: " << result << endl;
    op2->numero = result;
    topo = op2;
    delete temp;

}

void processExpression(const string& expression) {
    stringstream ss(expression);
    string token;

    while(ss >> token) {
    if(token == "+"){
        plusOP();
    } else if(token == "-") {
        lessOP();
    } else if(token == "/") {
        divOP();
    } else if(token == "*") {
        multOP();
    } else {
        push(stoi(token));
    }
}

}

int main()
{
    setlocale(LC_ALL, "portuguese");
    int valor = 0, opc = 0, tamanho = 0;
    char opc1 = 0;
    string expression;

    do {
        cout << "Selecione um valor" << endl;
        cout << "1 - Push" << endl;
        cout << "2 - Index" << endl;
        cout << "3 - Pop" << endl;
        cout << "4 - Realizar uma operação matemática básica" << endl;
        cout << "5 - Realizar uma operação matemática complexa" << endl;
        cout << "0 - Sair" << endl;
        cin >> opc;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');


        switch(opc) {
        case 1:
            cout << "Digite um valor: ";
            cin >> valor;
            push(valor);
            break;

        case 2:
        if(isEmpty()) {
            cout << "Pilha vazia." << endl;
            break;
        }
        cout << "Valores empilhados" << endl;
        index();
        break;

        case 3:
        if(isEmpty()) {
            cout << "Pilha vazia." << endl;
            break;
        }
            pop();
            break;

        case 4:
        if(isEmpty()) {
            cout << "Pilha vazia." << endl;
            break;
        }

        if(countSize() < 2) {
            cout << "É necessário 2 ou mais números para realizar uma operação" << endl;
            break;
        }

            cout << "Selecione um operador" << endl;
            cout << "+ - / *" << endl;
            cin >> opc1;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if(opc1 == '+') {
                plusOP();
                break;
            } else if(opc1 == '-') {
                lessOP();
                break;
            } else if(opc1 == '/') {
                divOP();
                break;
            } else if(opc1 == '*') {
                multOP();
                break;
            }

        case 5:
            cout << "Digite a expressão: ";
            getline(cin, expression);

            processExpression(expression);

        if(!isEmpty()) {
            cout << "Resultado final: " << topo->numero << endl;
        } else {
            cout << "A expressão não resultou em um valor válido." << endl;
        }
        break;
    }

}while(opc != 0);


    return 0;
}
