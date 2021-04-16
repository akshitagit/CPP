#include<stdio.h>
#define MAX 20
typedef struct{
	int top;
	int item[MAX];
	}stack;
void push(stack *, int);
int isFull(stack *);
int pop(stack *s);
int isEmpty(stack *s);
int dequeue(stack *s1, stack *s2);
int main()
{
	stack s1, s2;
	s1.top=-1;
    s2.top=-1;
	int x, ch;
	do{
		printf("0-Quit\n1-Enqueue\n2-Dequeue\nEnter your choice:");
		scanf("%d", &ch	);
		if (ch==1)
		{	printf("Enter the no. to push:");
			scanf("%d", &x);
			push(&s1, x);
		}
		else if (ch==2)
			printf("The popped element is :%d", dequeue(&s1, &s2));
		else
			printf("Invalid choice entered. Enter again.");
	}while (ch != 0);
	return 0;
}
int isFull(stack *s)
{
	if (s->top==MAX-1)
		return 1;
	else 
		return 0;
}
void push (stack *s, int n)
{
	if (isFull(s))
		printf("Stack is Full");
	else
	{
		++s->top;
		s->item[s->top]=n;
	}
}
int isEmpty(stack *s)
{
	if (s->top==-1)
		return 1;
	else
		return 0;
}
int pop(stack *s)
{
	int x;
	if(isEmpty(s))
	{
		printf("Stack is Empty");
		return 1;
	}
	else
	{
		x=s->item[s->top];
		--s->top;
		return x;
	}
}
int dequeue(stack *s1, stack *s2)
{
    if(isEmpty(s1))
    {
        printf("Queue is empty");
        return -1;
    }
    while(s1->top != 0)
        push(s2, pop(s1));
    int temp=pop(s1);
    while (s2->top != -1)
    {
        push(s1, pop(s2));
    }
    return temp;    
}
