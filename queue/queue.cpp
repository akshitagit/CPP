#include<iostream>
using namespace std;

template <class X> class Queue
{
    private:
        int size, capacity;
        X *arr;
    public:
        Queue(int capacity)
        {
            this->capacity = capacity;
            this->size = 0;
            arr = new X[this->capacity];
        }
        ~Queue()
        {
            delete []arr;
        }
        // isEmpty() returns true if queue is empty
        bool isEmpty()
        {
            return(this->size == 0);
        }
        // isFull() returns true if queue is full
        bool isFull()
        {
            return(this->size == this->capacity);
        }
        // enqueue() used to insert a new item at the front of queue
        int enqueue(int item)
        {
            if(isFull())
            {
                return 1;
            }
            else
            {
                this->arr[size] = item;
                this->size++;
                return 0;
            }
        }
        // dequeue() used to delete last item from queue
        int dequeue()
        {
            int i;
            if(isEmpty())
            {
                return -1;
            }
            else
            {
                for(i = 0; i < this->size - 1; i++)
                {
                    this->arr[i] = this->arr[i+1];
                }
                this->size--;
                return 0;
            }
        }
        // getFront() returns front item of the queue
        X getFront()
        {
            if(isEmpty())
            {
                return -1;
            }
            else
            {
                return this->arr[0];
            }
            
        }
        // getRear() returns last item of the queue
        X getRear()
        {
            if(isEmpty())
            {
                return -1;
            }
            else
            {
                return this->arr[this->size - 1];
            }
        }

        // display() print out all the items of queue
        void display()
        {
            int i;
            if(isEmpty())
            {
                cout << "Queue is Empty." << endl;
                return;
            }
            else
            {
                for(i = 0; i < this->size; i++)
                {
                    cout << this->arr[i] << " ";
                }
                cout << endl;
            }
        }
};

// main funciton
int main(int argv, char *argc[])
{
    Queue<char>q('s');
    q.enqueue('a');
    q.enqueue('c');
    q.enqueue('h');
    q.display();
    q.dequeue();
    q.display();
    cout << q.getFront() << endl;
    cout << q.getRear() << endl;
    return 0;
}