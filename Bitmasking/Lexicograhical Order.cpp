/*
Given a number n, print numbers from 1 to n in dictionary(lexicographical) order.
Sample Input

20

Sample Output

1
10
11
12
13
14
15
16
17
18
19
2
20
3
4
5
6
7
8
9
*/


#include <iostream>
#include <string>
using namespace std;

/*
int csti(string s){
    int ans=0;
    for(int i=0;i<s.size();i++)
        ans=ans*10+(s[i]-48);
    return ans;
}
*/
void help(int x,int n){
    
    if(x>n)
        return;
    for(int i=0;i<=9;i++){
        x=x*10+i;
        if(x==0)
            continue;
        if(x<=n)
            cout<<x<<endl;
        help(x,n);
        x=(x-i)/10;
    }
    
}


void lexicographicalOrder(int num){
	// Write your code here
    int x=0;
    help(x,num);

}

int main() {
    int n;
    cin >> n;
    lexicographicalOrder(n);
}
