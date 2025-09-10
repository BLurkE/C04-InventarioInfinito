#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Item {
  int id;
  string nome;
  string dono;
  string categoria;
  int apego_emocional;
};

struct No
{
    Item item;
    No *proximo;
    No() : proximo(NULL) {}
};

struct Lista
{
    No *primeiro;
    int totalItens;
    Lista() : primeiro(NULL), totalItens(0) {}
};

bool listaVazia(Lista *lista)
{
    return lista->primeiro == NULL;
}

void append(Lista *lista, Item novoItem)
{
    No *novoNo = new No;
    novoNo->item = novoItem;

    if (listaVazia(lista))
    {
        lista->primeiro = novoNo;
    }
    else
    {
        No *atual = lista->primeiro;
        while (atual->proximo != NULL)
        {
            atual = atual->proximo;
        }
        atual->proximo = novoNo;
    }
    lista->totalItens += 1;
}

bool pop(Lista *lista, string nome)
{
    if (listaVazia(lista))
    {
        cout << "Lista vazia." << endl;
        return false;
    }

    No *atual = lista->primeiro;
    No *anterior = NULL;

    while (atual != NULL && atual->item.nome != nome)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL)
    {
        cout << "Elemento nao encontrado." << endl;
        return false;
    }

    if (anterior == NULL)
    {
        lista->primeiro = atual->proximo;
    }
    else
    {
        anterior->proximo = atual->proximo;
    }

    delete atual;
    lista->totalItens -= 1;
    cout << "Elemento removido: " << nome << endl;
    return true;
}

void mostraItens(Lista *lista)
{
    if (lista->totalItens >= 1)
    {
        No *atual = lista->primeiro;
        cout << "\nItens disponiveis:\n";
        while (atual != NULL)
        {
            cout << atual->item.id << endl;
            cout << atual->item.nome << endl;
            cout << atual->item.dono << endl;
            cout << atual->item.categoria << endl;
            cout << atual->item.apego_emocional << endl << endl;

            atual = atual->proximo;
        }
        cout << endl;
    }

    else{
        cout << "\nAinda nao existem itens cadastrados.\n" << endl;
    }
}

Lista ordenarItens_Nome(Lista* lista) {
    Lista novaListaOrdenada;

    No* atual = lista->primeiro;

    while (atual != NULL) {
        No* copia = new No;
        copia->item = atual->item;
        copia->proximo = NULL;

        if (novaListaOrdenada.primeiro == NULL || 
            copia->item.nome < novaListaOrdenada.primeiro->item.nome) {
            
            copia->proximo = novaListaOrdenada.primeiro;
            novaListaOrdenada.primeiro = copia;
        } else {
            No* pos = novaListaOrdenada.primeiro;
            while (pos->proximo != NULL && 
                   pos->proximo->item.nome < copia->item.nome) {
                pos = pos->proximo;
            }
            copia->proximo = pos->proximo;
            pos->proximo = copia;
        }

        atual = atual->proximo;
    }

    novaListaOrdenada.totalItens = lista->totalItens;

    return novaListaOrdenada;
}

Lista ordenarItens_Apego(Lista* lista) {
    Lista novaListaOrdenada;

    No* atual = lista->primeiro;

    while (atual != NULL) {
        No* copia = new No;
        copia->item = atual->item;
        copia->proximo = NULL;

        if (novaListaOrdenada.primeiro == NULL || 
            copia->item.apego_emocional > novaListaOrdenada.primeiro->item.apego_emocional) {
            
            copia->proximo = novaListaOrdenada.primeiro;
            novaListaOrdenada.primeiro = copia;
        } else {
            No* pos = novaListaOrdenada.primeiro;
            while (pos->proximo != NULL && 
                   pos->proximo->item.apego_emocional > copia->item.apego_emocional) {
                pos = pos->proximo;
            }
            copia->proximo = pos->proximo;
            pos->proximo = copia;
        }

        atual = atual->proximo;
    }

    novaListaOrdenada.totalItens = lista->totalItens;

    return novaListaOrdenada;
}

int toInt(const std::string &s) {
    int x;
    std::stringstream ss(s);
    ss >> x;
    return x;
}

void carregarItensDeArquivo(Lista *lista, const string &nomeArquivo) {
    ifstream arquivo(nomeArquivo.c_str());

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo " << nomeArquivo << endl;
        return;
    }

    string linha;
    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        string campo;
        Item novoItem;

        // id
        getline(ss, campo, ',');
        novoItem.id = toInt(campo);

        // nome
        getline(ss, campo, ',');
        novoItem.nome = campo;

        // dono
        getline(ss, campo, ',');
        novoItem.dono = campo;

        // categoria
        getline(ss, campo, ',');
        novoItem.categoria = campo;

        // apego_emocional
        getline(ss, campo, ',');
        novoItem.apego_emocional = toInt(campo);

        append(lista, novoItem);
    }

    arquivo.close();
    cout << "Itens carregados com sucesso do arquivo!" << endl;
}