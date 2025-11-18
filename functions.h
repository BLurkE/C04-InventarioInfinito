// ------------------------- Bibliotecas -------------------------
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <cmath>
using namespace std;

// ------------------------- Variaveis globais -------------------------

int id = 0;


// -------------------------- Tipos ------------------------------------

typedef int KeyType;
typedef string ValueTypeNome;
typedef float ValueTypeRaridade;

// ------------------------- Estruturas -------------------------

struct Item {
    int id;
    string nome;
    string dono;
    string categoria;
    float raridade; //0.0 a 100.0 / 0.0 = comum, 100.0 = raro
};

struct Similaridade {
    Item *item1;
    Item *item2;
    float similaridade; //0.0 a 100.0 / 0.0 = nada similar, 100.0 = igual
};

struct DatatypeNome {
  KeyType key;
  ValueTypeNome value;
};
struct DatatypeRaridade {
  KeyType key;
  ValueTypeRaridade value;
};

struct node_nome {
  DatatypeNome data;
  node_nome *left;
  node_nome *right;
};
struct node_raridade {
  DatatypeRaridade data;
  node_raridade *left;
  node_raridade *right;
};

// ------------------------- Funções ABB -------------------------

void insert_nome(node_nome * & curr, DatatypeNome data) {
  if (curr == NULL) {
    curr = new node_nome;
    curr->data = data;
    curr->left = NULL;
    curr->right = NULL;
  } else if (data.value < curr->data.value) {
    insert_nome(curr->left, data);
  } else {
    insert_nome(curr->right, data);
  }
}

void insert_raridade(node_raridade * & curr, DatatypeRaridade data) {
  if (curr == NULL) {
    curr = new node_raridade;
    curr->data = data;
    curr->left = NULL;
    curr->right = NULL;
  } else if (data.value < curr->data.value) {
    insert_raridade(curr->left, data);
  } else {
    insert_raridade(curr->right, data);
  }
}

node_nome * search_less_point_right_nome(node_nome * & curr) {
  node_nome * temp = curr;
  if (curr->left == NULL) {
    curr = curr->right;
    return temp;
  } else {
    return search_less_point_right_nome(curr->left);
  }
}

node_raridade * search_less_point_right_raridade(node_raridade * & curr) {
  node_raridade * temp = curr;
  if (curr->left == NULL) {
    curr = curr->right;
    return temp;
  } else {
    return search_less_point_right_raridade(curr->left);
  }
}

bool remove_nome(node_nome * & curr, int key) {
  if (curr == NULL) {
    return false;
  } else if (key == curr->data.key) {
    node_nome * temp = curr;
    if (curr->left == NULL) {
      curr = curr->right;
    } else if (curr->right == NULL) {
      curr = curr->left;
    } else {
      temp = search_less_point_right_nome(curr->right);
      curr->data = temp->data;
    }
    delete temp;
    return true;
  } else if (key < curr->data.key) {
    return remove_nome(curr->left, key);
  } else {
    return remove_nome(curr->right, key);
  }
}

bool remove_raridade(node_raridade * & curr, int key) {
  if (curr == NULL) {
    return false;
  } else if (key == curr->data.key) {
    node_raridade * temp = curr;
    if (curr->left == NULL) {
      curr = curr->right;
    } else if (curr->right == NULL) {
      curr = curr->left;
    } else {
      temp = search_less_point_right_raridade(curr->right);
      curr->data = temp->data;
    }
    delete temp;
    return true;
  } else if (key < curr->data.key) {
    return remove_raridade(curr->left, key);
  } else {
    return remove_raridade(curr->right, key);
  }
}

void print_value_nome(ValueTypeNome value) {
  cout << value << " ";
}

void print_value_raridade(ValueTypeRaridade value) {
  cout << value << " ";
}

//Função que imprime a árvore em ordem crescente de nome
void in_order_nome(node_nome * curr) {
  if (curr != NULL) {
    in_order_nome(curr->left);
    print_value_nome(curr->data.value); // Exemplo: imprimir o nome do item
    in_order_nome(curr->right);
  }
}

//Função que imprime a árvore em ordem crescente de raridade
void in_order_raridade(node_raridade * curr) {
  if (curr != NULL) {
    in_order_raridade(curr->left);
    print_value_raridade(curr->data.value); // Exemplo: imprimir o nome do item
    in_order_raridade(curr->right);
  }
}

// ------------------------- Funções auxiliares -------------------------

void inserirItem(list<Item> &lista, node_nome *& curr_nome, node_raridade *& curr_raridade) {
    Item novoItem;
    float raridade;

    cout << "Cadastro de Novo Item de viagem" << endl;
    novoItem.id = id;
    id++; // Incrementa o ID para o próximo item
    cout << "ID atribuido automaticamente: " << novoItem.id << endl;

    cin.ignore(); // Limpa o buffer do teclado antes de usar getline

    cout << "Nome do Item de viagem: ";
    getline(cin, novoItem.nome);

    cout << "Dono do item: ";
    getline(cin, novoItem.dono);

    cout << "Categoria do item: ";
    getline(cin, novoItem.categoria);

    cout << "Raridade do item (numero real entre 0.0 e 100.0): ";
    cin >> raridade;
    while(raridade < 0.0 || raridade > 100.0) {
        cout << "⚠️ Valor inválido! Digite um número entre 0.0 e 100.0." << endl;
        cout << "Raridade do item (numero real entre 0.0 e 100.0): ";
        cin >> raridade;
    }
    cout << "Raridade registrada: " << raridade << endl << endl;

    novoItem.raridade = raridade;
    lista.push_back(novoItem);

    cout << "✅ Item cadastrado com sucesso!" << endl;

    // Inserir na ABB
    insert_nome(curr_nome, {novoItem.id, novoItem.nome});
    insert_raridade(curr_raridade, {novoItem.id, novoItem.raridade});
}

void cadastrarSimilaridade(list<Similaridade> &listaDeSimilaridades, list<Item> &listaDeItens)
{
    int id1, id2;
    Item *item1 = nullptr, *item2 = nullptr; // Ponteiros para os itens //Iniciando igual à nullptr para evitar lixo de memória
    float similaridade; //0.0 a 100.0
    Similaridade novaSimilaridade;
    list<Item>::iterator it;

    cout << "Cadastro de Similaridade entre Itens" << endl;
    cout << "ID do primeiro item: ";
    cin >> id1;
    while(!item1){
        // Procurar o item na lista de itens
        for(it = listaDeItens.begin(); it!= listaDeItens.end(); it++){ // Iterador para percorrer a lista de itens
            if(it->id == id1){ // Se o ID do item atual for igual ao ID buscado
                item1 = &(*it); //O '&' pega o endereço do item  na lista
                break;
            }
        }
        if (!item1){
            cout << "Item nao encontrado! Tente novamente." << endl;
            cout << "ID do primeiro item: ";
            cin >> id1;
        }
    }

    cout << "ID do segundo item: ";
    cin >> id2;
    while(!item2){
        // Procurar o item na lista de itens
        for(it = listaDeItens.begin(); it!= listaDeItens.end(); it++){ // Iterador para percorrer a lista de itens
            if(it->id == id2){ // Se o ID do item atual for igual ao ID buscado
                item2 = &(*it); //O '&' pega o endereço do item  na lista
                break;
            }
        }
        if (!item2){
            cout << "Item nao encontrado! Tente novamente." << endl;
            cout << "ID do segundo item: ";
            cin >> id2;
        }
    }

    cout << "Similaridade entre os itens (numero real entre 0.0 e 100.0): ";
    cin >> similaridade;
    while(similaridade < 0.0 || similaridade > 100.0) {
        cout << "⚠️ Valor invalido! Digite um numero entre 0.0 e 100.0." << endl;
        cout << "Similaridade entre os itens (numero real entre 0.0 e 100.0): ";
        cin >> similaridade;
    }

 
    listaDeSimilaridades.push_back({item1, item2, similaridade});// Adiciona a nova similaridade à lista
    listaDeSimilaridades.push_back({item2, item1, similaridade});// Adiciona a nova similaridade à lista
    //Grafo não direcionado


    cout << "✅ Similaridade cadastrada com sucesso!" << endl;

}

void buscarItensSimilares(list<Similaridade> listaDeSimilaridades, list<Item> &listaItens) {
    list<Item>::iterator it;
    list<Similaridade>::iterator it2;

    Item *itemBusca; // Ponteiro para o item buscado, caso encontrado

    int idBusca;
    bool encontrado = false;

    cout << "Digite o ID do item para buscar similares: ";
    cin >> idBusca;

    //Este while serve para validar se a entrada do usuário é válida e garantir que o item exista na lista, além de armazenar o ponteiro do item buscado
    while(!encontrado){
        // Procurar o item na lista de itens
        for(it = listaItens.begin(); it!= listaItens.end(); it++){ // Iterador para percorrer a lista de itens
            if(it->id == idBusca){ // Se o ID do item atual for igual ao ID buscado
                itemBusca = &(*it); //O '&' pega o endereço do item  na lista
                encontrado = true;
                break;
            }
        }
        if(!encontrado){
            cout << "Item nao encontrado. Digite um ID valido: ";
            cin >> idBusca;
        }
    }

    // Agora, iremos buscar pelos items similares
    cout << endl << "Itens de viagem similares ao item: \"" << it->nome << "\""<< endl << endl;

    for(it2 = listaDeSimilaridades.begin(); it2!= listaDeSimilaridades.end(); it2++){ // Iterador para percorrer a lista de itens
        if(it2->item1 == itemBusca){// Se o ponteiro do item atual for igual ao ponteiro do item buscado
            Item *sim = it2->item2;
            cout << "ID: " << sim->id << endl;
            cout << "Nome: " << sim->nome << endl;
            cout << "Dono: " << sim->dono << endl;
            cout << "Categoria: " << sim->categoria << endl;
            cout << "Raridade: " << sim->raridade << endl << endl;
            cout << "Similaridade: " << it2->similaridade << endl << endl;
        }
    }

    cout << "✅ Busca por Similaridade finalizada com sucesso!" << endl;
}

void verificarExistencia(list<Item> &listaItens) {

    list<Item>::iterator it;
    string nomeBusca;
    bool encontrado = false;

    cin.ignore(); // Limpa o buffer do teclado antes de usar getline

    cout << "Digite o nome do item para verificar existencia: ";
    getline(cin, nomeBusca);

    for(it = listaItens.begin(); it!= listaItens.end(); it++){ // Iterador para percorrer a lista de itens
        if(it->nome == nomeBusca){ // Se o nome do item atual for igual ao nome buscado
            encontrado = true;
            break;
        }
    }

    if(encontrado){
        cout << "✅ O item \"" << nomeBusca << "\" existe na lista!" << endl;
    } else {
        cout << "❌ O item \"" << nomeBusca << "\" nao foi encontrado na lista." << endl;
    }
}

void listarItensAlfabeticaNome(list<Item> &listaItens) {

    listaItens.sort([](const Item &a, const Item &b) {
        return a.nome < b.nome; // Ordena em ordem crescente pelo nome
    });

    cout << "Itens de viagem em ordem alfabetica pelo nome:" << endl << endl;

    for (const auto &item : listaItens) {
        cout << "ID: " << item.id << endl;
        cout << "Nome: " << item.nome << endl;
        cout << "Dono: " << item.dono << endl;
        cout << "Categoria: " << item.categoria << endl;
        cout << "Raridade: " << item.raridade << endl << endl;
    }

    cout << "✅ Listagem finalizada com sucesso!" << endl;
}

void listarItensDecrescenteRaridade(list<Item> &listaItens) {

    listaItens.sort([](const Item &a, const Item &b) {
        return a.raridade > b.raridade; // Ordena em ordem decrescente pela raridade
    });

    cout << "Itens de viagem em ordem decrescente pela raridade:" << endl << endl;

    for (const auto &item : listaItens) {
        cout << "ID: " << item.id << endl;
        cout << "Nome: " << item.nome << endl;
        cout << "Dono: " << item.dono << endl;
        cout << "Categoria: " << item.categoria << endl;
        cout << "Raridade: " << item.raridade << endl << endl;
    }

    cout << "✅ Listagem finalizada com sucesso!" << endl;
}

void contarItensComMesmaCategoria(list<Item> &listaItens) {
    string categoriaBusca;
    int contador = 0;

    cin.ignore(); // Limpa o buffer do teclado antes de usar getline

    cout << "Digite a categoria para contar os itens: ";
    getline(cin, categoriaBusca);

    for (const auto &item : listaItens) {
        if (item.categoria == categoriaBusca) {
            contador++;
        }
    }

    cout << "Existem " << contador << " itens na categoria \"" << categoriaBusca << "\"." << endl;
}

void removerMenosRaridade(list<Item> &listaItens, node_nome *& curr_nome, node_raridade *& curr_raridade) {
    if (listaItens.empty()) {
        cout << "A lista de itens esta vazia. Nao ha itens para remover." << endl;
        return;
    }

    // Encontrar a menor raridade
    float menorRaridade = listaItens.front().raridade;
    for (const auto &item : listaItens) {
        if (item.raridade < menorRaridade) {
            menorRaridade = item.raridade;
        }
    }

    // Remover itens com a menor raridade
    listaItens.remove_if([menorRaridade](const Item &item) {
        return item.raridade == menorRaridade;
    });

    cout << "✅ Itens com a menor raridade (" << menorRaridade << ") foram removidos com sucesso!" << endl;

    // Atualizar a ABB removendo os IDs dos itens removidos
    list<Item>::iterator it;
    for(it = listaItens.begin(); it!= listaItens.end(); it++){ // Iterador para percorrer a lista de itens
        if(it->raridade == menorRaridade){ // Se a raridade do item atual for igual à menor raridade
            remove_nome(curr_nome, it->id); // Remover da ABB de nomes
            remove_raridade(curr_raridade, it->id); // Remover da ABB de raridades
        }
    }
}

// ------------------------- Funções Extras -------------------------
void carregarItensDeArquivo(list<Item> &listaItens, string nomeArquivo, node_nome *& curr_nome, node_raridade *& curr_raridade) {
    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        cout << "❌ Nao foi possivel abrir o arquivo \'" << nomeArquivo << "\'." << endl;
        return;
    }

    string linha;
    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        Item novoItem;
        string raridadeStr; // para ler o valor antes de converter

        // Lendo cada campo separado por vírgula
        string idStr;
        getline(ss, idStr, ',');
        getline(ss, novoItem.nome, ',');
        getline(ss, novoItem.dono, ',');
        getline(ss, novoItem.categoria, ',');
        getline(ss, raridadeStr, ',');

        // Converter strings para tipos numéricos
        novoItem.id = stoi(idStr);
        novoItem.raridade = stof(raridadeStr);

        // Inserir o item na lista
        listaItens.push_back(novoItem);

        // Atualizar o ID global, se necessário
        if (novoItem.id >= id) {
            id = novoItem.id + 1;
        }

        // Inserir na ABB
        insert_nome(curr_nome, {novoItem.id, novoItem.nome});
        insert_raridade(curr_raridade, {novoItem.id, novoItem.raridade});
    }

    arquivo.close();
    cout << "✅ Lista de itens carregada com sucesso do arquivo!" << endl;
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
                << item.raridade << endl;
    }

    arquivo.close();
    cout << "Itens salvos com sucesso no arquivo!" << endl;
}

void listarItensAbb_Crescente_nome(node_nome * curr) {
  if (curr != NULL) {
    cout << "Itens na ABB em ordem crescente de nome:" << endl << endl;
    in_order_nome(curr);
    cout << endl;
  }
  else{
    cout << "A arvore esta vazia." << endl;
  }
}

void listarItensAbb_Decrescente_raridade(node_raridade * curr) {
  if (curr != NULL) {
    cout << "Itens na ABB em ordem decrescente de raridade:" << endl << endl;
    in_order_raridade(curr);
    cout << endl;
  }
  else{
    cout << "A arvore esta vazia." << endl;
  }
}