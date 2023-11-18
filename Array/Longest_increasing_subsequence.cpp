#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lis(vector<int> &arr)
{
    int n = arr.size();
    vector<int> lisLength(n, 1);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && lisLength[i] < lisLength[j] + 1)
            {
                lisLength[i] = lisLength[j] + 1;
            }
        }
    }

    return *max_element(lisLength.begin(), lisLength.end());
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int result = lis(arr);

    cout << result << endl;

    return 0;
}
