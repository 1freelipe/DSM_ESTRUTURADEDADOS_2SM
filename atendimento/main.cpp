#include <iostream>
#include <locale>
#include <cstring>

using namespace std;

#define TAM_MAX 10
struct Pedidos {
    char nome[30];
    char problema[50];
};

struct Fila {
    Pedidos elementos[TAM_MAX];
    int inicio;
    int fim;
    int total;
};

void inicializarFila(Fila &f){
    f.inicio = 0;
    f.fim = -1;
    f.total = 0;
}

bool filaCheia(Fila &f){
    return f.total == TAM_MAX;
}

bool filaVazia(Fila &f){
    return f.total == 0;
}

void registrarAtendimento(Fila &f, const char* nomeAluno, const char* novoPedido){
    if(filaCheia(f)){
        cout << "\033[1;31mA fila de pedidos está cheia, tente outra hora.\033[0m" << endl;
        return;
    }

    f.fim = (f.fim + 1) % TAM_MAX;
    strcpy(f.elementos[f.fim].nome, nomeAluno);
    strcpy(f.elementos[f.fim].problema, novoPedido);
    f.total++;

    cout << "\033[32mAtendimento registrado com sucesso.\033[0m" << endl;
}

void proximoAtendimento(Fila &f){
    if(filaVazia(f)) {
        cout << "\033[1;31mA fila está vazia.\033[0m" << endl;
        return;
    }

    Pedidos p = f.elementos[f.inicio];
    f.fim = (f.fim - 1) % TAM_MAX;
    f.total--;

    cout << "\033[32mAtendendo o próximo aluno: " << p.nome << endl;
    cout << "Problema: " << p.problema << "\033[0m" << endl;
}

void verificarLista(Fila &f) {
    if(filaVazia(f)) {
        cout << "\033[1;31mA fila está vazia.\033[0m" << endl;
        return;
    }

    for(int i = 0; i < f.total; i++){
        int index = (f.fim - i) % TAM_MAX;
        cout << i + 1 << "º"<< " - Nome: " << f.elementos[index].nome << endl;
        cout << "Problema: " << f.elementos[index].problema << endl;
        cout << "===============================" << endl;
    }
}


struct Pilha {
    char acoes[50];
    Pilha* proximo;
};

Pilha* topo = NULL;

void novaAcao(const char* acoesTec) {
    Pilha* novo = new Pilha;
    strcpy(novo->acoes, acoesTec);
    novo->proximo = topo;
    topo = novo;
    cout << "Ação: " << novo->acoes << " inserida." << endl;
}

void verificarAcoes() {
    Pilha* atual = topo;

    cout << "Ações inseridas: ";
    while(atual != NULL) {
        cout << " | " << atual->acoes;
        atual = atual->proximo;
    }

    cout << endl;
}

void undo() {
    if(topo == NULL) {
        cout << "Nenhuma ação foi registrada ainda." << endl;
        return;
    }

    Pilha* temp = topo;
    topo = topo->proximo;

    cout << "Ação: " << temp->acoes << " desfeita." << endl;
    delete temp;
}

int main()
{
    Fila fila;
    inicializarFila(fila);
    setlocale(LC_ALL, "portuguese");
    int opc = 0, opc1 = 0;
    char nome[30];
    char problema[50];
    char acoesTec[50];

do {

    cout << "Menu Principal - Digite o valor desejado para a operação" << endl;
    cout << "1 - Registrar novo atendimento" << endl;
    cout << "2 - Atender próximo aluno" << endl;
    cout << "3 - Listar fila de espera" << endl;
    cout << "4 - Sair" << endl;
    cin >> opc;
    cin.ignore();

    switch(opc) {
        case 1:
            cout << "Digite o nome do aluno: ";
            cin.getline(nome, 30);
            cout << "Digite o problema que está acontecendo: ";
            cin.getline(problema, 50);
            registrarAtendimento(fila, nome, problema);
            break;


        case 2:
            proximoAtendimento(fila);
            do {
                cout << "1 - Relatório das ações necessárias para o atendimento" << endl;
                cout << "2 - Histórico de ações" << endl;
                cout << "3 - Desfazer a última ação" << endl;
                cout << "4 - Finalizar atendimento" << endl;
                cin >> opc1;
                cin.ignore();

                switch(opc1) {
                    case 1:
                    cout << "Digite a ação que deseja registrar: ";
                    cin.getline(acoesTec, 50);
                    novaAcao(acoesTec);
                    break;

                    case 2:
                    verificarAcoes();
                    break;

                    case 3:
                    undo();
                    break;
                }
            }while(opc1 != 4);
            break;

        case 3:
        cout << "Esses são os próximos atendimentos: " << endl;
        verificarLista(fila);
    }

}while(opc != 4);


    return 0;
}
