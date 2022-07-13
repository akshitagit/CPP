//Function to check if a given string is valid parenthesis or not
bool isValid(string s) {
        stack <char> s1;
        int i=0;
        while(s[i]!='\0')
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                s1.push(s[i]);
            }
            else
            {
                if(s[i] == ')')
                {
                    if(!s1.empty() && s1.top()=='(')
                    {
                        s1.pop();
                    }
                    else{
                        break;
                    }
                }
                if(s[i] == ']')
                {
                    if(!s1.empty() && s1.top()=='[')
                    {
                        s1.pop();
                    }
                    else{
                        break;
                    }
                }
                if(s[i] == '}')
                {
                    if(!s1.empty() && s1.top()=='{')
                    {
                        s1.pop();
                    }
                    else{
                        break;
                    }
                }
            }
            i++;
        }
        if(i==s.length() && s1.empty())
            return true;
        else
            return false;
