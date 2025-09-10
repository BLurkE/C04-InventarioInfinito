#include <iostream>
#include "functions.cpp"
using namespace std;

void inserirItem(Lista *lista)
{
  Item novoItem;
  novoItem.id = 0;
  novoItem.categoria = "Higiene";
  novoItem.apego_emocional = 30;
  novoItem.dono = "Pedro";
  novoItem.nome = "Escova";
  append(lista, novoItem);
  novoItem.id = 1;
  novoItem.categoria = "Higiene";
  novoItem.apego_emocional = 75;
  novoItem.dono = "Maria";
  novoItem.nome = "Shampoo";
  append(lista, novoItem);
  novoItem.id = 2;
  novoItem.categoria = "Cozinha";
  novoItem.apego_emocional = 20;
  novoItem.dono = "Joao";
  novoItem.nome = "Panela";
  append(lista, novoItem);
  novoItem.id = 3;
  novoItem.categoria = "Eletronicos";
  novoItem.apego_emocional = 90;
  novoItem.dono = "Pedro";
  novoItem.nome = "Celular";
  append(lista, novoItem);
  novoItem.id = 4;
  novoItem.categoria = "Roupas";
  novoItem.apego_emocional = 15;
  novoItem.dono = "Carla";
  novoItem.nome = "Jaqueta";
  append(lista, novoItem);
  novoItem.id = 5;
  novoItem.categoria = "Livros";
  novoItem.apego_emocional = 100;
  novoItem.dono = "Lucas";
  novoItem.nome = "Diario";
  append(lista, novoItem);
  novoItem.id = 6;
  novoItem.categoria = "Moveis";
  novoItem.apego_emocional = 40;
  novoItem.dono = "Ana";
  novoItem.nome = "Cadeira";
  append(lista, novoItem);
  novoItem.id = 7;
  novoItem.categoria = "Decoracao";
  novoItem.apego_emocional = 65;
  novoItem.dono = "Felipe";
  novoItem.nome = "Quadro";
  append(lista, novoItem);
  novoItem.id = 8;
  novoItem.categoria = "Esporte";
  novoItem.apego_emocional = 55;
  novoItem.dono = "Bruno";
  novoItem.nome = "Bola de futebol";
  append(lista, novoItem);
  novoItem.id = 9;
  novoItem.categoria = "Instrumentos";
  novoItem.apego_emocional = 85;
  novoItem.dono = "Mariana";
  novoItem.nome = "Violao";
  append(lista, novoItem);
  novoItem.id = 10;
  novoItem.categoria = "Brinquedos";
  novoItem.apego_emocional = 10;
  novoItem.dono = "Sofia";
  novoItem.nome = "Boneca";
  append(lista, novoItem);
}

void cadastrarSimilaridade()
{
  cout << "Funcionalidade em construcao" << endl;
}

void verificarExistenciaItem()
{
  cout << "Funcionalidade em construcao" << endl;
}

void listarItens(Lista *lista)
{
  mostraItens(lista);
}

void listarItensAlfabeticaNome(Lista* lista)
{
  Lista listaOrdenada = ordenarItens_Nome(lista);
  mostraItens(&listaOrdenada);
}

void listarItensDecrescenteApego(Lista* lista)
{
  Lista listaOrdenada = ordenarItens_Apego(lista);
  mostraItens(&listaOrdenada);
}

void contarItensComMesmaCategoria()
{
  cout << "Funcionalidade em construcao" << endl;
}

void removerMenosApegados()
{
  cout << "Funcionalidade em construcao" << endl;
}

int main()
{
  int opMenu;

  Lista listaDeItens;

  
  /* Menu */
  while (opMenu != 0)
  {

    cin >> opMenu;

    switch (opMenu)
    {

    case 1:
      inserirItem(&listaDeItens);
      break;
    case 2:
      cadastrarSimilaridade();
      break;
    case 3:
      verificarExistenciaItem();
      break;
    case 4:
      listarItens(&listaDeItens);
      break;
    case 5:
      listarItensAlfabeticaNome(&listaDeItens);
      break;
    case 6:
      listarItensDecrescenteApego(&listaDeItens);
      break;
    case 7:
      contarItensComMesmaCategoria();
      break;
    case 8:
      removerMenosApegados();
      break;
    case 9:
      carregarItensDeArquivo(&listaDeItens, "itens.txt");
      break;
    case 0:
      cout << "Ate a proxima!!" << endl;
      break;
    default:
      cout << "Caso de excecao. Selecione uma opcao valida." << endl;
      break;
    }
  }

  return 0;
}