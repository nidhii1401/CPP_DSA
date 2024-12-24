#include <iostream>
#include <queue>
using namespace std;

class Node{

    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
    
};

// Building a tree
Node* buildTree(Node* root){
      
    int val;
    cout << "Enter data:" << endl;
    cin >> val;

    root = new Node(val);

    if(val == -1) return NULL;

    cout << "Enter data to insert at left of " << val << endl;
      cin >> val;
      root->left = buildTree(root->left);
      cout << "Enter data to insert at right of " << val << endl;
      cin >> val;
    root->right = buildTree(root->right);

    return root;
}

// PreOrder Traversal
void preOrder(Node* root){
    if(root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// InOrder Traversal

void inOrder(Node* root){
    if(root == NULL) return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);

}

// PostOrder Traversal
void postOrder(Node* root){
    if(root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// Level Order Traversal;
void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);

    while (!q.empty()){
        int n = q.size();

        for(int i=0;i<n; i++){
            Node* temp = q.front();
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            cout << temp->data << " ";
        }
        cout << endl;
    }
}



int main(){

    // Node* root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);

    // root->left->left = new Node(4);
    // root->left->right = new Node(-1);

    Node* root = NULL;
    root = buildTree(root);
    cout << " Pre-order Traversal: ",
    preOrder(root);
    cout << endl;

    cout << " inorder Traversal: ",
    inOrder(root);
    cout << endl;

    cout << " post-order Traversal: ",
    postOrder(root);
    cout << endl;

    cout << " Level-order Traversal:" << endl;
    levelOrderTraversal(root);
    cout << endl;

    

    cout << "Code executed succesfully" << endl;
    /*
            1
           /  \
          2    3
         / \   
        4   x 
    
    
    */
}