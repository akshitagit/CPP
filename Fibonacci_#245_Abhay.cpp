#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fastIO {ios_base::sync_with_stdio(false); cin.tie(NULL);}

ll fibonacci(int n){
	double phi = pow((1+sqrt(5))/2, n) - pow((1-sqrt(5))/2, n);
	return round(phi/sqrt(5));
}

int main(){
	fastIO
	int n;
	
	cin >> n;
	cout << fibonacci(n) << endl;

	return 0;
}
