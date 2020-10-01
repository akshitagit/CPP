#include <iostream>
using namespace std;

int main()
{
        int size=1;
        int num = 1;
        cout << "Enter a number for printing Diamond Pattern:";
        cin >> size;
        //For prining top
        for (int row = 1; row <= size; row++) {
            for (int column = 1; column <=  2*(size - row); column++) {
                cout <<" ";
            }
            for (int column = 1; column <= 2*row - 1; column++) {
                cout <<"*"<<" ";
            }
            cout <<endl;
        }
        //for printing bottom
        for (int row = 1; row <= size - 1; row++) {
            for (int column = 1; column <= 2*row; column++) {
                cout <<" ";
            }
            for (int column = 1; column <= 2*(size - row) - 1; column++) {
                cout <<"*"<<" ";
            }
            cout <<endl;
        }
}
