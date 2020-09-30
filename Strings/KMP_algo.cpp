//Given a text string and a pattern we have to find the number of occurrences of pattern in text string

#include <bits/stdc++.h>
using namespace std;
void computeLPS(string pat, int M, int *lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
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
void KMP(string pat, string txt)
{
    int M = pat.length();
    int N = txt.length();

    int lps[M];

    computeLPS(pat, M, lps);

    int i = 0;
    int j = 0;
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == M)
        {
            cout << "Found pattern at index " << i - j << endl;
            j = lps[j - 1];
        }
        // mismatch after j matches
        else if (i < N && pat[j] != txt[i])
        {
            // if they do not match then lps[0..lps[j-1]] will match anyways
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i = i + 1;
            }
        }
    }
}

int main()
{
    string txt, pat;
    cin >> txt >> pat;
    KMP(pat, txt);
    return 0;
}

/*
Input : ABABDABACDABABCABAB
        ABABCABAB

Output : Found pattern at index 10
*/