#include <bits/stdc++.h>
using namespace std;

int M, N, R, C;
vector <string> g, pat;
bool present(int x, int y) {
    for(int i = 0; i < (int)R; ++i) {
        for(int j = 0; j < (int)C; ++j) {
            int ii = i + x, jj = j + y;
            if(ii >= M || jj >= N)
                return false;
            else if(g[ii][jj] != pat[i][j])
                return false;
            else
                continue;
        }
    }
    return true;
}

int main()
{
int t;
cin >> t;
assert(t >= 1 && t <= 5);

while(t--) {
    cin >> M >> N;
    g = vector <string> (M);
    for(int i = 0; i < (int)M; ++i) {
        cin >> g[i];
    }

    cin >> R >> C;
    pat = vector <string>(R);
    for(int i = 0; i < (int)R; ++i) {
        cin >> pat[i];
    }

    bool isPresent = false;

    for(int i = 0; i < (int)M; ++i) {
        for(int j = 0; j < (int)N; ++j) {
            isPresent = present(i, j);
            if(isPresent)
                break;
        }
        if(isPresent)
            break;
    }

    cout << (isPresent? "YES" : "NO")<<"\n";
}

return 0;

}