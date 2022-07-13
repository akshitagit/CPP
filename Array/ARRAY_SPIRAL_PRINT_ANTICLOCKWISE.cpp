// C++ code to traverse a 2D matrix spirally in anticlockwise direction


#include <bits/stdc++.h>
using namespace std;
#define R 100
#define C 100
// function to print the
// required traversal
void Anticlock_pattern(int m,
							int n,
							int arr[R][C])
{
	int i, k = 0, l = 0;

	// k - starting row index
	// m - ending row index
	// l - starting column index
	// n - ending column index
	// i - iterator

	// initialize the count
	int cnt = 0;

	// total number of
	// elements
	int total = m * n;

	while (k < m && l < n)
	{
		if (cnt == total)
			break;

		// the first column
		// from the remaining columns
		for (i = k; i < m; ++i)
		{
			cout << arr[i][l] << " ";
			cnt++;
		}
		l++;

		if (cnt == total)
			break;

		// the last row from
		// the remaining rows
		for (i = l; i < n; ++i)
		{
			cout << arr[m - 1][i] << " ";
			cnt++;
		}
		m--;

		if (cnt == total)
			break;

		//  the last column
		// from the remaining columns
		if (k < m)
		{
			for (i = m - 1; i >= k; --i)
			{
				cout << arr[i][n - 1] << " ";
				cnt++;
			}
			n--;
		}

		if (cnt == total)
			break;

		//  the first row
		// from the remaining rows
		if (l < n)
		{
			for (i = n - 1; i >= l; --i)
			{
				cout << arr[k][i] << " ";
				cnt++;
			}
			k++;
		}
	}
}

// main function
int main()
{
	int arr[R][C];
  cout<<"Enter the number of rows and columns"<<endl;
  int n,m;
  cin>>m>>n;
  cout<<"Enter the array elements"<<endl;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
      cin>>arr[i][j];
  }
  Anticlock_pattern(m,n,arr);
	return 0;
}
