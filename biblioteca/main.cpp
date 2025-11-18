#include <iostream>
#include <cstring>
#include <locale>
using namespace std;

struct Livro {
    int codigo;
    char titulo[50];
    char autor[50];
    int ano;
    Livro* prox;
};

struct NoArvore {
    Livro* livro;
    NoArvore* left;
    NoArvore* right;

    NoArvore(Livro* l) : livro(l), left(nullptr), right(nullptr) {}
};

struct Arvore {
    NoArvore* raiz;

    Arvore() {
        raiz = nullptr;
    }

    NoArvore* insertTree(NoArvore* tree, Livro* livro) {
    if(tree == nullptr) {
        return new NoArvore(livro);
    }

    if(strcmp(livro->titulo, tree->livro->titulo) < 0){
        tree->left = insertTree(tree->left, livro);
    } else {
        tree->right = insertTree(tree->right, livro);
    }

    return tree;
    }

    void insertTreeLivro(Livro* livro) {
        raiz = insertTree(raiz, livro);
    }

    void listTreeOrder(NoArvore* tree) {
        if(tree == nullptr) {
            cout << "A biblioteca ainda não possui livros cadastrados." << endl;
            return;
        }

        listTreeOrder(tree->left);

        cout << "Título: " << tree->livro->titulo << endl;
        cout << "Autor: " << tree->livro->autor << endl;
        cout << "Ano: " << tree->livro->ano << endl;
        cout << "-----------------------" << endl;

        listTreeOrder(tree->right);
    }

};

struct ListaEncadeada {
    Livro* primeiro;

    ListaEncadeada() {
        primeiro = nullptr;
    }

    void insertLivro(Arvore &arvore) {
        Livro* novo = new Livro;
        Livro* atual = primeiro;

        cout << "Digite o código do livro: ";
        cin >> novo->codigo;
        cin.ignore();
        cout << "Digite o título do livro: ";
        cin.getline(novo->titulo, 50);
        cout << "Digite o nome do autor: ";
        cin.getline(novo->autor, 50);
        cout << "Digite o ano de publicação do livro: ";
        cin >> novo->ano;

        novo->prox = primeiro;
        primeiro = novo;
        arvore.insertTreeLivro(novo);
        cout << "Livro cadastrado com sucesso." << endl;
    };

    void deleteLivro(string tituloRemove) {
    Livro* atual = primeiro;
    Livro* anterior = nullptr;

        if(atual == nullptr) {
            cout << "A biblioteca ainda não possui livros cadastrados." << endl;
            return;
        }

        while(atual != nullptr) {
            if(tituloRemove == atual->titulo) {
                cout << "Titulo do livro: " << atual->titulo << endl;
                delete atual;
                cout << "Livro removido com sucesso." << endl;
            } else {
                cout << "Livro não encontrado ou não cadastrado." << endl;
            }
                anterior = atual;
                atual = atual->prox;
        }
    }

    void findLivro() {
        Livro* atual = primeiro;
        Livro* anterior = nullptr;
        string find;

        if(atual == nullptr) {
            cout << "A biblioteca ainda não possui livros cadastrados." << endl;
            return;
        }

        cout << "Digite o título do livro que você quer buscar: ";
        cin >> find;

        while(atual != nullptr) {
            if(find == atual->titulo) {
                cout << "-----------------------------------------" << endl;
                cout << "Livro encontrado" << endl;
                cout << "Título: " << atual->titulo << endl;
                cout << "Autor: " << atual->autor << endl;
                cout << "Ano de publicação: " << atual->ano << endl;
                cout << "-----------------------------------------" << endl;
            } else {
                cout << "Livro não encontrado ou não cadastrado." << endl;
            }

            anterior = atual;
            atual = atual->prox;
        }
    }

    void findAll() {
        Livro* atual = primeiro;
        Livro* anterior = nullptr;

        if(atual == nullptr) {
            cout << "A biblioteca ainda não possui livros cadastrados." << endl;
            return;
        }

        cout << "Aqui estão todos os livros da biblioteca" << endl;
        while(atual != nullptr) {
            cout << "------------------------------" << endl;
            cout << "Título: " << atual->titulo << endl;
            cout << "Autor: " << atual->autor << endl;
            cout << "Ano de publicação: " << atual->ano << endl;
            cout << "------------------------------" << endl;
            anterior = atual;
            atual = atual->prox;
        }
    }

};

struct Operacao {
    char acoes[50];
    Operacao* prox;
};

Operacao* topo = NULL;

void novaAcao(const char* acoesBiblioteca) {
    Operacao* novo = new Operacao;
    strcpy(novo->acoes, acoesBiblioteca);
    novo->prox = topo;
    topo = novo;
    cout << "Ação registrada com sucesso. -> " << acoesBiblioteca << endl;
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    ListaEncadeada lista;
    Livro livro;
    Arvore arvore;
    int opc = 0, opc1 = 0, opc2 = 0;
    char acoesBiblioteca[50];
    string tituloRemove;


    do {
    cout << "Bem vindo à biblioteca, escolha a opção abaixo que mais te favorece hoje" << endl;
    cout << "1 - Cadastrar livro" << endl;
    cout << "2 - Remover livro pelo título" << endl;
    cout << "3 - Buscar livro pelo título " << endl;
    cout << "4 - Listar todos os livros" << endl;
    cout << "5 - Desfazer a última operação" << endl;
    cout << "6 - Listar em ordem alfabética" << endl;
    cout << "7 - Sair" << endl;
    cin >> opc;
    cin.ignore();

    switch(opc) {
        case 1:
        cout << "Preencha as informações abaixo:" << endl;
        lista.insertLivro(arvore);
        cout << "Deseja registrar a operação?" << endl;
        cout << "Digite 1 para sim e 2 para não" << endl;
        cin >> opc1;
        cin.ignore();
        if(opc1 == 1) {
            cout << "Digite a última ação realizada: ";
            cin.getline(acoesBiblioteca, 50);
            novaAcao(acoesBiblioteca);
            break;
        } else {
            break;
        }

        case 2:
        cout << "Digite o título do livro que você quer remover: ";
        cin >> tituloRemove;
        lista.deleteLivro(tituloRemove);
        cout << "Deseja registrar a operação?" << endl;
        cout << "Digite 1 para sim e 2 para não" << endl;
        cin >> opc1;
        cin.ignore();
        if(opc1 == 1) {
            cout << "Digite a última ação realizada: ";
            cin.getline(acoesBiblioteca, 50);
            novaAcao(acoesBiblioteca);
            break;
        } else {
            break;
        }

        case 3:
        lista.findLivro();
        cout << "Deseja registar a operação?" << endl;
        cout << "Digite 1 para sim e 2 para não" << endl;
        cin >> opc1;
        cin.ignore();
        if(opc1 == 1) {
            cout << "Digite a última operação realizada: ";
            cin.getline(acoesBiblioteca, 50);
            novaAcao(acoesBiblioteca);
            break;
        } else {
            break;
        }

        case 4:
        lista.findAll();
        cout << "Deseja registrar a operação?" << endl;
        cout << "Digite 1 para sim e 2 para não" << endl;
        cin >> opc1;
        if(opc1 == 1) {
            cout << "Digite a última operação realizada: ";
            cin.getline(acoesBiblioteca, 50);
            novaAcao(acoesBiblioteca);
            break;
        } else {
            break;
        }

        case 5:
        cout << "Deseja desfazer qual operação? Digite 1 para 'INSERÇÃO' e 2 para 'REMOÇÃO': " ;
        cin >> opc2;
        cout << endl;
        if(opc2 == 2) {
            lista.deleteLivro(tituloRemove);
            cout << "Digite o título do livro que você quer remover: ";
            cin >> tituloRemove;
            cout << "Operação desfeita com sucesso. Agora o último livro não existe mais na biblioteca" << endl;
            break;
        } else if (opc2 == 1) {
            cout << "Preencha as informações do livro que acabou de ser removido." << endl;
            lista.insertLivro(arvore);
            break;
        }

        case 6:
        cout << "Lista dos livros em ordem alfabética" << endl;
        arvore.listTreeOrder(arvore.raiz);
        break;
    }


}while(opc != 7);
    cout << "Programa finalizado com sucesso.";


    return 0;
}

