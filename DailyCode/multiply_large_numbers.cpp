#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b, ans, row;
    char digit;
    int x,y,z,prod,carry=0, carrySum=0, m, decimal=0;
    cout<<"Enter first number:";
    cin>>a;
    cout<<"Enter second number:";
    cin>>b;
    if(a=="0" || b=="0")
    {
        cout<<0<<endl;
        return 0;
    }
    for(int i=0; i<a.length(); ++i)
    {
        if(a[i] == '.')
        {
            decimal += a.length()-1-i;
            a.erase(a.begin()+i);
        }
    }
    for(int i=0; i<b.length(); ++i)
    {
        if(b[i] == '.')
        {
            decimal += b.length()-1-i;
            b.erase(b.begin()+i);
        }
    }
    for(int i=a.length()-1; i>=0; --i)
    {
        row="";
        x=a[i]-'0';
        for(int j=b.length()-1; j>=0; --j)
        {
            y = b[j]-'0';
            prod = x*y+carry;
            carry = prod/10;
            prod = prod % 10;
            digit = prod+'0';
            row += digit;
        }
        // cout<<row<<endl;
        if(carry)
        {
            // cout<<"carry="<<carry;
            digit = carry+'0';
            row += digit;
            carry = 0;
        }
        // cout<<"i="<<i<<"a="<<a.length()<<endl;
        for(int j=0; j<a.length()-1-i; ++j)
        { 
            row.insert(0,"0");
            // cout<<row<<endl;
        }
        // cout<<row<<endl;
        if(ans.empty())
        {
            ans=row;
            // cout<<"here";
        }
        else
        {
            m=min(row.length(), ans.length());
            for(int j=0; j<m; ++j)
            {
                y = row[j]-'0'+carrySum+ans[j]-'0';
                // cout<<"y="<<y<<endl;
                carrySum = y/10;
                y=y%10;
                digit = y+'0';
                ans[j] = digit;
                // cout<<"ans[j]"<<ans[j]<<endl;
            }
            // cout<<"ans="<<ans<<endl;
            if(m == ans.length())
            {
                for(int j=m; j<row.length(); ++j)
                {
                    y = carrySum + row[j]-'0';
                    carrySum = y/10;
                    y = y%10;
                    digit = y+'0';
                    ans+=digit;
                    // cout<<"ans="<<ans<<endl;
                }
            }
            if(carrySum)
            {
                digit=carrySum+'0';
                ans+=digit;
            }
        }
        // cout<<row<<' '<<ans<<endl;
    }
    // cout<<decimal<<endl;
    if(decimal != 0)
        ans.insert(decimal, ".");
    reverse(ans.begin(), ans.end());
    cout<<ans<<endl;
}