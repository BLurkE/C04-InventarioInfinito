#include <iostream>
#include "functions.cpp"
using namespace std;

void inserirItem(Lista *lista)
{
    Item novoItem;

    cout << "\nCadastro de Novo Item \n";

    novoItem.id = lista->totalItens;
    cout << "ID atribuido automaticamente: " << novoItem.id << endl;

     cin.ignore(); // limpar buffer caso tenha lixo do último cin

    cout << "Item: ";
    getline(cin, novoItem.nome);

    cout << "Dono: ";
    getline(cin, novoItem.dono);

    cout << "Categoria: ";
    getline(cin, novoItem.categoria);

    cout << "Apego emocional (numero inteiro): ";
    cin >> novoItem.apego_emocional;

    append(lista, novoItem);

    cout << "\nItem cadastrado com sucesso!\n" << endl;
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

    
      cout << endl << "1 - Inserir itens" << endl;
      cout << "2 - Cadatrar similaridade " <<  endl;
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
      cout << endl << "Ate a proxima!!" << endl;
      break;
    default:
      cout << endl << "Caso de excecao. Selecione uma opcao valida." << endl;
      break;
    }
  }

  return 0;
}
