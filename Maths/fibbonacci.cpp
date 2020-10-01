/*
	Fibbonacci is a series in which each number of the series is the sum of the preceeding two numbers.
    Is algoritm displays the fibbonacci series upto nth term, entered by the user.
*/

#include <iostream>
using namespace std;

int main()
{
    int n1 = 0; 
    int n2 = 1;
    int nextTerm = 0;
    int n;

    cout << "Enter a positive number: ";
    cin >> n;

    // the first two terms which is always 0 and 1
    cout << "The fibonacci Series: " << n1 << ", " << n2 << ", ";

    nextTerm = n1 + n2;

//while loop runs till the new term is lesser than the one entered by the user.
    while(nextTerm <= n)
    {
        cout << nextTerm << ", ";
        n1 = n2;
        n2 = nextTerm;
        nextTerm = n1 + n2;
    };

    return 0;
}