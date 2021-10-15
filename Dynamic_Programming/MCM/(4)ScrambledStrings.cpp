#include<bits/stdc++.h>
using namespace std;

// Scrambled Strings - OP true/false

bool solve(string s1, string s2) {

	if (s1.compare(s2) == 0) return true; // identical strings
	if (s1.length() <= 1) return false; // as per rule given

	int n = s1.length();
	bool flag = false;

	for (int i = 1; i <= n - 1; i++) {

		// swap
		bool cond1 = ( solve(s1.substr(0, i), s2.substr(n - i, i)) == true ) &&
		             ( solve(s1.substr(i, n - i), s2.substr(0, n - i)) == true );

		//no swap
		bool cond2 = ( solve(s1.substr(0, i), s2.substr(0, i)) == true ) &&
		             ( solve(s1.substr(i, n - i), s2.substr(i, n - i)) == true );

		if (cond1 || cond2) {
			flag = true;
			break;
		}

	}
	return flag;
}

unordered_map<string, bool> mp;

bool solve_mem(string s1, string s2) {

	if (s1.compare(s2) == 0) return true; // identical strings
	if (s1.length() <= 1) return false; // as per rule given

	int n = s1.length();
	bool flag = false;

	string temp = s1;
	temp += " ";
	temp += s2;
	temp += " ";

	if (mp.find(temp) != mp.end()) return mp[temp];

	else {
		for (int i = 1; i <= n - 1; i++) {

			// swap
			bool cond1 = ( solve(s1.substr(0, i), s2.substr(n - i, i)) == true ) &&
			             ( solve(s1.substr(i, n - i), s2.substr(0, n - i)) == true );

			//no swap
			bool cond2 = ( solve(s1.substr(0, i), s2.substr(0, i)) == true ) &&
			             ( solve(s1.substr(i, n - i), s2.substr(i, n - i)) == true );

			if (cond1 || cond2) {
				flag = true;
				break;
			}

		}
	}
	return mp[temp] = flag;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s1 = "great";
	string s2 = "rgeat";

	if (s1.length() != s2.length()) cout << "0" << endl;
	// if both empty strings cout 1
	else cout << solve(s1, s2) << endl;

	mp.clear();
	cout << solve_mem(s1, s2) << endl;

}
