#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;
 struct node *prev;
}*end=NULL;
void create(struct node**head,int n)
{
  struct node *newn;
  newn=(struct node*)malloc(sizeof(struct node));
  newn->data=n;
  newn->next=NULL;
  newn->prev=NULL;
  if((*head)==NULL)
  {
    *head=newn;
     end=newn;
  }
 else
  {
    end->next=newn;
    newn->prev=end;
    end=newn;
  }
}
void displayf(struct node *head)
{
    struct node*t;
    t=head;
    while(t!=NULL)
    {
        printf("%d--> ",t->data);
        t=t->next;
    }

}
void displayb( )
{
    struct node*t;
    t=end;
    while(t!=NULL)
    {
        printf("%d--> ",t->data);
        t=t->prev;
    }

}

void insert(struct node**head,int pos,int a)
{
  struct node *newn,*t;
  newn=(struct node*)malloc(sizeof(struct node));
  newn->data=a;
  newn->next=NULL;
  newn->prev=NULL;
  t=*head;
  if(pos==1)
  {
    newn->next=t;
    t->prev=newn;
    *head=newn;
  }
  else
{
  for(int j=1;j<pos-1;j++)
  {
      t=t->next;
  }
  newn->next=t->next;
  newn->prev=t;
  if(t->next)
    {
    t->next->prev=newn;
    t->next=newn;
    }
 else
    {
        t->next=newn;
        end=newn;
    }

}
}
void insertatbegin(struct node**head,int a)
{
  struct node *newn,*t;
  newn=(struct node*)malloc(sizeof(struct node));
  newn->data=a;
  newn->next=NULL;
  newn->prev=NULL;
  t=*head;
    newn->next=t;
    t->prev=newn;
    *head=newn;
}
void insertatend(struct node** prev,int a)
{
  struct node *newn;
  newn=(struct node*)malloc(sizeof(struct node));
  newn->data=a;
  newn->next=NULL;
  newn->prev=NULL;
    newn->prev=end;
    end->next=newn;
    end=newn;
}

void delpos(struct node**head,int i)
{
  struct node*t;
  t=*head;
  if(i==1)
  {
     t->next->prev=NULL;
    *head=(*head)->next;
     free(t);

  }
  else
  {
 for(int j=1;j<=i-1;j++)
     t=t->next;
   t->prev->next=t->next;
   if(t->next)
   t->next->prev=t->prev;
   else
   end=t->prev;
   free(t);
   }

}
void delele(struct node**head,int a)
{
  struct node*t;
  t=*head;


     if(t->data==a && t->prev==NULL)
     {
        t->next->prev=NULL;
       *head=(*head)->next;
        free(t);
     }
    else
    {
      while(t->data!=a)
       t=t->next;
       t->prev->next=t->next;
      if(t->next)
         t->next->prev=t->prev;
      else
       end=t->prev;
       free(t);
    }

}
void rev(struct node**head)
{
    struct node*t,*temp=NULL;
    t=*head;
    end=*head;
    while(t!=NULL)
    {
        temp=t->prev;
        t->prev=t->next;
        t->next=temp;
        t=t->prev;
    }
        if(temp!=NULL)
            *head=temp->prev;


}
int main()
{
   int c,n,f=1,a,i;
   struct node *head=NULL,*end=NULL;
   while(f)
   {
        system("cls");
        int ch=1;
        printf("\nENTER YOUR CHOICE \n(1)ENTER THE DATA\n(2)INSERT AT FIRST POSITION\n(3)INSERT AT LAST POS\n(4)INSERT ELEMENT AT A GIVEN POS\n(5)DELETE AT POSITION\n(6)DELETE THE ELEMENT\n(7)DISPLAY FORWARD\n(8)DISPLAY BACKWARD\n(9)REVERSE THE LINKEDLIST\n(10)EXIT \n:");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                while(ch)
                {
                    system("cls");
                    printf("\nDO YOU WANT TO ADD ELEMENT ? \n(1)YES \n(2)NO\n");
                    scanf("%d",&ch);
                        if(ch==1)
                        {
                            printf("\nENTER THE ELEMENT TO ADD --" );
                            scanf("%d",&n);
                            create(&head,n);
                        }
                        if(ch==2)
                        ch=0;
                }
                    break;
            case 2:
                  printf("\nENTER THE ELEMENT TO INSERT AT BEGINING  :");
                  scanf("%d",&a);
                  insertatbegin(&head,a);
                  break;
            case 3:
                  printf("\nENTER THE ELEMENT TO INSERT AT END :");
                  scanf("%d",&a);
                  insertatend(&head,a);
                  break;
            case 4:
                   printf("\nENTER THE POSITION TO INSERT AND THE ELEMENT :");
                   scanf("%d%d",&i,&a);
                   insert(&head,i,a);
                   break;
           case 5:
                   printf("\nENTER THE POSITION TO DELETE :");
                   scanf("%d",&i);
                   delpos(&head,i);
                   break;
           case 6:
                   printf("\nENTER THE ELEMENT TO DELETE :");
                   scanf("%d",&a);
                   delele(&head,a);
                   break;
           case 7:
                   displayf(head);
                   getch();
                   break;
           case 8:
                   displayb( );
                   getch();
                   break;
           case 9:
                   rev(&head);
                   break;
           case 10:
                f=0;
                break;
         }
    }
return 0;
}

