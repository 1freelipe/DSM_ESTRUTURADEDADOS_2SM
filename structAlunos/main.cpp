#include <iostream>
#include <locale>

using namespace std;

struct Aluno {
    string nome;
    string curso;
    int raescolar;
    int media_final;

    // Funções da struct
    void viewContent() {
        cout << "|--------------------|" << endl;
        cout << "|Nome................: " << nome << endl;
        cout << "|Curso...............: " << curso << endl;
        cout << "|Registro acadêmico..: " << raescolar << endl;
        cout << "|Média final.........: " << media_final << endl;
        cout << "|--------------------|" << endl;
    }

    bool findRA(Aluno* alunos, int raescolar, int totalCadastrados){
        for(int i=0; i < totalCadastrados; i++){
            if(raescolar == alunos[i].raescolar){
                return true;
            }
        }
        return false;
    }
};

// Funções globais
bool limitExceded(int capacidade, int totalCadastrados);
void updateMedia(int newMedia, int &media_final);
int findIndexRA(Aluno *alunos, int raescolar, int totalCadastrados);
bool deletedByRA(Aluno *alunos, int raescolar, int &totalCadastrados);

int main()
{
    setlocale(LC_ALL, "portuguese");

    // Variáveis globais
    int opc, totalCadastrados = 0, capacidade = 50, raBuscado = 0, newMedia = 0;
    bool findStudent = false;

    Aluno *alunos = new Aluno[capacidade];


    do {
    cout << "Bem vindo ao cadastro de alunos" << endl;
    cout << "Selecione uma das opções ou digite [0] para sair" << endl;
    cout << "(1). Cadastrar aluno" << endl;
    cout << "(2). Listar alunos cadastrados" << endl;
    cout << "(3). Buscar aluno por RA" << endl;
    cout << "(4). Atualizar a média final do aluno" << endl;
    cout << "(5). Excluir aluno" << endl;
    cout << "(0). Sair" << endl;
    cin >> opc;
    cin.ignore();

    switch(opc) {
        case 1:
        if(limitExceded(capacidade, totalCadastrados)) {
            cout << "Capacidade total de alunos atingida" << endl;
            break;
        }

        cout << "Digite o RA do aluno: ";
        cin >> raBuscado;
        cin.ignore();

        if(findIndexRA(alunos, raBuscado, totalCadastrados)!= -1) {
            cout << "RA já existente" << endl;
            break;
        }else {
            alunos[totalCadastrados].raescolar = raBuscado;
        }

        cout << "Digite o nome do aluno: ";
        getline(cin, alunos[totalCadastrados].nome);
        cout << "Digite o curso do aluno: ";
        getline(cin, alunos[totalCadastrados].curso);
        cout << "Digite a média final do aluno: ";
        cin >> alunos[totalCadastrados].media_final;
        totalCadastrados++;
        cout << "Aluno cadastrado" << endl;
        break;

        case 2:
        if(totalCadastrados == 0) {
            cout << "Nenhum aluno cadastrado.\n";
            break;
        } else {
            for(int i=0; i < totalCadastrados; i++){
                alunos[i].viewContent();
            }
            break;
        }

        case 3:
        cout << "Digite o RA que deseja buscar: ";
        cin >> raBuscado;
        if(alunos[totalCadastrados].findRA(alunos, raBuscado, totalCadastrados)){
            cout << "Aluno encontrado: " << endl;
            for(int i=0; i < totalCadastrados; i++){
                alunos[i].viewContent();
            }
            cout << endl;
            break;
        } else {
            cout << "Aluno não encontrado ou não cadastrado" << endl;
            break;
        }

        case 4:
        cout << "Digite o RA do aluno que será alterado a média final: ";
        cin >> raBuscado;

        for(int i=0; i < totalCadastrados; i++){
            if(raBuscado == alunos[i].raescolar) {
                findStudent = true;
                cout << "Aluno encontrado" << endl;
                alunos[i].viewContent();

                cout << "Agora digite a nova média final dele: ";
                cin >> newMedia;
                updateMedia(newMedia, alunos[i].media_final);
                cout << "Nova média: " << alunos[i].media_final << endl;
                cout << "Média atualizada com sucesso" << endl;
                break;
            }
        }
        if(!findStudent) {
            cout << "Aluno não encontrado ou não cadastrado." << endl;
        }
        break;

        case 5:
        cout << "Digite o RA do aluno que deseja excluir: ";
        cin >> raBuscado;

        if(deletedByRA(alunos, raBuscado, totalCadastrados)){
            cout << "Aluno deletado com sucesso" << endl;
        } else {
            cout << "Aluno não encontrado" << endl;
        }
        break;

    }

    }while(opc != 0);


    return 0;
}

// Verificar se o máximo de alunos já não foi atingido
bool limitExceded(int capacidade, int totalCadastrados){
    if(totalCadastrados == capacidade) return true;
    return false;
}

// Alterar a média final de um aluno
void updateMedia(int newMedia, int &media_final){
    media_final = newMedia;
}

// Procurar e retornar o index do aluno
int findIndexRA(Aluno *alunos, int raescolar, int totalCadastrados) {
    for(int i=0; i < totalCadastrados; i++){
        if(raescolar == alunos[i].raescolar) {
            return i;
        }
    }
    return -1;
}

// Deletar um determinado aluno pela busca do seu RA(buscado pelo index do aluno)
bool deletedByRA(Aluno *alunos, int raescolar, int &totalCadastrados){
    int index = findIndexRA(alunos, raescolar, totalCadastrados);
    if(index == -1){
        return false;
    }

    for(int i = index; i < totalCadastrados - 1; i++){
        alunos[i] = alunos[i + 1];
    }

    totalCadastrados--;
    return true;
}
