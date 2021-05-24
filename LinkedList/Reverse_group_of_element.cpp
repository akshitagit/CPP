
//This program will reverse the first k element over than other.
// linked list = 1 2 3 4 5 6 7 8 9 and k=3
// outpur:3 2 1 6 5 4 9 8 7
#include<bits/stdc++.h>
using namespace std;

struct Node
{
 int data;
 struct Node *next;
}*top=NULL;

void push (int x){
	struct Node *t;
	t = new Node;
	if(t==NULL){
		cout<<"Overflow";
	}
	else{
		t->data = x;
		t->next = top;
		top =t;
	}
	
	
}


struct Node *Reverse(struct Node *first, int k){
	stack<Node*> st;
	struct Node*p=first;
	struct Node *prev=NULL;
	while(p){
		int c=0;
		while(p && c<k){
			st.push(p);
			p=p->next;
			c++;
		}
		while(st.size()>0){
			if(prev==NULL){
				prev = st.top();
				first = prev;
				st.pop();
			}
			else{
				prev->next= st.top();
				prev = prev->next;
				st.pop();
			}
		}
	}
	prev->next = NULL;
	return first;
}
void show(struct Node *p){
	while(p){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}


int main(){
	struct Node *first =NULL;
	push(9);push(8);push(7);push(6);push(5);push(4);push(3);push(2);push(1);
		show(top);
		first = Reverse(top, 3);
	show(first);
}
