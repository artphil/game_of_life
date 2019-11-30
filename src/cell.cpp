#include "cell.hpp"

// Construtor
Cell::Cell()
{
	state = DEAD;
	for (int i = 0; i < N_NEIGHBOURS; i++)
	{
		neighbours[i] = NULL;
	}
	
}

// Verifica se a celula vai estar viva ou morta no proximo ciclo
char Cell::check_next_state()
{
	char i;
	char live_neighbours = 0;

	for(i=0;i<N_NEIGHBOURS;i++)
	{
		if (neighbours[i] == NULL) continue;
		if (neighbours[i]->state == LIVE)
		live_neighbours ++;
	}
	
	if(state==LIVE && live_neighbours < 2) // Morte por isolamento
	{
		next_state = DEAD;
		return DEAD;
	}

	if(state==LIVE && live_neighbours > 3) // Morte por superlotacao
	{
		next_state = DEAD;
		return DEAD;
	}

	if(state==DEAD && live_neighbours == 3) // Nasce 
	{
		next_state = LIVE;
		return LIVE;
	}	

	next_state = state;
	return state;
}

#include <iostream>
// Atualiza o estado da celula
char Cell::update()
{
	state = next_state;
	// std::cout << (int)state << " ";

	return state;
}