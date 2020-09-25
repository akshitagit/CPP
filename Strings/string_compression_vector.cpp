#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str, res = "";
    cin >> str;
    map<char, int> m;
    for (int i = 0; i < str.length(); i++)
    {
        m[str[i]]++;
    }
    for (auto it = m.begin(); it != m.end(); it++)
    {
        res.push_back(it->first);
        char c = '0' + it->second;
        res.push_back(c);
    }
    cout << res << "\n";
    return 0;
}
