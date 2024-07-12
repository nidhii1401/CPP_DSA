#include <iostream>
using namespace std;

// Stack Class Implementation
class Stack{
    public:
     // Properties
     int *arr;
     int top;
     int size;

     // Constructor
     Stack(int size){
        this->size=size;
        arr = new int[size];
        top=-1;
     }
     
    // Methods

    // Pushing element in the stack
    void push(int element){
        if( (size-top) > 1){
            top++;
            arr[top]=element;
        }
        else cout << "Stack Overflow" << endl;
    }

    // Popping element from the top of the stack
    void pop(){
        if(top>=0) top--;
        else cout << "Stack Underflow" << endl;
    }

    // Finding Peak element 
    int peak(){
        if(top >= 0) return arr[top];
        else {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }
    // To check whether the stack is empty or not
    bool isEmpty(){
        if(top == -1) return true;
        else return false;
    }
};
int main(){
    
    Stack* s = new Stack(5);
    s->push(17);
    s->push(16);

    cout << "Top element of the stack is: "<< s->peak() << endl;
    
    while(!s->isEmpty()){
        cout<< s->peak() << " ";
        s->pop();
    }

}