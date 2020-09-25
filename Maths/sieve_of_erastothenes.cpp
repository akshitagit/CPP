/* Sieve of Eratosthenes*/

/*Algorithm to find all digits from 1 to n which are prime:

1.Create a list of all digits from 2 to n which are unmarked initially.
2.For all numbers (m) from 2 to sqrt(n) (where n is unmarked):
	Mark all the numbers which are multiple of m and greater than m^2.
3.Iterate through the list and print all unmarked digits.

*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v;
    int n; //Enter the digit
    cout<<"Enter the value of n:";
	cin>>n;
    if(n<2)
        {
            cout<<"No prime numbers found.";
            return 0;
        }

    for (int a = 0; a <= n; a++)
		v.push_back(1); //Initially unmarking all the digits

	for (int m = 2; m <= sqrt(n); m++) //Iterating from 2 to sqrt(n)
	{
		if (v[m] == 1)
		{
			for (int a = 2; m * a <= n; a++)
				v.at(a*m)= 0; //Marking all digits which are multiple of m and greater than m^2
		}
	}
    cout<<"The prime numbers between 2 and "<< n <<" are: "<<" ";
	for (int i=2;i<=n;i++)
		if (v[i] == 1)
			cout<< i << " ";

}
