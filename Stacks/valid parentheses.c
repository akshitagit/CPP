//Name-Nishikanta Ray

#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int top;
char pop(char s[ ])
{
	char c;
	if(top==-1)
	{
		printf("STACK UNDERFLOW\n");
		exit(0);
	}
	return s[top--];
}
void push(char s[ ],char e)
{
	if(top==SIZE-1)
	{
		printf("STACK OVERFLOW\n");
		exit(0);
	}
	s[++top]=e;
}
int check(char str[ ])
{
	int flag=1,i;
	char s[SIZE],t;
	for(i=0;str[i]!='\0'&&flag==1;i++)
		if(str[i]=='('||str[i]=='{'||str[i]=='[')
			push(s,str[i]);
		else if(str[i]==')'||str[i]=='}'||str[i]==']')
			if(top==-1)
			{
				printf("Less no of left %c\n",str[i]);
				flag=0;
			}
			else
			{
				t=pop(s);
				if((str[i]==')'&&(t=='['||t=='{'))||(str[i]=='}'&&(t=='('||t=='['))||(str[i]==']'&&(t=='('||t=='{')))
				{
					printf("Mismatch of brackets\n");
					flag=0;
				}
			}
	if(top!=-1&&flag==1)
	{
		printf("More no. of left %c\n",str[top]);
		flag=0;
	}
	return flag;
}
main()
{
	top=-1;
	char s[SIZE],str[SIZE],i;
	printf("Enter the string: ");
	scanf("%s",str);
	if(check(str))
		printf("CORRECT NO. OF BRACKETS\n");
	else
		printf("INVALID EXPRESSION\n");
}
