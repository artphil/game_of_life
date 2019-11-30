#include "board.hpp"

// Inicializa um tabuleiro
Board::Board(int _size, bool borderless)
{
	size = _size;
	cell = vector<vector<Cell>>(size);

	for (int x = 0; x < size; x++)
	{
		cell[x] = vector<Cell>(size);
		for (int y = 0; y < size; y++)
			cell[x][y] = Cell();
	}

	if (borderless)
		for (int x = 0; x < size; x++)
			for (int y = 0; y < size; y++)
			{
				int last = size - 1;
				int x_minus = (x == 0) ? last : x - 1;
				int x_plus = (x == last) ? 0 : x + 1;
				int y_minus = (y == 0) ? last : y - 1;
				int y_plus = (y == last) ? 0 : y + 1;

				cell[x][y].neighbours[LEFT] = &cell[x_minus][y];
				cell[x][y].neighbours[RIGTH] = &cell[x_plus][y];
				cell[x][y].neighbours[TOP] = &cell[x][y_minus];
				cell[x][y].neighbours[DOWN] = &cell[x][y_plus];
				cell[x][y].neighbours[TOP_LEFT] = &cell[x_minus][y_minus];
				cell[x][y].neighbours[TOP_RIGTH] = &cell[x_plus][y_minus];
				cell[x][y].neighbours[DOWN_LEFT] = &cell[x_minus][y_plus];
				cell[x][y].neighbours[DOWN_RIGTH] = &cell[x_plus][y_plus];
			}
	else
		for (int x = 0; x < size; x++)
			for (int y = 0; y < size; y++)
			{
				int last = size - 1;
				int x_minus = x - 1;
				int x_plus = x + 1;
				int y_minus = y - 1;
				int y_plus = y + 1;

				if (x > 0)
					cell[x][y].neighbours[LEFT] = &cell[x_minus][y];
				if (x < last)
					cell[x][y].neighbours[RIGTH] = &cell[x_plus][y];
				if (y > 0)
					cell[x][y].neighbours[TOP] = &cell[x][y_minus];
				if (y < last)
					cell[x][y].neighbours[DOWN] = &cell[x][y_plus];
				if (x > 0 && y > 0)
					cell[x][y].neighbours[TOP_LEFT] = &cell[x_minus][y_minus];
				if (x < last && y > 0)
					cell[x][y].neighbours[TOP_RIGTH] = &cell[x_plus][y_minus];
				if (x > 0 && y < last)
					cell[x][y].neighbours[DOWN_LEFT] = &cell[x_minus][y_plus];
				if (x < last && y < last)
					cell[x][y].neighbours[DOWN_RIGTH] = &cell[x_plus][y_plus];
			}
}

void Board::print()
{
	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			cout << cell[x][y].state << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Board::fill(vector<int> x_points, vector<int> y_points)
{
	int n_points = x_points.size();
	for (int p = 0; p < n_points; p++)
	{
		cell[x_points[p]][y_points[p]].state = LIVE;
	}
}

int Board::refresh()
{
	int n_lives = 0;
	for (int x = 0; x < size; x++)
		for (int y = 0; y < size; y++)
			cell[x][y].check_next_state();

	for (int x = 0; x < size; x++)
		for (int y = 0; y < size; y++)
			if (cell[x][y].update() == LIVE)
				n_lives++;

	return n_lives;
}
