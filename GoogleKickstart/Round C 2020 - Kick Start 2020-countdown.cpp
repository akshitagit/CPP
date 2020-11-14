#include<bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDJE
	freopen("input.txt", "r+", stdin);
	freopen("output.txt", "w+", stdout);
#endif
	int i, t, n, p, u, z = 0, k;
	cin >> t;
	for (i = 0; i < t; i++)
	{
		cin >> n;
		int *a = new int[n];
		cin >> p;
		for (int j = 0; j < n; j++)
		{
			cin >> a[j];
		}
		for (int j = 0; j < n; j++)
		{
			if (a[j] == p)
			{
				u = a[j];
				for (k = j; k < n; k++)
				{
					if (a[k] == u)
					{
						if (u == 1)
						{
							z++;
							break;
						}
						u--;
					}
					else
					{
						break;
					}
				}
			}
		}
		cout << "Case #" << i + 1 << ": " << z << "\n";
		z = 0;
	}
}