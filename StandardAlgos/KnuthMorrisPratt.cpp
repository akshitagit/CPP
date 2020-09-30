#include <iostream>
#include <vector>
#include <string>
using namespace std;
void computeLPS(string &patt, vector<int> &lps)
{
    int M = patt.size();
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M)
    {
        if (patt[i] == patt[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void searchByKMP(string &text, string &patt)
{
    int N = text.size(), M = patt.size();
    vector<int> lps(M);
    computeLPS(patt, lps);
    int i = 0, j = 0;
    while (i < N)
    {
        if (patt[j] == text[i])
        {
            i++;
            j++;
        }
        if (j == M)
        {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        }
        else if (i < N && patt[j] != text[i])
        {
            if (j == 0)
                i++;
            else
                j = lps[j - 1];
        }
    }
}

int main()
{
    string text = "", patt = "";
    int n;
    cout << "Enter number of test cases: ";
    cin >> n;
    while (n)
    {
        cout << "Enter the text string: ";
        cin >> text;
        cout << "Enter the pattern string: ";
        cin >> patt;
        searchByKMP(text, patt);
        n--;
        text.clear();
        patt.clear();
    }
    return 0;
}