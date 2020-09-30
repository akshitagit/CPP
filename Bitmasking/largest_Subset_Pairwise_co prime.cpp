#include <bits/stdc++.h> 
using namespace std; 

int lengthlargestsubset(int a[], int n) 
{ 
	int answer = 0; 

	for (int i = 1; i < (1 << n); i++) {   // iterating through all the subset generated through bitmasking
		vector<int> subset; 
		//checking if the jth bit is 1
		for (int j = 0; j < n; j++) { 
			if (i & (1 << j)) 
				subset.push_back(a[j]); // including element into the subset
		} 
		bool f = true; 
		// checking pairwise if they are coprimes.
		for (int j = 0; j < subset.size(); j++) { 
			for (int k = j + 1; k < subset.size(); k++) {  
				if (__gcd(subset[j], subset[k]) != 1)// Check if the gcd is not equal to 1 
					f = false; 
			} 
		} 

		if (f == true) 
			answer = max(answer, (int)subset.size()); //updating maximum size of the subset
	}  
	return answer; // return answer
} 

// main code segment
int main() 
{ 
	int n;
	cout<<"enter the size of the set: ";
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cout<<"enter element "<<i+1<<": ";
		cin>>arr[i];
	}
	cout << lengthlargestsubset(arr, n); 

	return 0; 
} 