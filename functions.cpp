#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <cmath>

using namespace std;
struct Item {
    int id;
    string nome;
    string dono;
    string categoria;
    int apego_emocional;
};

struct Similaridade {
    Item item1;
    Item item2;
    float similaridade;
};

// ------------------------- Funções auxiliares -------------------------

bool listaVazia(const list<Item> &lista) {
    return lista.empty();
}

void append(list<Item> &lista, const Item &novoItem) {
    lista.push_back(novoItem);
}

bool pop(list<Item> &lista, const string &nome) {
    
    list<Item>::iterator it;
    for (it = lista.begin(); it != lista.end(); ++it) {
        if (it->nome == nome) {
            lista.erase(it);
            cout << "Elemento removido: " << nome << endl;
            return true;
        }
    }
    cout << "Elemento nao encontrado." << endl;
    return false;
}

void mostraItens(const list<Item> &lista) {
    if (lista.empty()) {
        cout << "\nAinda nao existem itens cadastrados.\n" << endl;
        return;
    }

    cout << "\nItens disponiveis:\n";
    for (list<Item>::const_iterator it = lista.begin(); it != lista.end(); ++it) {
        const Item &item = *it;
        cout << item.id << endl;
        cout << item.nome << endl;
        cout << item.dono << endl;
        cout << item.categoria << endl;
        cout << item.apego_emocional << endl << endl;
    }

    cout << endl;
}

bool compararPorNome(const Item &a, const Item &b) {
    return a.nome < b.nome;
}

bool compararPorApego(const Item &a, const Item &b) {
    return a.apego_emocional > b.apego_emocional;
}

list<Item> buscaItensPorIds(const list<Item> &lista, int ids[], int num_ids){

    list<Item> itens;

    int count_items_found = 0, aux = 0;
    bool items_found = false;

    while (!items_found && count_items_found != num_ids)
    {
        for (list<Item>::const_iterator it = lista.begin(); it != lista.end(); ++it)
        {
            const Item &item = *it;
            if (item.id == ids[count_items_found]){
                itens.push_back(item);
                count_items_found++;
                if(count_items_found == num_ids){
                    items_found = true;
                }
                break;
            }
            aux++;
        }

        if(aux >= 100){
            break;
        }
    }

    if (items_found){
        cout << "Itens encontrados!" << endl;
    }
    else{
        cout << "Itens não encontrados!" << endl;
    }

    return itens;
}

list<Item> ordenarItens_Nome(const list<Item> &lista) {
    list<Item> ordenada = lista;
    ordenada.sort(compararPorNome);
    return ordenada;
}

list<Item> ordenarItens_Apego(const list<Item> &lista) {
    list<Item> ordenada = lista;
    ordenada.sort(compararPorApego);
    return ordenada;
}

int toInt(const string &s) {
    int x;
    stringstream ss(s);
    ss >> x;
    return x;
}

void carregarItensDeArquivo(list<Item> &lista, const string &nomeArquivo) {
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

        getline(ss, campo, ',');
        novoItem.id = toInt(campo);

        getline(ss, campo, ',');
        novoItem.nome = campo;

        getline(ss, campo, ',');
        novoItem.dono = campo;

        getline(ss, campo, ',');
        novoItem.categoria = campo;

        getline(ss, campo, ',');
        novoItem.apego_emocional = toInt(campo);

        append(lista, novoItem);
    }

    arquivo.close();
    cout << endl << "Itens carregados com sucesso do arquivo!" << endl;
}

void salvarItensEmArquivo(const list<Item> &lista, const string &nomeArquivo) {
    ofstream arquivo(nomeArquivo.c_str());

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo " << nomeArquivo << " para escrita." << endl;
        return;
    }

    for (list<Item>::const_iterator it = lista.begin(); it != lista.end(); ++it) {
        const Item &item = *it;
        arquivo << item.id << ","
                << item.nome << ","
                << item.dono << ","
                << item.categoria << ","
                << item.apego_emocional << endl;
    }

    arquivo.close();
    cout << "Itens salvos com sucesso no arquivo!" << endl;
}

void insert(list<Item> &lista) {
    Item novoItem;
    int aux;

    cout << "Cadastro de Novo Item" << endl;
    novoItem.id = lista.size();
    cout << "ID atribuido automaticamente: " << novoItem.id << endl;

    std::cin.ignore();

    cout << "Item: ";
    std::getline(std::cin, novoItem.nome);

    cout << "Dono: ";
    std::getline(std::cin, novoItem.dono);

    cout << "Categoria: ";
    std::getline(std::cin, novoItem.categoria);

    do {
        cout << "Apego emocional (numero inteiro entre 0 e 100): ";
        std::cin >> aux;
        if (aux < 0 || aux > 100)
            cout << "⚠️ Valor inválido! Digite um número entre 0 e 100." << endl;
    } while (aux < 0 || aux > 100);

    novoItem.apego_emocional = aux;
    append(lista, novoItem);

    cout << "✅ Item cadastrado com sucesso!" << endl;
}

double calcularProximidadeApegoEmocional(double a, double b) {
    return (1 - fabs(a - b) / 100.0) * 33.0;
}
