#include "board.hpp"

int main(int argc, char const *argv[])
{
	if (argc <= 1)
	{
		cout << "Sem argumentos" << endl;
		return -1;
	}

	srand(time(NULL));

	int my_size = atoi(argv[1]);
	bool borderless = false;

	Board my_board(my_size, borderless);

	vector<int> x_list(my_size);
	vector<int> y_list(my_size);
	// for (char i = 0; i < 256; i++)
	// 	cout << i << " ";
	// cout << endl;

	for (int i = 0; i < my_size; i++)
	{
		int x = rand() % my_size;
		int y = rand() % my_size;
		x_list[i] = x;
		y_list[i] = y;
	}

	my_board.fill(x_list, y_list);
	my_board.print();

	int live_cells = 1;
	while (live_cells)
	{
		live_cells = my_board.refresh();
		my_board.print();

		getchar();
	}

	return 0;
}
