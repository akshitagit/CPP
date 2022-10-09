#include<bits/stdc++.h>
using namespace std;

void firstNonRepeating(string s)
{
  pair<int, int> position[256];   //array of pair type
  for(int i = 0; i < s.length(); i++)   //array: (0, 0),...
  {
    position[s[i]].first++;
    position[s[i]] = i;
  }
  
  int min_index = s.length();
  
  for(int i = 0; i < 256; i++)
  {
    if(position[i].first == 1)
    {
      min_index = min(min_index, position[i].second);
    }
  }
  
  if(min_index == s.length())
    cout << "No non-repeating";
  else
    cout << s[min_index];
}

int main()
{
  string s;
  cin >> s;
  firstNonRepeating(s);
}
