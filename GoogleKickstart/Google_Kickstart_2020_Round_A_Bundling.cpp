//Kickstart_2020_Round A_D

#include <iostream>
#include <cstdio>
#include <math.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MAX 4001
#define DIV 100000LL
#define INF 2000000000
using namespace std;

int T, n, k;
char str[100001];
typedef struct trie* tlink;
typedef struct trie {
	tlink go[26];
	bool isend;
	bool isparent;
	int cnum;
	int lv;
}trie;

trie* root;

void insert(trie* Root, char* str) {
	if (*str == '\0') Root->isend = true;
	else {
		int num = *str - 'A';
		if (!(Root->go[num])) {
			trie* newT;
			newT = (trie*)malloc(sizeof(trie));
			for (int i = 0; i < 26; i++) newT->go[i] = NULL;
			newT->isend = false;
			newT->isparent = false;
			newT->cnum = 0;
			newT->lv = Root->lv + 1;
			Root->go[num] = newT;
		}
		Root->isparent = true;
		Root->go[num]->cnum++;
		insert(Root->go[num], str + 1);
	}
}

pii solve(trie* Root) {
	if (!Root) return { 0, 0 };
	//if (Root->cnum < k) return { 0, 0 };

	int res = 0, solved = 0;
	for (int i = 0; i < 26; i++) {
		if (!Root->go[i]) continue;
		pii tmp = solve(Root->go[i]);
		solved += tmp.second;
		res += tmp.first;
	}
	Root->cnum -= solved;
	res += (Root->cnum / k)*Root->lv;
	solved += (Root->cnum / k)*k;

	return { res, solved };
}

void del(trie* Root) {
	if (!Root) return;
	if (Root->isparent == false) free(Root);
	else {
		for (int i = 0; i < 26; i++) del(Root->go[i]);
		free(Root);
	}
	return;
}

int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n >> k;
		
		//init root
		root = (trie*)malloc(sizeof(trie));
		for (int i = 0; i < 26; i++) root->go[i] = NULL;
		root->isend = false;
		root->isparent = false;
		root->cnum = 0;
		root->lv = 0;

		//make trie
		for (int i = 0; i < n; i++) {
			cin >> str;
			insert(root, str);
		}
		cout << "Case #" << tc << ": " << solve(root).first << "\n";
		del(root);
	}

	return 0;
}
