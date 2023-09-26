/*
Problem Statement
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

Input Format
the first line contains n the number of nodes in the given linked list

the second line contains n space separated binary integers to be in the list.

Output Format
Calculate and return the number formed by using the input list

Constraints
The Linked List is not empty.
Number of nodes will not exceed 30.
Each node's value is either 0 or 1.
Sample Testcase 0
Testcase Input
3
1 0 1
Testcase Output
5
*/


// code
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int getDecimalValue(ListNode* head) {
    int decimalValue = 0;
    while (head != nullptr) {
        decimalValue = (decimalValue << 1) | head->val;
        head = head->next;
    }
    return decimalValue;
}

// Function to create a linked list from an array of values
ListNode* createLinkedList(int values[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (int i = 1; i < n; ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

int main() {
    int n;
    std::cin >> n;
    int binaryValues[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> binaryValues[i];
    }
    
    ListNode* head = createLinkedList(binaryValues, n);
    int decimalValue = getDecimalValue(head);
    
    std::cout << decimalValue << std::endl;
    
    return 0;
}
