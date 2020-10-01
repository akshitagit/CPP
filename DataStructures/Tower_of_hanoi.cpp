
#include <iostream>
using namespace std;
void hanoi(int n,char src,char help,char dest)
{
    if(n==0)
    {
        return ;
    }
    
    
        hanoi(n-1,src,dest,help);
        cout<<"Moving ring "<<n<<" from "<<src<<" to "<<dest<<endl;
        hanoi(n-1,help,src,dest);
}
int main(int argc, char **argv)
{
	int n;
    cin>>n;
    hanoi(n,'A','C','B');
	return 0;
}
