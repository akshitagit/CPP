#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Node {
   public:
    T data;
    Node *next;
};

template <class T>
class LL {
   private:
    Node<T> *first, *last;

   public:
    // --Constructors--

    LL() {
        first = nullptr;
        last = nullptr;
    }
    LL(T A[], int n);
    LL(vector<T> vec);

    // --Destructor--
    ~LL();

    // --Prototypes--

    //Function to display contents of LL
    void Display();
    //Function to insert x into LL at index
    void Insert(int index, T x);
    //Function to delete Node from index
    T Delete(int index);
    //Function which returns the length of LL
    int Length();
    //Function to search for particular element
    Node<T> *Search(T key);
    //Function to insert an element at the end of linked list
    void Append(T x);
    //Function to check if the LL is sorted
    bool isSorted();
    //Function to remove Duplicates from sorted LL
    void Unique();
    //Function to Reverse the linked list
    void Reverse();
    //Function to check if there is a loop in LL
    bool isLoop();
    //Function to concatenate argument LL at end of this LL
    // void Concat(Node<T> *node);
    //Function which returns head
    Node<T> *getHead() { return first; }
};

template <class T>
LL<T>::LL(T A[], int n) {
    Node<T> *t;           //last will be used to enter a new node at the ending
    first = new Node<T>;  //memory of size of structure is allocated, typecasted to type of struct
    first->data = A[0];
    first->next = nullptr;
    last = first;

    for (int i = 1; i < n; i++) {
        t = new Node<T>;
        t->data = A[i];
        t->next = nullptr;  //no next node yet
        last->next = t;     // last node should point on t
        last = t;           // last becomes t, and t will be used for next node
    }

    last->next = nullptr;
}

template <class T>
LL<T>::LL(vector<T> A) {
    Node<T> *t;
    first = new Node<T>;
    first->data = A[0];
    first->next = nullptr;
    last = first;

    int n = A.size();
    for (int i = 1; i < n; i++) {
        t = new Node<T>;
        t->data = A[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }

    last->next = nullptr;
}

template <class T>
LL<T>::~LL() {
    Node<T> *p = first;
    while (first) {
        first = first->next;
        delete p;  //deleting all nodes
        p = first;
    }
}

template <class T>
void LL<T>::Display() {
    Node<T> *p = first;  //first is already in class

    while (p) {
        cout << p->data << " ";
        p = p->next;
    }

    cout << '\n';
}

template <class T>
int LL<T>::Length() {
    Node<T> *p = first;
    int len = 0;
    while (p) {
        len++;
        p = p->next;
    }
    return len;
}

template <class T>
void LL<T>::Insert(int index, T x) {
    Node<T> *t, *p = first;
    if (index < 0 || index > Length()) return;  //! failsafe
    t = new Node<T>;
    t->data = x;
    t->next = nullptr;

    if (index == 0) {  //insert before first
        t->next = first;
        first = t;
    } else {  //insert after first
        for (int i = 0; i < index - 1; ++i)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

template <class T>
T LL<T>::Delete(int index) {
    Node<T> *p, *q = nullptr;
    T x = -1;

    if (index < 1 || index > Length())
        return -1;

    p = first;

    if (index == 1) {  //? O(1) and extra pointer is needed
        first = first->next;
        x = p->data;  //data taken out
        delete p;
    } else {  //? O(n)
        /*
        the node previous to the node to be deleted needs to point to the next node
        So two pointers are needed, one on index, and one on index-1
        */
        for (int i = 0; i < index - 1 && p; ++i) {  //p is checked if null which it becomes at end
            q = p;
            p = p->next;
        }
        if (p) {  //p can become null
            q->next = p->next;
            x = p->data;
            delete p;
        }
    }
    return x;
}

template <class T>
Node<T> *LL<T>::Search(T key) {
    Node<T> *p = first;
    while (p) {
        if (key == p->data) return p;
        p = p->next;
    }
    return nullptr;
}

template <class T>
void LL<T>::Append(T x) {
    Node<T> *t = new Node<T>;
    t->data = x;
    t->next = nullptr;

    if (first == nullptr)
        first = last = t;
    else {
        last->next = t;
        last = t;
    }
}

template <class T>
bool LL<T>::isSorted() {  //O(n)
    Node<T> *p = first;
    T x = first->data;

    while (p) {
        if (p->data < x) return false;
        x = p->data;
        p = p->next;
    }

    return true;
}

template <class T>
void LL<T>::Unique() {
    // q is node before p
    Node<T> *q = first, *p = first->next;
    for (int i = 0; p; ++i) {
        if (p->data == q->data) {
            q->next = p->next;
            delete p;
            p = q->next;
        } else {
            q = p;
            p = p->next;
        }
    }
}

template <class T>
void LL<T>::Reverse() {
    Node<T> *curr = first;
    Node<T> *prev = nullptr;

    while (curr) {
        Node<T> *nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    Node<T> *head = first;
    first = prev;
    last = head;
}

template <class T>
bool LL<T>::isLoop() {  // O(n)
    Node<T> *p, *q;
    p = q = first;  // p moves once, q moves twice
    while (p && q) {
        p = p->next;
        q = q->next;
        q = (q) ? q->next : nullptr;  //dont go to next if already null
        if (p == q) return true;
    }
    return false;
}

int main() {
    vector<int> A = {1, 2, 3, 4, 5};
    LL<int> l1(A), l2;
    l1.Reverse();
    l1.Display();
    l2.Append(6);
    l2.Append(10);
    l2.Append(100);
    l2.Display();
    return 0;
}