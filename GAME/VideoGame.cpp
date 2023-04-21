#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    long long int n, h, j = 0, k = 0;
    int a[100000], b[100000];
    string str;
    cin >> n >> h;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin.ignore();
    getline(cin, str);
    int x = str.length();
    for (int i = 0; i < x; i++) {
        switch (str[i]) {
        case '1':
            j = max(j - 1, 0);
            break;
        case '2':
            j = min(j + 1, n - 1);
            break;
        case '3':
            if (k == 0 && a[j] > 0) {
                a[j]--;
                k = 1;
            }
            break;
        case '4':
            if (k == 1 && a[j] < h) {
                a[j]++;
                k = 0;
            }
            break;
        case '0':
            goto end;
        }
    }
    end:
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}

