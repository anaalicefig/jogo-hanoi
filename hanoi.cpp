#include <iostream>

using namespace std;

// void renderiza(string[] aneis);
#defina LINHA = 5;
#defina COLUNA = 11;

string aneis[linha][coluna];

int main() 
{    
  string anelGraph;
  int posicao1, posicao2, anelInt;
  bool venceu = false;

  preencheMapa(aneis);
  renderiza(aneis);

  while(!venceu){

    cout << "Peças: O, o, * " << endl;
    cout << "Digite a linha, coluna, e peça que deseja mover: " << endl;
    cin >> posicao1;
    cin >> posicao2;
    cin >> anelGraph;
    anelInt = anelGraphToAnelInt(anelGraph);

    aneis = efetuaJogada(posicao1, posicao2, anelInt);
    renderiza();

    if(verificaVitoria()){
      cout << "PARABÉNS!! VOCÊ VENCEU O JOGO" << endl;
      venceu = true;
    }
  }
}

void renderiza()
{
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 11; j++){            
      cout << "c" << aneis[i][j] << "ɔ";
    }
    cout << endl;
  }  
}

void preencheMapa()
{
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 11; j++){
      if(aneis[i][j].compare(0,0,"O") || aneis[i][j].compare(0,0,"o") || aneis[i][j].compare(0,0,"*")){
        if((j == 2 || j == 5 ||j == 8) && (i != 0 && i != 4))
          aneis[i][j] = "|";        
      }
      aneis[i][j] = "-";
    }
  }

  return aneis; 
}

string efetuaJogada(int posicao1, int posicao2, string aneis[LINHA][COLUNA], int anel)
{
  bool validate = jogadaValidate(posicao, aneis);
  
  if(validate) {
    aneis[posicao1-1][posicao2-1] = anel;
    return aneis;
  } else {
    cout << "JOGADA INVÁLIDA, JOGUE NOVAMENTE" << endl;
    return aneis;
  }
}

void jogadaValidate(int posicao1, int posicao2, , int anel)
{
  if((posicao1 > 5 || posicao1 < 0) || (posicao2 > 11 || posicao2 < 0))
    return false;
  else if(aneis[posicao1][posicao2-1] < anel)
    return false;
    
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 11; j++){    
      if((j != 2 || j != 5 ||j != 8) && (i == 0 && i == 4))
      return false;
    }
  }
  return true;
}

int anelGraphToAnelInt(string anelGraph)
{
  if(anelGraph.compare(0, 0, "O"))
    return 3;
  else if(anelGraph.compare(0, 0, "o"))
    return 2;
  else if(anelGraph.compare(0, 0, "*"))
    return 1;
}

bool verificaVitoria()
{
  if(aneis[3][2].compare(0, 0, "O") || aneis[3][5].compare(0, 0, "o") || aneis[3][8].compare(0, 0, "*")) 
    return true;

  return false;
}