#include <iostream>
#include <locale>

using namespace std;

struct Cadastro {
    string nome;
    int idade;
    float mediafinal;

    void store(string nome, int idade, float mediafinal){
        this->nome = nome;
        this->idade = idade;
        this->mediafinal = mediafinal;
    }

    void view()  {
        cout << "Nome: " << nome << endl;
        cout << "Idade: " << idade << endl;
        cout << "Média final: " << mediafinal << endl;
    }

};



int main()
{
    setlocale(LC_ALL, "portuguese");
    int capacidade = 50, totalCadastrados = 0, maior = 0;

    Cadastro *aluno = new Cadastro[capacidade];

    for(int i=0; i < 5; i++){
        cout << "Digite o nome do aluno: ";
        cin >> aluno[totalCadastrados].nome;
        cout << "Digite a idade do aluno: ";
        cin >> aluno[totalCadastrados].idade;
        cout << "Digite a média final: ";
        cin >> aluno[totalCadastrados].mediafinal;
        cout << endl;
        totalCadastrados++;
    }

    cout << "Alunos Cadastrados: " << endl;
    for(int i=0; i < totalCadastrados; i++){
        aluno[i].view();
        cout << endl;
    }

    maior = aluno[0].mediafinal;

    for(int i=0; i < totalCadastrados; i++){
        if(aluno[i].mediafinal > maior){
            cout << "O aluno com a maior nota foi: " << endl;
            aluno[i].view();
        }
    }



    return 0;
}
