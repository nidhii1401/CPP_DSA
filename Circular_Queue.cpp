#include <iostream>
using namespace std;

// Implementation of cicular queue using array
class CircularQueue
{

    // Data Members
    int *arr;
    int front;
    int rear;
    int size;

public:
    // Constructor
    CircularQueue(int n)
    {
        size = n;
        arr = new int(size);
        front = 0;
        rear = 0;
    }

    //  Function to insert element in the queue
    void enqueue(int data)
    {

        // Check whether queue is full or not
        if ((front == 0 && rear == size - 1) || (rear == front - 1) % (size - 1))
        {
            cout << "Queue is Full, cannot add more elements" << endl;
        }

        // Insertion of first element
        else if (front == -1)
        {
            front = 0;
            rear = 0;
            arr[front] = data;
            cout << arr[front] << " ";
        }

        // To maintain the cyclic nature of the queue
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = data;
            cout << arr[rear] << " ";
        }

        // Normal Flow
        else
        {
            rear++;
            arr[rear] = data;
            cout << arr[rear] << " ";
        }
    }

    // Funtion to remove element from the circular
    void dequeue()
    {
        // cout << endl;
        // int ele = arr[front];

        // To check if queue is empty or not
        if (front == -1)
        {
            cout << "Queue is Empty" << endl;
        }

        // if there is only a single element in the queue
        else if (front == rear)
        {
            // cout << "Element Removed: " << ele << endl;
            front = -1;
            rear = -1;
        }

        // to maintain the cyclic nature of the queue
        else if (front == size - 1)
        {
            // cout << "Element Removed: " << ele << endl;
            front = 0;
        }

        // Normal flow
        else
        {
            // cout << "Element Removed: " << ele << endl;
            front++;
        }
    }
};

int main()
{

    CircularQueue *obj = new CircularQueue(5);
    // obj->enqueue(10);
    obj->enqueue(45);
    // obj->dequeue();
    obj->enqueue(14);
    // obj->enqueue(16);
    obj->dequeue();
}