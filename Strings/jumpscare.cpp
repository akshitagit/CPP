#include <iostream>
#include <ctime>
#include <random>
#include <thread>
#include <chrono>

using namespace std;

int main()
{
	srand(time(0));
	int randSeed = rand() % 4;
	cout << "You've made a mistake..." << endl << endl;
	
	this_thread::sleep_for(chrono::seconds(randSeed + 3));  //wait
	
	cout << "BOO!" << endl; //JUMPSCARE o_0
	return 0;
}