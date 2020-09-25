 
 #include <iostream>
using namespace std;

int main()
{

    cout << "Enter a number for printing Diamond Pattern:";
    int size;
    cin >> size;
    int num = 1;
  for (int i = 1; i <= size; i++) {
            for (int j = 1; j <=  2*(size - i); j++) {
                cout <<" ";
            }
            for (int j = 1; j <= 2*i - 1; j++) {
                cout <<"*"<<" ";
            }
            cout <<endl;
        }
        for (int i = 1; i <= size - 1; i++) {
            for (int j = 1; j <= 2*i; j++) {
                cout <<" ";
            }
            for (int j = 1; j <= 2*(size - i) - 1; j++) {
                cout <<"*"<<" ";
            }
            cout <<endl;
        }
}