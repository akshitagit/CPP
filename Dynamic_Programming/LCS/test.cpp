#include <bits/stdc++.h> 
using namespace std; 

#define MAXN 1000 

struct Node 
{ 
	int start, end; 
	int length; 
	int insertionEdge[26]; 
	int suffixEdge; 
}; 

Node root1, root2; 
Node tree[MAXN]; 
int currNode; 
string s; 
int ptr; 

void insert(int currIndex) 
{ 
	int temp = currNode; 
	while (true) 
	{ 
		int currLength = tree[temp].length; 
		if (currIndex - currLength >= 1 && (s[currIndex] == s[currIndex -currLength - 1])) break; 
		temp = tree[temp].suffixEdge; 
	} 

	if (tree[temp].insertionEdge[s[currIndex] - 'a'] != 0) 
	{ 
		currNode = 
		tree[temp].insertionEdge[s[currIndex] - 'a']; 

		return; 
	} 

	ptr++; 

	tree[temp].insertionEdge[s[currIndex] - 'a'] = ptr; 
	tree[ptr].end = currIndex; 
	tree[ptr].length = tree[temp].length + 2; 
	tree[ptr].start = tree[ptr].end - tree[ptr].length + 1; 

	currNode = ptr; 
	temp = tree[temp].suffixEdge; 

	if (tree[currNode].length == 1) { 
		tree[currNode].suffixEdge = 2; 
		return; 
	} 

	while (true) { 
		int currLength = tree[temp].length; 

		if (currIndex - currLength >= 1 && 
			(s[currIndex] == 
			s[currIndex - currLength - 1])) 
				break; 

		temp = tree[temp].suffixEdge; 
	} 

	tree[currNode].suffixEdge = tree[temp].insertionEdge[s[currIndex] - 'a']; 
} 

// Driver code 
int main() 
{ 

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	root1.length = -1; 
	root1.suffixEdge = 1; 

	root2.length = 0; 
	root2.suffixEdge = 1; 

	tree[1] = root1; 
	tree[2] = root2; 

	ptr = 2; 
	currNode = 1; 
	s = "forgeeksskeegfor"; 
	for (int i = 0; i < s.size(); i++) insert(i); 

	int last = ptr; 

	for (int i = tree[last].start; i <= tree[last].end; i++) cout << s[i]; 

	return 0; 
} 
