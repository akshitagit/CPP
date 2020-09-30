#include <iostream>
#include <fstream>
using namespace std;
void getboard(int solved[2]);
bool checkboard(int board[][9]);
bool checkrow(int board[][9]);
bool checkcol(int board[][9]);
bool checkbox(int board[][9]);
int main()
{
	int solved[2] = {0};
	cout << "Welcome please wait while I check your boards...\n";
	getboard(solved);
	cout << "Very good you solved: " << solved[0]+solved[1] << " boards.\n"
		<< solved[1] << " boards were right.\n"
		<< solved[0] << " boards were wrong.\n";
	return 0;
}

void getboard(int solved[2])
{
	ifstream sudokuIn("sudoku_boards.txt");
	while (!sudokuIn.eof())
		int board[9][9];
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				sudokuIn >> board[i][j];
			}
		}
		if (checkboard(board))
			solved[1]++;
		else
			solved[0]++;
	}
}

bool checkboard(int board[9][9])
{ 
	bool solved = false;
	solved = checkrow(board);
	if (solved == false)
		solved = checkcol(board);
	if (solved == false)
		solved = checkbox(board);
	return !solved;
}

bool checkrow(int board[][9])
{
	bool solved = false;
	int row[9];

	for (int x = 0; x < 9; x++) 
		row[x] = 0;

	for (int i = 0; i < 9 && !solved; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			row[board[i][j]-1]++;
		}
		for (int x = 0; x < 9; x++)
		{
			if (row[x] != 1) 
			{
				solved = true;
			}
		}
		for (int x = 0; x < 9; x++)
			row[x] = 0;
	}

	return solved;
}

bool checkcol(int board[][9])
{ 
	bool solved = false;
	int col[9];

	for (int i = 0; i < 9; i++)
		col[i] = 0;

	for (int i = 0; i < 9 && !solved; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			col[board[j][i]-1]++;
		}
		for (int x = 0; x < 9; x++)
		{
			if (col[x] != 1)
			{
				solved = true;
			}
		}
		for (int x = 0; x < 9; x++)
			col[x] = 0;
	}
	return solved;
}

bool checkbox(int board[][9])
{ 
	bool solved = false;
	int box[9][9];

	for (int i = 0; i < 9; i++) 
		for (int j = 0; j < 9; j++)
			box[i][j] = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			box[0][board[i][j]-1]++;
		}
		for (int j = 3; j < 6; j++)
		{
			box[1][board[i][j]-1]++;
		}
		for (int j = 6; j < 9; j++)
		{
			box[2][board[i][j]-1]++;
		}
	}
	for (int i = 3; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			box[3][board[i][j]-1]++;
		}
		for (int j = 3; j < 6; j++)
		{
			box[4][board[i][j]-1]++;
		}
		for (int j = 6; j < 9; j++)
		{
			box[5][board[i][j]-1]++;
		}
	}
	for (int i = 6; i < 9; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			box[6][board[i][j]-1]++;
		}
		for (int j = 3; j < 6; j++)
		{
			box[7][board[i][j]-1]++;
		}
		for (int j = 6; j < 9; j++)
		{
			box[8][board[i][j]-1]++;
		}
	}
	for (int i = 0; i < 9 && !solved; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (box[i][j] != 1)
				solved = true;
		}
	}
	return solved;
}
