
// The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate span of stock’s price for all n days.
// The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, 
// for which the price of the stock on the current day is less than or equal to its price on the given day.
// For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}

#include<bits/stdc++.h>

int* stockSpan(int *price, int size) {
	// Write your code here
	int *si = new int[size];
    
    stack<int> s;
    
    for(int i = 0; i<size; i++)
    {
        if(s.empty())
        {
            s.push(i);
            si[i] = 1;
        }
        else if(price[i] > price[s.top()])
        {
            while(true)
            {
                if(s.empty())
                {
                    break;
                }
                else
                {
                    if(price[i] > price[s.top()])
                    {
                        s.pop();
                    }
                    else
                    {
                        break;
                    }
                }
            }
            
            if(s.empty())
            {
                si[i] = i+1;
                s.push(i);
            }
            else
            {
                si[i] = i - s.top();
                s.push(i);
            }
        }    
        else if(price[i] <= price[s.top()])
        {	
            
            si[i] = i - s.top();
            s.push(i);
        }
    }
    
    return si;
}