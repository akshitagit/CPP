#include<iostream>
using namespace std;

class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
node* arrange_LinkedList(node* head)
{
    
  node*oh=NULL;
  node*ot=NULL;
  node*eh=NULL;
  node*et=NULL;
  while(head!=NULL)
  {
    if((head->data)%2!=0)
    {
      if(oh==NULL)
      {
        oh=head;
        ot=head;
      }
      else
      { ot->next=head;
        ot=head;
    }
    }
    else
    {
      if(eh==NULL)
      {
        eh=head;
        et=head;
      }
      else
      {
        et->next=head;
        et=head;
      }
    }
    head=head->next;
  }
 
  if(oh==NULL)
  {  et=NULL;
    return eh;
  }
  if(eh==NULL)
  {
    ot=NULL;
    return oh;
  }
  et=NULL;
  ot->next=eh;
  return oh;

}

node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    node*head=takeinput();
    head=arrange_LinkedList(head);
    print(head);
    return 0;
}
