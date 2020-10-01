#include<bits/stdc++.h>
using namespace std;

struct node {
    int val;
    struct node *next = NULL;
};

struct node* remove_duplicates(struct node *Head) {

    set<int> s1;
    while (Head) {
        s1.insert(Head->val);
        Head = Head->next;
    }

    struct node *newhead = NULL;
    struct node *prev = NULL;

    // insertion of linked list of n values
    for(int x : s1) {  

        struct node  *tempnode = new node();
         tempnode->val = x;
        if(newhead == nullptr) {
            newhead = tempnode;
            prev = newhead;
        } else {
            prev->next = tempnode;
            prev = tempnode; 
        }
    }
    return newhead;
    
};
int main() {

    int n;
    cin >> n;
    struct node *Head = NULL;
    struct node *prev;

    // insertion or creation of linked list of n values
    while(n--) {
        
        struct node  *tempnode = new node();
        cin >> tempnode->val;
        if(Head == nullptr) {
            Head = tempnode;
            prev = Head;
        } else {
            prev->next = tempnode;
            prev = tempnode;
        }
    }


    struct node *newhead = remove_duplicates(Head);

    while(newhead) {
        cout<< newhead->val << " ";
        newhead = newhead->next;
    }

    return 0;
}