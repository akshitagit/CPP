/**
 * #42: https://github.com/akshitagit/JavaScript/issues/42
 * Name: hollowRhombus
 * Author: ngdangtu
 * Standard: c++2a
 * 	g++ hollowRhombus.cpp --std=c++2a
 */
#include <iostream>
#include <string>

#include "headers/Canvas.hpp"
#include "headers/Struct.hpp"

using std::cout;
using std::endl;
using std::stoi;

bool verifyInput(char *[], int);

void ifInputValid(Canvas canvas)
{
	printf(
		"Here is %dx%d diamon shape: ",
		canvas.size.width,
		canvas.size.height);
	cout << endl;
	canvas.draw();
	cout << endl;
}

int main(int argc, char *argv[])
{
	bool isInputValid = verifyInput(argv, argc);
	if (isInputValid)
	{
		Pixel types{'*', ' '};
		CanvasSize size{
			stoi(argv[1]),
			stoi(argv[argc == 2 ? 1 : 2]),
		};
		Canvas canvas{size, types};
		ifInputValid(canvas);
		return 0;
	};

	cout << endl;
	return 1; // Fail to execute
}
