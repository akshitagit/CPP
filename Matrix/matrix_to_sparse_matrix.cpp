#include <bits/stdc++.h>


#define loop(i, n) for (ll i = 0; i < n; ++i)
#define pb push_back
#define ll long long
# define MAX 100

using namespace
std;

int main() {
    int t, m, n;
    std::vector<std::vector<ll> > sp;
    std::vector<ll> row;
    std::vector<ll> temp;
    cin >> t;

    while (t--) {
        cin >> m >> n;
        ll a[m][n];

        ll k = 1;
        temp.pb(m);
        temp.pb(n);
        sp.pb(temp);

        loop(i, m)
            loop(j, n)
                cin >> a[i][j];
        loop(i, m)
            loop(j, n)
                if (a[i][j] != 0) {
                    row.pb(i);
                    row.pb(j);
                    row.pb(a[i][j]);
                    sp.pb(row);
                    row.clear();
                    k++;
                }
        temp.pb(--k);
        sp.at(0) = temp;
        temp.clear();

        loop(i, sp.size()) {
            loop(j, 3)cout << sp.at(i)[j] << " ";
            cout << endl;
        }
        sp.clear();

    }
    return 0;
}
