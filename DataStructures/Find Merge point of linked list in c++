#include<iostream>
#include<cstdlib>
#include<set>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};
int length(struct Node *head) {
    int len = 0;
    while(head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}
//finds the intersection of the given linked lists version1
//Brute force approach
struct Node* findMergePoint1(struct Node *A, struct Node *B) {
    int m = length(A);  //O(m)
    int n = length(B);  //O(n)
    struct Node* head2 = B;
    for(int i=0;i<m;i++) {
        B = head2;
        for(int j=0;j<n;j++) {
            if(A == B) {
                return A;
            }
            B = B->next;
        }
        A = A->next;
    }
    return NULL;
}
//finds the intersection of the given linked lists version2
//Using memory in brute force
struct Node* findMergePoint2(struct Node *A, struct Node *B) {
    int m = length(A);  //O(m)
    int n = length(B);  //O(n)
    set<Node *> addresses;  //requires #include<set>
    for(int i=0;i<n;i++) {  //O(n log n)
        addresses.insert(B);    //O(log n)
        B = B->next;
    }
    for(int i=0;i<m;i++) {  //O(m log n)
        if(addresses.find(A) != addresses.end()) {  //O(log n)
            return A;
        }
        A = A->next;
    }
    return NULL;
    //Overall Complexity -> O(m log n + n log n)
}
//finds the intersection of the given linked lists version3
//The best approach to solve
struct Node* findMergePoint3(struct Node *A, struct Node *B) {
    int m = length(A);
    int n = length(B);
    int d = n - m;
    if(m > n) {
        struct Node* temp = A;
        A = B;
        B = temp;
        d = m - n;
    }
    int i;
    for(i=0;i<d;i++) {
        B = B->next;
    }
    while(A != NULL && B != NULL) {
        if(A == B) {
            return A;
        }
        A = A->next;
        B = B->next;
    }
    return NULL;
}
int main()
{
    // Code to test the logic, creating 7 nodes and linking them together as
    // two linked list merging at a point. 
    struct Node *head1 = NULL, *head2 = NULL;
    struct Node *temp[7];
    for(int i=0;i<7;i++) {
        temp[i] = (Node *)malloc(sizeof(Node));
    }
    temp[0]->data = 4;
    temp[0]->next = temp[1];
    temp[1]->data = 6;
    temp[1]->next = temp[2];
    temp[2]->data = 7;
    temp[2]->next = temp[3];
    temp[3]->data = 1;
    temp[3]->next = NULL;
    temp[4]->data = 9;
    temp[4]->next = temp[5];
    temp[5]->data = 3;
    temp[5]->next = temp[6];
    temp[6]->data = 5;
    temp[6]->next = temp[2];

    head1 = temp[0];
    head2 = temp[4];
    struct Node *C = findMergePoint3(head1, head2); // You can change method name to call function with other approaches. 
    cout<<C->data;
    return 0;
}
