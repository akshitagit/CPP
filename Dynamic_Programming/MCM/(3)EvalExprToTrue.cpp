#include<bits/stdc++.h>
using namespace std;

// Evaluate expression to true / boolean parenthesization
// Find number of ways to make this expression true

int solve(string s, int i, int j, bool isTrue) {

	if (i > j) return 0; // empty string is not true

	if (i == j) {
		if (isTrue == true) return s[i] == 'T';
		else return s[i] == 'F';
	}

	int ans = 0;
	for (int k = i + 1; k <= j - 1; k += 2) {

		int lT = solve(s, i, k - 1, true);
		int lF = solve(s, i, k - 1, false);
		int rT = solve(s, k + 1, j, true);
		int rF = solve(s, k + 1, j, false);

		if (s[k] == '&') {
			if (isTrue == true) ans += lT * rT;
			else ans += lF * rF + lF * rT + lT * rF;
		}
		else if (s[k] == '|') {
			if (isTrue == true) ans += lT * rT + lF * rT + lT * rF;
			else ans += lF * rF;
		}
		else if (s[k] == '^') {
			if (isTrue == true) ans += lT * rF + lF * rT;
			else ans += lF * rF + lT * rT;
		}

	}
	return ans;
}

unordered_map<string, int> mp;

int solve_mem(string s, int i, int j, bool isTrue) {

	if (i > j) return 0; // empty string is not true

	if (i == j) {
		if (isTrue == true) return s[i] == 'T';
		else return s[i] == 'F';
	}

	string temp = to_string(i);
	temp += " ";
	temp += to_string(j);
	temp += " ";
	temp += to_string(isTrue);
	int ans = 0;

	if (mp.find(temp) != mp.end()) {
		return mp[temp];
	}

	else {

		for (int k = i + 1; k <= j - 1; k += 2) {

			int lT = solve(s, i, k - 1, true);
			int lF = solve(s, i, k - 1, false);
			int rT = solve(s, k + 1, j, true);
			int rF = solve(s, k + 1, j, false);

			if (s[k] == '&') {
				if (isTrue == true) ans += lT * rT;
				else ans += lF * rF + lF * rT + lT * rF;
			}
			else if (s[k] == '|') {
				if (isTrue == true) ans += lT * rT + lF * rT + lT * rF;
				else ans += lF * rF;
			}
			else if (s[k] == '^') {
				if (isTrue == true) ans += lT * rF + lF * rT;
				else ans += lF * rF + lT * rT;
			}

		}
	}

	return mp[temp] = ans;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s = "T^F&T|T";
	cout << solve(s, 0, s.length() - 1, true) << endl;

	mp.clear(); // like dp to -1
	cout << solve_mem(s, 0, s.length() - 1, true) << endl;
}
