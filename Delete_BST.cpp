#include<iostream>
using namespace std;

/*Left The Code written for the deletetion for the second child*/

class node{
    int data;
    node* left;
    node* right;

    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL; 
    }
};

//Delete From BST

node* DeleteIntoBST(node* root, int val){
    //base case
    if(root == NULL){
        return root;
    }

    if(root -> data == val){
    // 0 child
    if(root -> left == NULL && root -> right == NULL){
        Delete root;
        return NULL;
    }
    // 1 child

    //left child
    if(root -> left != NULL && root -> right == NULL){
        node* temp = root -> left; // save the next value of the root (root -> next)
        delete root; // delete the current root
        return temp; // now return the root -> next (which was saves previously)
    }

    // Right child
    if(root -> left == NULL && root -> right != NULL){
        node* temp = root -> right; // save the next value of the root (root -> next)
        delete root; // delete the current root
        return temp; // now return the root -> next (which was saves previously)
    }

    // 2 child
if (root->left != NULL && root->right != NULL) {
    int mini = minVal(root->right)->data;
    root->data = mini;
    root->right = deleteFromBST(root->right, mini);
    return root;
}


    }
   
}

int main(){

    node* root = NULL;
    DeleteIntoBST(root);
    return NULL;
}