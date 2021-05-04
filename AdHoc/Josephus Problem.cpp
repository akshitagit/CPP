// Tested : Gym 101955K - Let the Flames Begin

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// Complexity : O(min(k log(n), m))
// People 1 to n in a circle, counting starts from 1, every k'th
// people dies, returns the position of the m'th killed people
ll Josephus(ll n, ll k, ll m){
    m = n - m;
    if (k <= 1) return n - m;
    ll i = m;
    while (i < n){
        ll r = (i - m + k - 2) / (k - 1);
        if ((i + r) > n) r = n - i;
        else if (!r) r = 1;
        i += r;
        m = (m + (r * k)) % i;
    }
    return m + 1;
}
