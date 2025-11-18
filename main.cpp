// ------------------------- Bibliotecas -------------------------
#include <iostream>
#include <list>
#include "functions.h"
using namespace std;

//--------------------------- Main ---------------------------
int main()
{
  int opMenu = -1;

  list<Item> listaDeItens;
  list<Similaridade> listaDeSimilaridades;

  node_nome * root_nome = NULL; // Raiz da ABB de nomes
  node_raridade * root_raridade = NULL; // Raiz da ABB de raridades

  cout << "///////////////////////////////////////////" << endl;
  cout << "Bem-vindo ao Gerenciador da Mala de Viagem!" << endl;
  cout << "///////////////////////////////////////////" << endl;

  while (opMenu != 0)
  {                    
      cout << endl << "----------------Menu----------------" << endl;
      cout << "1 - Inserir itens" << endl;
      cout << "2 - Cadastrar similaridade entre itens" <<  endl;
      cout << "3 - Buscar itens similares" <<  endl;
      cout << "4 - Verificar existencia de um item" <<  endl;
      cout << "5 - Listar os itens pelo nome, em ordem alfabetica" <<  endl;
      cout << "6 - Listar itens pela raridade, em ordem decrescente" <<  endl;
      cout << "7 - Quantidade de itens da mesma categoria" <<  endl;
      cout << "8 - Remover itens com menor raridade" <<  endl;
      cout << "9 - Carregar lista de itens" <<  endl;
      cout << "0 - Sair" <<  endl;
      cout << "------------------------------------" << endl;
      cout << "****************EXTRAS**************" << endl;
      cout << "11 - Salvar itens em arquivo" <<  endl;
      cout << "12 - Imprimir ABB em ordem crescente de nome" <<  endl;
      cout << "13 - Imprimir ABB em ordem decrescente de raridade" << endl;
      cout << "------------------------------------" << endl << endl;
  
      

      cout << "Escolha uma opcao: ";
      cin >> opMenu; // Lendo a opção do menu

      switch (opMenu)
      {
        //1 - Inserir itens
        case 1:
          inserirItem(listaDeItens, root_nome, root_raridade);
          break;
        //2 - Cadastrar similaridade entre itens
        case 2:
          cadastrarSimilaridade(listaDeSimilaridades, listaDeItens);
          break;
        //3 - Buscar itens similares
        case 3:
          buscarItensSimilares(listaDeSimilaridades, listaDeItens);
          break;
        //4 - Verificar existencia de um item
        case 4:
          verificarExistencia(listaDeItens);
          break;
        //5 - Listar os itens pelo nome, em ordem alfabetica
        case 5:
          listarItensAlfabeticaNome(listaDeItens);
          break;
        //6 - Listar itens pela raridade, em ordem decrescente
        case 6:
          listarItensDecrescenteRaridade(listaDeItens);
          break;
        //7 - Quantidade de itens da mesma categoria
        case 7:
          contarItensComMesmaCategoria(listaDeItens);
          break;
        //8 - Remover itens com menor raridade
        case 8:
          removerMenosRaridade(listaDeItens, root_nome, root_raridade);
          break;
        //9 - Carregar lista de itens
        case 9:
          carregarItensDeArquivo(listaDeItens, "itens.txt", root_nome, root_raridade);
          break;
        // 0 - Sair
        case 0:
          cout << endl << "Ate a proxima!!" << endl;
          break;
        //****************EXTRAS**************
        //11 - Salvar itens em arquivo
        case 11:
          salvarItensEmArquivo(listaDeItens, "itens_salvos.txt");
          break;
        //12 - Imprimir ABB em ordem crescente de nome
        case 12:
          listarItensAbb_Crescente_nome(root_nome);
          break;
        //13 - Imprimir ABB em ordem decrescente de raridade
        case 13:
          listarItensAbb_Decrescente_raridade(root_raridade);
          break;
        // Opcão inválida/não implementada
        default:
          cout << endl << "Opcao invalida." << endl;
          break;
      }
  }

  return 0;
}