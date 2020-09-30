/* cpp file
 * Hardik
 * @2020
 * */

#include<bits/stdc++.h>
#define boost ios::sync_with_stdio(false);cin.tie(nullptr)
using namespace std;

/*
Size of array : r
Array : a
search : key
*/
int binary_search(int a[], int r, int key) {

    boost;

    int l = 0;

    while (l <= r) {
        int m = l + (r - l) / 2;
        if (key == a[m])
            return m;

        if (a[m] < key)
            l = m + 1;  
        else
            r = m - 1;
    }
    return -1;
}

int main(int argc, char const* argv[]) {
    int n, key;
    std::cout << "Enter size of array: ";
    std::cin >> n;
    std::cout << "Enter array elements: ";

    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Enter search key: ";
    cin >> key;
    int res = binary_search(a, n - 1, key);
    if (res == -1)
        cout << key << " not found" << endl;
    else
        cout << key << " found at index " << res << endl;
    return 0;
}

/*
Sample Output:

1) 
Enter size of array: 5
Enter array elements: 12 45 85 123 300
Enter search key: 85
85 found at index 2

2)
Enter size of array: 5
Enter array elements: 12 45 85 123 300
Enter search key: 86
86 not found
*/