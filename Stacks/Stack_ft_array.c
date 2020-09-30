#include<stdio.h>
#include<stdlib.h>
#define size 10

int top = -1;
int stack[10];

void push(int item){
    if(top == (size -1)){
        printf("\n Warning..!!,Stack Overflown\n");
    }
    else{
        top++;
        stack[top] = item;
    }
}

int pop(){
    int item;
    if(top<0){
        printf("\nWarning..!!,Stack Underflow\n");
        return 0;
    }
    else{
        item = stack[top];
        top--;
        return item;
    }
}

void peek(){
    if(top--<0){
        printf("\nEmpty Stack\n");
    }
    else{
        printf("\nTop Element is Stack is: %d\n",stack[top]);
    }
}

void display(){
    int i = 0;
    printf("\nStack Elements are: \n");
    for(i=0;i<=top;i++){
        printf("%d\t",stack[i]);
    }
}


int main(){
    int n,in;
    
    printf("Menu Driven Program\n\n");
    printf("1 = Push,   2 = Pop,    3 = Peek,   4 = Display,    8 = Exit Program\n\n");
    printf("Enter Appropriate Options: ");
    scanf("%d",&n);
    printf("\n");
    
    while(1){
    switch(n){
        case (1):printf("\nEnter Input Elements for Stack: ");
            scanf("%d",&in);
            push(in);
            break;
        case (2):printf("\nElement Deleted: %d",pop());
            break;
        case (3):peek();
            break;
        case (4):display();
            break;
        case (8):exit(0);
        default:printf("\n\nNo/Incorrect Option Selected");break;
    }
    printf("\nEnter Appropriate Options: ");
    scanf("%d",&n);
    }
}