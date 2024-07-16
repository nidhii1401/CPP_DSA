#include <iostream>
using namespace std;

// Implementation of Queues using Array

class Queue
{

    // Properties
    int *arr;
    int front;
    int rear;
    int size;

public:
    // Constructor
    Queue(int size)
    {
        size = this->size;
        arr = new int(size);
        front = 0;
        rear = 0;
    }
    // Function to add element at the front of the queue
    void enqueue(int data)
    {

        if (rear == size)
        {
            cout << "Queue is Full" << endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    // Function to remove element from the front of the queue

    int dequeue()
    {
        int ele = arr[front];
        cout << "Element Removed : " << ele << endl;
        if (front == rear)
            return -1; // When Queue is empty
        else
        {
            arr[front] = -1;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
        }
        return ele;
    }

    // Function to get front element of the queue
    int getFront()
    {
        if (front == rear)
            return -1; // Queue is Empty
        else
            return arr[front];
    }

    // Function to check if Queue is empty or not
    bool isEmpty()
    {
        if (front == rear)
            return true; // Queue is Empty
        else
            return false;
    }
};

int main()
{
    Queue *q = new Queue(5);

    q->enqueue(9);
    cout << q->getFront() << endl;
    q->enqueue(29);
    // cout << q->getFront() << endl;
    // q->dequeue();
    // cout << q->getFront() << endl;
    q->enqueue(529);
    // q->dequeue();
    q->enqueue(2);
    // q->dequeue();
    q->enqueue(26);
    // q->enqueue(10);

    // q->enqueue(29);
    // cout << q->isEmpty();

    //   q->enqueue(19);
    //   q->enqueue(94);
    //   q->enqueue(39);
    //   q->enqueue(59);
    //   q->enqueue(90);

    // int ans =  q->getFront();
    //  cout << ans;
}