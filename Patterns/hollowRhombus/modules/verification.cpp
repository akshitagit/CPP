#include <iostream>
#include <string>

#include "../headers/Struct.hpp"

using std::string;

// TOFIX this is not strict enough 2nd case
bool isOddInLimRange(string input, Range lim)
{
	int number = std::stoi(input);
	bool isOdd = (number % 2) > 0;
	bool isInLimRange = (number >= lim.min) && (number <= lim.max);
	return isOdd && isInLimRange;
}

bool verifyInput(char *inputArray[], int inSize)
{
	Range limRange{0, 15};
	bool limitedOdd = isOddInLimRange(inputArray[1], limRange);
	if (inSize == 1 || inSize > 3)
	{
		printf("This program requires 1 - 2 numeric input(s) to excute.");
		return false;
	}
	else if (!limitedOdd)
	{
		printf("Please enter (an) odd number(s) in range from %d to %d.", limRange.min, limRange.max);
		return false;
	}
	return true;
}