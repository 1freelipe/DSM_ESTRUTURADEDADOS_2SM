#include <iostream>
#include <locale>

using namespace std;

struct Aluno {
    string nome;
    int idade;
    int matricula;
    Aluno* prox; // Ponteiro que aponta para o próximo nó
};

struct ListaEncadeada {
    Aluno* primeiro; // Criando um primeiro espaço na lista
    int tamanho;

    ListaEncadeada() {
        primeiro = nullptr; // Primeiro apontando para null, indicando que a lista está vazia
        tamanho = 0;
    }

    bool verifyList() {
        Aluno* atual = primeiro;

        if(atual == nullptr) {
            return true;
        } else if(atual != nullptr) {
            return false;
        }
    }

    void insertStudent() {
        bool findMatricula = false;
        Aluno* novo = new Aluno;
        Aluno* atual = primeiro;
        for(int i=0; i < 1; i++){
            cout << "Digite o nome do aluno que deseja cadastrar: ";
            cin >> novo->nome;
            cout << "Digite a idade do aluno: ";
            cin >> novo->idade;
            cout << "Digite a matrícula do aluno: ";
            cin >> novo->matricula;
            while(atual != nullptr) { // Fazendo um looping ao inserir a matrícula, para verificar se a matrícula já existe no sistema
                if(atual->matricula == novo->matricula){
                    cout << "Essa matrícula já existe no sistema." << endl;
                    findMatricula = true; // Se ela existir, o programa não irá cadastrar o aluno
                    break;
                }
                atual = atual->prox;
            }
        }
        if(!findMatricula){
            novo->prox = primeiro; // O primeiro insert agora ponta para o primeiro que antes estava null
            primeiro = novo; // E o primeiro já aponta para o próximo insert, criando um link
            cout << "Aluno cadastrado com sucesso." << endl;
            tamanho++;
        }
    }

    void printList() {
        Aluno* atual = primeiro;
        while(atual != nullptr){
            cout << "Nome: " << atual->nome << " | Idade: " << atual->idade << " | Matrícula: " << atual->matricula << endl;
            atual = atual->prox;
        }
    }

    void show(int matricula) {
        bool findStudent = false;
        Aluno* atual = primeiro;
        while(atual != nullptr) {
            if(atual->matricula == matricula){
                cout << "Aluno encontrado: " << endl;
                cout << "Nome: " << atual->nome << " | Idade: " << atual->idade << " | Matrícula: " << atual->matricula << endl;
                findStudent = true;
            }

            atual = atual->prox;
        }
        if(atual == nullptr && !findStudent) {
            cout << "Aluno não encontrado ou não cadastrado." << endl;
        }
    }

    void removeOne(int matricula) {
        bool findStudent = false;
        char op;
        Aluno* atual = primeiro;
        Aluno* anterior = nullptr;
        while(atual != nullptr) {
            if(atual->matricula == matricula){
                cout << "Aluno encontrado" << endl;
                cout << "Nome: " << atual->nome << " | Idade: " << atual->idade << " | Matrícula: " << atual->matricula << endl;
                findStudent = true;
                cout << "Deseja excluir esse cadastro? S/N" << endl;
                cin >> op;

               if(op == 'S' || op == 's'){
                   if(anterior == nullptr) { // Verificando se o aluno é o único aluno cadastrado na lista
                       primeiro = atual->prox;
                   } else { // Se ele não for, apenas vai pular o nó deletado, evitando um loop
                       anterior->prox = atual->prox;
                   }
               }
               delete atual;
               cout << "Cadastro excluído com sucesso" << endl;
               tamanho--;

            return;
        }
        anterior = atual;
        atual = atual->prox;
    }

    if(!findStudent) {
        cout << "Aluno com a matrícula " << matricula << " não encontrado!" << endl;
    }
}

void bubbleSort() {
    Aluno* atual;
    Aluno* proximo;
    Aluno* anterior;
    bool control;

    if (primeiro == nullptr || primeiro->prox == nullptr) {
        return; // Lista vazia ou com um único nó, já está ordenada
    }

    do {
        control = false;
        anterior = nullptr;
        atual = primeiro;

        while (atual != nullptr && atual->prox != nullptr) {
            proximo = atual->prox;

            if (atual->matricula > proximo->matricula) {
                // Lógica de troca
                if (anterior == nullptr) {
                    primeiro = proximo; // A troca envolve o primeiro nó da lista
                } else {
                    anterior->prox = proximo; // A troca ocorre no meio da lista
                }

                atual->prox = proximo->prox;

                proximo->prox = atual;

                anterior = proximo;
                atual = proximo->prox;

                control = true;
            } else {
                anterior = atual;
                atual = atual->prox;
            }
        }
    } while (control);
}

};

int main()
{
    setlocale(LC_ALL, "portuguese");
    int opc = 0, matricula = 0;
    ListaEncadeada lista; // Criando uma referência para a lista encadeada

    do{
    cout << "Bem vindo ao cadastro de alunos" << endl;
    cout << "Selecione uma das opções ou digite [0] para sair" << endl;
    cout << "(1). Cadastrar aluno" << endl;
    cout << "(2). Listar alunos cadastrados" << endl;
    cout << "(3). Buscar aluno pela matrícula" << endl;
    cout << "(4). Excluir aluno" << endl;
    cout << "(0). Sair" << endl;
    cin >> opc;
    cin.ignore();

    switch(opc) {
        case 1:
        lista.insertStudent();
        break;

        case 2:
        if(lista.verifyList()) {
            cout << "Não exite nenhum aluno cadastrado." << endl;
            break;
        }
        cout << "Lista de todos os alunos" << endl;
        lista.bubbleSort();
        lista.printList();
        break;

        case 3:
        if(lista.verifyList()) {
            cout << "Não existe nenhum aluno cadastrado." << endl;
            break;
        } else {
            cout << "Digite a matrícula do aluno que você deseja procurar: ";
            cin >> matricula;
            lista.show(matricula);
            break;
        }

        case 4:
        if(lista.verifyList()) {
            cout << "Não existe nenhum aluno cadastrado." << endl;
            break;
        }
        cout << "Digite a matrícula do aluno que você deseja excluir: ";
        cin >> matricula;
        lista.removeOne(matricula);
        break;
    }

    }while(opc != 0);

    return 0;
}

