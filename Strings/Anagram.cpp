#include <iostream>

using namespace std;
bool anagram(string s1,string s2)
{   int i,count[256]={0};
    if(s1.length()!=s2.length())
        return false;
    for(i=0;s1[i] && s2[i];i++)
    {
        count[s1[i]]++;
        count[s2[i]]--;
    }


    for(i=0;i<256;i++)
    {
        if(count[i]!=0)
            return false;
    }
    return true;
}
int main()
{
    bool b;
    b=anagram("abc","cab");
    cout<<b;
    return 0;
}
