#ifndef __BOARD__
#define __BOARD__

#include <iostream>
#include "cell.hpp"

using namespace std;

class Board
{
	public:
	vector<vector<Cell>> cell; 
	int size;

	// Inicializa um tabuleiro 
	Board(int _size, bool borderless);

	// Verifica o proximo estado da celula e coloca em 'next_state'
	int refresh();

	// Inprime estados no terminal
	void print();

	void fill(vector<int> x_points, vector<int> y_points);

};



#endif
