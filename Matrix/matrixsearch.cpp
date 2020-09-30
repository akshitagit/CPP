#include <bits/stdc++.h>

#define inp(x) scanf("%d", &x)
#define loop(i, n) for (ll i = 0; i < n; ++i)
#define pb push_back
#define mp make_pair
#define ll long long

using namespace std;

int main()
{
    int t, m, n;
    cin >> t;

    while (t--)
    {
        cin >> m >> n;
        int a[m][n];
        loop(i, m)
                loop(j, n)
                    cin >>
            a[i][j];
        //Start at bottom left
        int key, x = m - 1, y = 0;
        cin >> key;

        while (x >= 0 && y < n)
        {
            if (a[x][y] == key)
            {
                cout << 1 << endl;
                goto end;
            }
            (a[x][y] < key) ? (y++) : (x--);
        }
        cout << 0 << endl;
    end:;
    }
    return 0;
}
