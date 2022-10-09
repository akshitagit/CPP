#include<bits/stdc++.h>
using namespace std;

void findFirstRepeating(string s)
{
  int position[256];
  for(int i = 0; i < 256; i++)
    count[i] = -1;
  
  min_index = s.length();
  
  for(int i = 0; i < s.length(); i++)
  {
    if(position[s[i]] == -1)
      position[s[i]] = 1;
    else
    {
      if(position[s[i]] < min_index)
        min_index = position[s[i]];
    }
  }
  
  if(min_index == s.length())
    cout << "Non Repeating";
  else
    cout << s[min_ind];
}
    
int main()
{
  string s;
  cin >> s;
  findFirstRepeating(s);
}
