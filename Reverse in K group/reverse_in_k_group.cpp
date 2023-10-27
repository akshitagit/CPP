#include<bits/stdc++.h>
using namespace std;
class ListNode{
public:
    int val;
    ListNode *next;
    ListNode(int data = 0, ListNode *next_node = NULL){
        val = data;
        next = next_node;
    }
};
ListNode* reverseKGroup(ListNode* head, int k) {
    if(k == 0)return head;
    ListNode *cur = head, *prev = NULL;
    while(cur != NULL){
        int num_of_node_passed = 0;
        ListNode *temp1 = prev; // tail of previous group
        ListNode *temp2 = cur; //will become the tail of current group after reversing the group
        num_of_node_passed = 0;
        ListNode *temp = cur;
        while(temp != NULL && num_of_node_passed < k){
            num_of_node_passed++;
            temp = temp->next;
        }
        if(num_of_node_passed < k)break; // Not enough node to make a group
        num_of_node_passed = 0;
        while(cur != NULL && num_of_node_passed < k){
            ListNode *next_node = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next_node;
            num_of_node_passed++;
        }
        if(temp1 != NULL){
            temp1->next = prev;
        }
        else{
            head = prev;
        }
        temp2->next = cur;
        prev = temp2;
    }
    return head;
}
ListNode *create_list(){
    int length;
    while(true){
        cout << "Enter the length of linked list you wish to create: ";
        cin >> length;
        if(length < 0){
            cout << "Please enter a positive number\n";
        }
        else{
            break;
        }
    }
    ListNode *dummy = new ListNode();
    ListNode *tail = dummy;
    cout << "Enter " << length << " integers for the linked list: ";
    for(int i=0;i<length;i++){
        int data;
        cin >> data;
        ListNode *new_node = new ListNode(data);
        tail->next = new_node;
        tail = tail->next;
    }
    return dummy->next;
}
int main(){
    ListNode *head = create_list();
    int k;
    while(true){
        cout << "Enter the value of k: ";
        cin >> k;
        if(k <= 0){
            cout << "Please enter a number greater than 0\n";
        }
        else{
            break;
        }
    }
    head = reverseKGroup(head, k);
    cout << "Output: ";
    while(head != NULL){
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL";
    return 0;
}
