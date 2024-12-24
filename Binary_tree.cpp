#include <iostream>
#include <queue>
using namespace std;

// Creation of binary tree
class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    // Constructor
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to build tree
Node *buildTree(Node *root)
{

    cout << "Enter data:" << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
        return NULL;
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;

}

// Level Order Traversal

void levelOrderTraversal( Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            // Previous level has been completed
            cout << endl;
            if(!q.empty()){
                // Queue still have some child nodes 
                q.push(NULL);
            }
        }

        else{
            cout << temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
    }

}
int main()
{

    Node *root = NULL;

    // Creating a tree
    root = buildTree(root);
    cout << "Level Order Traversal:" << endl;
    levelOrderTraversal(root);
}