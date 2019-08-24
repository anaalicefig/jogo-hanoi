#include <iostream>
#include <string> 

using namespace std;

#define LINHA 5
#define COLUNA 11

string aneis[LINHA][COLUNA];

void renderiza()
{
  for(int i = 0; i < LINHA; i++){
    for(int j = 0; j < COLUNA; j++){    
      if(aneis[3][2] == "O" && aneis[3][5] == "o" && aneis[3][8] == "*")         
        cout << "c" << aneis[i][j] << "ɔ";

      cout << aneis[i][j];
    }
    cout << endl;
  }  
}

void preencheMapa()
{
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 11; j++){
      if(aneis[i][j] == "O" || aneis[i][j] == "o" || aneis[i][j] == "*"){
        if((j == 2 || j == 5 ||j == 8) && (i != 0 && i != 4))
          aneis[i][j] = "|";        
      }
      aneis[i][j] = "-";
    }
  }
}

bool jogadaValidate(int posicao1, int posicao2, int anel)
{
  int posicao = stoi(aneis[posicao1][posicao2-1]);

  if((posicao1 > 5 || posicao1 < 0) || (posicao2 > 11 || posicao2 < 0))
    return false;
  else if( posicao < anel)
    return false;
    
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 11; j++){    
      if((j != 2 || j != 5 ||j != 8) && (i == 0 && i == 4))
        return false;
    }
  }

  return true;
}

bool efetuaJogada(int posicao1, int posicao2, int anelInt)
{
  bool validate = jogadaValidate(posicao1, posicao2, anelInt);
  cout<< "validade " << validate << endl;
  if(validate) {
    aneis[posicao1-1][posicao2-1] = anelInt;
    return true;
  } else {
    cout << "JOGADA INVÁLIDA, JOGUE NOVAMENTE" << endl;
    return false;
  }
}

int anelGraphToAnelInt(string anelGraph)
{
  if(anelGraph == "O")
    return 3;
  else if(anelGraph == "o")
    return 2;
  else if(anelGraph == "*")
    return 1;
}

bool verificaVitoria()
{
  if(aneis[3][2] == "O" && aneis[3][5] == "o" && aneis[3][8] == "*") 
    return true;

  return false;
}

int main() 
{    
  string anelGraph;
  int posicao1, posicao2, anelInt=0;
  bool venceu = false;

  preencheMapa();
  renderiza();

  while(!venceu){

    cout << "Peças: O, o, * " << endl;
    cout << "Digite a linha, coluna, e peça que deseja mover: " << endl;
    cin >> posicao1;
    cin >> posicao2;
    cin >> anelGraph;

    anelInt = 3;
    
    efetuaJogada(posicao1, posicao2, anelInt);
    renderiza();

    if(verificaVitoria()){
      cout << "PARABÉNS!! VOCÊ VENCEU O JOGO" << endl;
      venceu = true;
    }
  }
}