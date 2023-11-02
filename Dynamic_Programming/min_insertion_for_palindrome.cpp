// A Dynamic Programming based program to find 
// minimum number insertions needed to make a 
// string palindrome 
#include <bits/stdc++.h> 
using namespace std; 


int findMinInsertionsDP(char str[], int n) 
{ 
	int table[n][n], l, h, gap; 

	memset(table, 0, sizeof(table)); 

	for (gap = 1; gap < n; ++gap) 
		for (l = 0, h = gap; h < n; ++l, ++h) 
			table[l][h] = (str[l] == str[h])? 
						table[l + 1][h - 1] : 
						(min(table[l][h - 1], 
							table[l + 1][h]) + 1); 

	return table[0][n - 1]; 
} 
