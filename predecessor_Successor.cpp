#include<iostream>
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

pair <int ,int> predecessorSuccessor(node* root, int key){
    node* temp = root;
    int pred = -1;
    int succ = -1;

    //find key
    while(temp != NULL && temp -> data != key){
        if(temp -> data > key){
            succ = temp -> data;
            temp = temp -> left;
        }
        else{
            pred = temp -> data;
            temp = temp -> right;
        }
    }

    //key not found
    if(temp == NULL){
        return make_pair(-1,-1);
    }

    //find predeccesor in left subtree
    node* leftTree = temp -> left;
    while(leftTree != NULL){
        pred = leftTree -> data;
        leftTree = leftTree -> right;

    }

    //find successor in the right subtree
    node* rightTree = temp -> right;
    while(rightTree != NULL){
        succ = rightTree -> data;
        rightTree = rightTree -> left;

    }
    return make_pair(pred, succ);

}


   //Inorder Traversal
    void inorder(node * root){
    if(root == NULL){
        return;
    }

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

int main(){

    node* root = NULL;
    root = new node(5);
    root->left = new node(3);
    root->right = new node(7);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->right->left = new node(6);
    root->right->right = new node(8);
    
    // printing the Inoder traversal

    cout << "Inorder Traversal is : ";
    inorder(root);
    cout << endl;

    
    int key;
    cout << "Enter the Key value to search :" << endl;
    cin >> key;

    pair<int, int> ans = predecessorSuccessor(root, key);

    cout << "Predecessor: " << ans.first << endl;
    cout << "Successor: " << ans.second << endl;
    return 0; 
}