#include <iostream>
#include <string.h>
#include <windows.h>

using namespace std;

// Rotates the direct of movement to right
void rotateRight(int &x, int &y)
{
	if (x == 1)
	{
		x = 0;
		y = 1;
	}
	else if (y == 1)
	{
		x = -1;
		y = 0;
	}
	else if (x == -1)
	{
		x = 0;
		y = -1;
	}
	else
	{
		x = 1;
		y = 0;
	}
}

int main()
{
	int rows, columns;
	cout << "Enter the number of Rows and Columns: ";
	cin >> rows >> columns;
	rows++;
	columns++;

	bool spiral[rows + 2][columns + 2];
	memset(spiral, false, sizeof spiral);

	// Making the boundaries
	for (int i = 0; i < rows + 2; i++)
		spiral[i][0] = spiral[i][columns + 1] = true;
	for (int i = 0; i < columns + 2; i++)
		spiral[0][i] = spiral[rows + 1][i] = true;

	int x = 1, y = 1, dirX = 1, dirY = 0, lastVertex = 0;
	while (true)
	{
		spiral[y][x] = true;

		// Printing the current state of the matrix
		system("cls");
		for (int i = 1; i <= rows; i++)
		{
			for (int j = 1; j <= columns; j++)
				if (spiral[i][j])
					cout << '*';
				else
					cout << ' ';
			cout << '\n';
		}
		cout << '\n';
		Sleep(10); // Adjustment for the speed of animation

		if (spiral[y + 2 * dirY][x + 2 * dirX])
		{
			if (lastVertex < 2)
				break;
			rotateRight(dirX, dirY);
			lastVertex = 0;
			if (spiral[y + 2 * dirY][x + 2 * dirX])
				break;
		}
		else
		{
			x += dirX;
			y += dirY;
			lastVertex++;
		}
	}
	cout << "\n\n\n";
	system("pause");
	return 0;
}

/*

INPUT: 11 20

OUTPUT:
********************
                   *
 ***************** *
 *               * *
 * ************* * *
 * *           * * *
 * * *********** * *
 * *             * *
 * *************** *
 *                 *
 *******************

*/