#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
  // Criando um tabuleiro 
  char tabuleiro[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

  int jogador = 1,jogadas = 0;


  // Loop inicial do jogo
  while (true) {
    // Mostrando o tabuleiro atual
    cout << "Jogador " << jogador << ", e sua vez:\n";
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        cout << setw(2) << tabuleiro[i][j];
        if (j < 2) {
          cout << " |";
        }
      }
      cout << endl;
      if (i < 2) {
        cout << "-----------\n";
      }
    }

    // Pedindo ao jogador as coordenadas da jogada
    int linha, coluna;
    cout << "Digite a linha (1--3): ";
    cin >> linha;
    cout << "Digite a coluna (1--3): ";
    cin >> coluna;

    // Vendo  se a jogada é possivel
    if (linha < 1 || linha > 3 || coluna < 1 || coluna > 3) {
      cout << "Coordenadas invalidas! Tente novamente.\n";
      continue;
    }
    //verifica se o espaço ja esta ocupado
    if (tabuleiro[linha-1][coluna-1] != ' ') {
      cout << "Essa posicao já esta ocupada! Tente novamente.\n";
      continue;
    }

    // Fazendo a jogada e vendo se teve um vencedor
    if (jogador == 1) {
      tabuleiro[linha-1][coluna-1] = 'X';
    } else {
      tabuleiro[linha-1][coluna-1] = 'O';
    }
    jogadas++;

    // Vendo o vencedor
    char vencedor = ' ';
    for (int i = 0; i < 3; i++) {
      // Vendo as linhas
      if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ') {
        vencedor = tabuleiro[i][0];
      }
      // Vendo as colunas as colunas
      if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ') {
        vencedor = tabuleiro[0][i];
      }
    }
    // Vendo as diagonais
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ') {
      vencedor = tabuleiro[0][0];
    }
if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ') {
  vencedor = tabuleiro[0][2];
}

// Vendo se teve um vencedor
if (vencedor != ' ') {
  cout << "Jogador " << jogador << " venceu o jogo!\n";
  break;
}

// Vendo se teve empate
if (jogadas == 9) {
  cout << "O jogo empatou!\n";
  break;
}

// Passando a vez para o próximo jogador
jogador = (jogador == 1) ? 2 : 1;
}

return 0;
}
