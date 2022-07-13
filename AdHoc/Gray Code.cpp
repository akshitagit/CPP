#define ll long long int
ll gray_code(ll x){return x ^ (x >> 1);}
ll inverse_gray_code(ll x){
    ll h = 1, res = 0;
    do{
        if (x & 1) res ^= h;
        x >>= 1, h = (h << 1) + 1;
    } while (x);
    return res;
}
