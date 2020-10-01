#include<iostream>
using namespace std;
class queue
{
    private:
        int size, cap, front;
        int *arr;
    public:
        queue(int capcaity)
        {
            this->cap = capcaity;
            this->size = 0;
            this->front = 0;
            this->arr = new int[cap];
        }
        ~queue()
        {
            delete []arr;
        }
        bool isEmpty()
        {
            return (this->size == 0);
        }
        bool isFull()
        {
            return (this->size == this->cap);
        }
        int getFront()
        {
            if(isEmpty())
            {
                return -1;
            }
            else
            {
                return this->front;
            }
        }
        int getRear()
        {
            if(isEmpty())
            {
                return -1;
            }
            else
            {
                return((this->front + this->size -1) % this->cap);
            }
        }
        int enqueue(int item)
        {
            if(isFull())
            {
                return 1;
            }
            int rear = getRear();
            rear = (rear + 1) % cap;
            this->arr[rear] = item;
            this->size++;
            return 0;
        }
        int dequeue()
        {
            if(isEmpty())
            {
                return -1;
            }
            this->arr[front] = -1;
            front = (front+1)%cap;
            this->size--;
            return 0;
        }
        void display()
        {
            int rear = getRear();
            if(isEmpty())
            {
                cout << "Queue is empty." ;
            }
            if(front <= rear)
            {
                for(int i = front; i <= rear ; i++)
                {
                    cout << arr[i] << " ";
                }
            }
            else
            {
                for(int i = front; i < size ; i++)
                {
                    cout << arr[i] << " ";
                }
                for(int i = 0 ;i < rear; i++)
                {
                    cout << arr[i] << " ";
                }
            }

            cout << endl;
        }
};
int main(int argv, char *argc[])
{
    queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();
    q.enqueue(60);
    q.display();
    return 0;
}