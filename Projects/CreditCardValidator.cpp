// program for checking the credit card validation
/* requirements 
credit card must have these things
13 to 16 digits 
start with the 4, 5, 37, 6
luhn's algorithm -> sum of all the double of even places 
and sum of all the odd places 
modulo of the sum of both of them must have been 0 
*/
#include <iostream>
#include<cmath>
#include<string>
using namespace std;


/*if we pass single digit to it, it will simply return that number,
if we pass double digit number to it then it will add both of 
the digit of that numebr and return that number 
*/
int getDigit(int d)
{
    if(d>9)
    {
        return (d/10+d%10);

    }
    return d;
}


/*this funtion is going to return the total number of digits in number
*/
int getSize(long long int number)
{
    string num = to_string(number);
    return num.length();
}


/* it is going to return the k numbers from starting 
*/
int getPrefix(long long int number,int k)
{
    string num = to_string(number);
    return stol(num.substr(0,k));
}


/*
this function is used to return the true if we get 
*/
bool getMatched(long long int number,int d)
{
    return getPrefix(number,getSize(d))==d;       
}


int sumOfDoubleEvenPlace(long long int number)
{
    string num = to_string(number);
    int sum=0;

    for(int i=getSize(number)-2; i>=0; i-=2)
    {
        sum+=getDigit(int(num[i]-'0')*2);
    }
    return sum;
}


int sumOfOddPlace(long long int number)
{
    string num = to_string(number);
    int sum=0;
    for(int i=getSize(number)-1; i>=0; i-=2)
    {
        sum += int(num[i]-'0');
    }
    return sum;
}


//if it is the valid credit card number then going to return 
//true 
bool isValid(long long int number)
{
    return getSize(number)>=13 && getSize(number)<=16 &&
    getMatched(number, 5) ||
    getMatched(number, 4) ||
    getMatched(number, 37) ||
    getMatched(number, 6) && 
    (sumOfDoubleEvenPlace(number)+sumOfOddPlace(number)%10==0);

}


int main()
{
    cout<<getDigit(24)<<endl;
    cout<<getSize(1234567890)<<endl;
    cout<<getPrefix(1234567890,3)<<endl;
    cout<<getMatched(1234567890,1234)<<endl;
    cout<<sumOfDoubleEvenPlace(1212121212)<<endl;
    cout<<sumOfOddPlace(1212121212)<<endl;
    cout<<isValid(5425233430109903)<<endl;
    cout<<isValid(4263982640269299);

    return 0;
}
