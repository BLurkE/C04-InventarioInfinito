#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <string>
#include <list>

struct Item {
    int id;
    std::string nome;
    std::string dono;
    std::string categoria;
    int apego_emocional;
};

struct Similaridade {
    Item item1;
    Item item2;
    float similaridade;
};

// Declarações de funções (headers)
bool listaVazia(const std::list<Item> &lista);
void append(std::list<Item> &lista, const Item &novoItem);
bool pop(std::list<Item> &lista, const std::string &nome);
void mostraItens(const std::list<Item> &lista);
std::list<Item> ordenarItens_Nome(const std::list<Item> &lista);
std::list<Item> ordenarItens_Apego(const std::list<Item> &lista);
void carregarItensDeArquivo(std::list<Item> &lista, const std::string &nomeArquivo);
void salvarItensEmArquivo(const std::list<Item> &lista, const std::string &nomeArquivo);
void insert(std::list<Item> &lista);
double calcularProximidadeApegoEmocional(double a, double b);
std::list<Item> buscaItensPorIds(const std::list<Item> &lista, int ids[], int num_ids);

#endif
