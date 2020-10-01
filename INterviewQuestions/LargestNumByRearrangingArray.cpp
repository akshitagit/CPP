#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> 
using namespace std; 
  
int myCompare(string a, string b) 
{ 
    string A = a.append(b); 
    string B = b.append(a); 
  
    if(A.compare(B) > 0) 
        return 1;
    return 0; 
} 
 
void printLargest(vector<string> arr) 
{ 
    sort(arr.begin(), arr.end(), myCompare); 
  
    for (int i=0; i < arr.size() ; i++ ) 
        cout << arr[i]; 
} 
  
 
int main() 
{ 
    vector<string> arr; 
  
    arr.push_back("54"); 
    arr.push_back("446"); 
    arr.push_back("948"); 
    arr.push_back("0"); 
    printLargest(arr); 
  
   return 0; 
} 
