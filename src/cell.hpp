#ifndef __CELL__
#define __CELL__

#include <vector>

#define N_NEIGHBOURS 8

#define LEFT 0
#define RIGTH 1
#define TOP 2
#define DOWN 3
#define TOP_LEFT 4
#define TOP_RIGTH 5
#define DOWN_LEFT 6
#define DOWN_RIGTH 7

#define LIVE '#'
#define DEAD '.'


class Cell
{
	private:
	char next_state; // Proximo estado
	
	public:
	Cell* neighbours[N_NEIGHBOURS]; // Lista de vizinhos
	char state; // Estado atual: 1 -> vivo, 0 -> morto
	
	// Construtor
	Cell();

	// Verifica o proximo estado da celula e coloca em 'next_state'
	char check_next_state();

	// Atualiza o estado da celula
	char update();
};


#endif
