// Inorder of the binary search tree (BST) is sorted
/* What Inside :-
   Creating the BST
   Level Order Traversal Of BST
   Printing Inorder ,PreOrder, Postoder 

*/


#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};


// inorder traversal
void inorder(node * root){
    if(root == NULL){
        return;
    }

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}


//preoder traversal 
void preorder(node * root){
    if(root == NULL){
        return;
    }
    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}
void postorder(node * root){
    if(root == NULL){
        return ;
    }
    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";
    
}
//level Order Traversal code 
void levelOrderTraversal(node* root) {
    if (root == NULL)
        return;

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;

        if (!q.empty())
            q.push(NULL);
        }
        else {
            cout << temp->data << " ";

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}

node* insertintoBST(node* root, int d){
    //base case
    if(root == NULL){
        root = new node(d);
        return root;
    }

    //inserting into the right subtree
    if(d > root -> data){
        root -> right = insertintoBST(root -> right, d);
    }
    // inserting into the left subtree
    if(d < root -> data){
        root -> left = insertintoBST(root -> left, d);
    }
    return root;
}

node* TakeInput(node* root){
    int data;
    cin >> data;

    while(data != -1){
        root = insertintoBST(root , data);
        cin >> data;
    }
    return root;
}

int main(){
    //10 8 21 7 27 5 4 3 -1

    node* root = NULL;

    cout << "Enter the data create BST" << endl;
    root = TakeInput(root);
    cout << "Printing Tree Level Order Traversal" << endl;
    levelOrderTraversal(root);

    cout << "Printing Inorder "<< endl;
    inorder(root);

    cout << endl << "Printing Preorder" << endl;
    preorder(root);

    cout << endl << "Printing Postorder" << endl;
    postorder(root);

    return 0;
}