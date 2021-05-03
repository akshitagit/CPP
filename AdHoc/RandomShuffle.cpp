mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<int> permutation(N);
shuffle(permutation.begin(), permutation.end(), rng);
