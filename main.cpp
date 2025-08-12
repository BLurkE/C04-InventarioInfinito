#include <iostream>
using namespace std;

void inserirItem(){
  cout << "Funcionalidade em construção" << endl;
}

void cadastrarSimilaridade(){
  cout << "Funcionalidade em construção" << endl;
}

void verificarExistenciaItem(){
  cout << "Funcionalidade em construção" << endl;
}

void listarItens(){
  cout << "Funcionalidade em construção" << endl;
}

void listarItensAlfabeticaNome(){
  cout << "Funcionalidade em construção" << endl;
}

void listarItensDecrescenteRaridade(){
  cout << "Funcionalidade em construção" << endl;
}

void contarItensPropMagica(){
  cout << "Funcionalidade em construção" << endl;
}

void removerMenosRaros(){
  cout << "Funcionalidade em construção" << endl;
}

int main() {
  int opMenu;


  cin >> opMenu;
  /* Menu */
  switch (opMenu){

    case 1:
      inserirItem();
    case 2:
      cadastrarSimilaridade();
    case 3:
      verificarExistenciaItem();
    case 4:
      listarItens();
    case 5:
      listarItensAlfabeticaNome();
    case 6:
      listarItensDecrescenteRaridade();
    case 7:
      contarItensPropMagica();
    case 8:
      removerMenosRaros();
    default:
      cout << "Caso de exceção. Selecione uma opção válida." << endl;
  }


  return 0;
}