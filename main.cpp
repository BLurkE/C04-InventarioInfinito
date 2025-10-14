#include <iostream>
#include <list>
#include "functions.hpp"

using namespace std;

void inserirItem(list<Item> &lista)
{
  insert(lista);
}

void cadastrarSimilaridade(list<Item> &listaItens, list<Similaridade> &listaSimilaridades)
{
  mostraItens(listaItens);

  int ids[2];
  cin >> ids[0] >> ids[1];

  cout << "Funcionalidade de similaridade ainda em desenvolvimento.\n";
}

void verificarExistenciaItem()
{
  cout << "Funcionalidade em construcao" << endl;
}

void listarItens(list<Item> &lista)
{
  mostraItens(lista);
}

void listarItensAlfabeticaNome(list<Item> &lista)
{
  list<Item> listaOrdenada = ordenarItens_Nome(lista);
  mostraItens(listaOrdenada);
}

void listarItensDecrescenteApego(list<Item> &lista)
{
  list<Item> listaOrdenada = ordenarItens_Apego(lista);
  mostraItens(listaOrdenada);
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
  int opMenu = -1;

  list<Item> listaDeItens;
  list<Similaridade> listaDeSimilaridades;

  while (opMenu != 0)
  {
      cout << endl << "1 - Inserir itens" << endl;
      cout << "2 - Cadastrar similaridade " <<  endl;
      cout << "3 - Verificar existencia do item" <<  endl;
      cout << "4 - Listar os itens" <<  endl;
      cout << "5 - Listar os itens em ordem alfabetica" <<  endl;
      cout << "6 - Listar itens apego emocional" <<  endl;
      cout << "7 - Quantidade de itens da mesma categoria" <<  endl;
      cout << "8 - Remover itens com menos apego" <<  endl;
      cout << "9 - Carregar lista de itens" <<  endl;
      cout << "0 - Sair" <<  endl << endl;

      cin >> opMenu;

      switch (opMenu)
      {
        case 1:
          inserirItem(listaDeItens);
          break;
        case 2:
          cadastrarSimilaridade(listaDeItens, listaDeSimilaridades);
          break;
        case 3:
          verificarExistenciaItem();
          break;
        case 4:
          listarItens(listaDeItens);
          break;
        case 5:
          listarItensAlfabeticaNome(listaDeItens);
          break;
        case 6:
          listarItensDecrescenteApego(listaDeItens);
          break;
        case 7:
          contarItensComMesmaCategoria();
          break;
        case 8:
          removerMenosApegados();
          break;
        case 9:
          carregarItensDeArquivo(listaDeItens, "itens.txt");
          break;
        case 0:
          cout << endl << "Ate a proxima!!" << endl;
          break;
        default:
          cout << endl << "Opcao invalida." << endl;
          break;
      }
  }

  return 0;
}