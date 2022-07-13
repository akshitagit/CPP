#include<iostream>
#include<stack>    //using inbuilt stack
#include<string>

using namespace std;

// Function to check the pair of respective bracket character
bool isPair(char opening,char closing)
{
	if(opening == '(' && closing == ')') return true;
	else if(opening == '{' && closing == '}') return true;
	else if(opening == '[' && closing == ']') return true;
	return false;
}

//Function to check whether the bracket combination is balanced
bool CheckBalanced(string exp)
{
	stack<char>  S;
	for(int i =0;i<exp.length();i++)
	{
		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			S.push(exp[i]);
		else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if(S.empty() || !isPair(S.top(),exp[i]))
				return false;
			else
				S.pop();
		}
	}
	return S.empty() ? true:false;
}

int main()
{
	/*Driver Code*/
	string expression;
	cout<<"Enter an expression:  "; // input expression 
	cin>>expression;
	if(CheckBalanced(expression))
		cout<<"Balanced\n";
	else
		cout<<"Not Balanced\n";
}