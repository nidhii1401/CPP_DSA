#include <iostream>
using namespace std;

//Implementation of linked list
class Node{

    public:

    int data;
    Node* next;

    //Constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    // Destructor
    ~Node(){
        int value = this->data;
        if(this->next  != NULL){
            // Memory free krane k liye
            delete next;
            this->next = NULL;
        }
        cout << "Memory freed successfully for data with " << value << endl;
    }
};

// Function to insert element in front of the linked list
void insertAtHead(Node* &head, int data){

   Node* temp = new Node(data);
   temp->next = head;
   head = temp;
}

// Function to insert element at the end of the linked list
void insertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

//Funtion to insert element at any position in the linked list
void insertAtPosition(Node* &head, Node* &tail, int position, int data){

    // agr pheli position pr insert krna hai 
    if(position == 1){
        insertAtHead(head, data);
        return;
    }

    Node* temp = head;
    int cnt=1;
    while(cnt < position -1){
        temp = temp->next;
        cnt++;
    }

    // What if I insert at last position?? Kch nhi insertAtTail function call kar or tail ko update krta jaa
    if(temp->next == NULL){
        insertAtTail(tail,data);
        return;
    }

    //Beech mei kahin bhi gusa do kya fark padta hai :)))
    Node* insertNode = new Node(data);
    insertNode->next = temp->next;
    temp->next = insertNode;

    


}

// Funtion to print linked list
void print(Node* &head){

    Node* temp = head;
     while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
     }
}

// Function to delete any node from the linked list
void deleteNode(int position, Node* &head){
    Node* temp = head;
    // Agr phela hi element hatana ho
    if(position == 1){
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        Node* current = head;
        Node* previous = NULL;
        int cnt = 1;
         while(cnt < position){
            previous = current;
            current = current->next;
            cnt++;
         }
         previous->next = current->next;
         current->next = NULL;
         delete current;
    }
    
}

//The Main Function
int main(){

    Node* node1 = new Node(14);
    Node* head = node1;
    Node* tail = node1;

     print(head);
    // cout << "Insertion at head " << endl;

    // insertAtHead(head, 16);
    // insertAtHead(head, 11);
    // insertAtHead(head, 18);
    // print(head);

    cout <<endl;
    insertAtTail(tail, 16);
    insertAtTail(tail, 45);
    insertAtTail(tail, 67);
    //print(head);
    //cout << endl << endl;
    insertAtPosition(head,tail,4, 69);
    insertAtPosition(head,tail,1, 23);
    insertAtPosition(head,tail,7, 114);
    print(head);

    cout << endl << "DELETION KIYA HAI " << endl;
    deleteNode(7,head);
    print(head);
    





}