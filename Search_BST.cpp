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

//Seaching using Iterative way :


bool SearchIntoBST(node* root, int Target){
    node* temp = root;

    while(temp != NULL ){
        if(temp -> data == Target){
            return true;
        }
        if(temp -> data > Target){
            temp = temp -> left;
        }
        else{
            temp = temp -> right;
        }
    }
    return false;
}


// Searching Using Recursive Way:
/*
bool SearchIntoBST(node* root, int Target){
    if(root == NULL){
        return false;
    }
    if(root -> data == Target){
        return true;
    }

    if(root -> data > Target){
        return SearchIntoBST(root -> left, Target);
    }
    else{
        return SearchIntoBST(root -> right, Target);
    }
}*/



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

    //Searching BST code
    cout << "Enter the Target To Search :" << endl;
    int Target;
    cin >> Target;
    bool ans = SearchIntoBST(root, Target);

    if (ans) {
    cout << "Target Found" << endl;
}
else {
    cout << "Target Not Found" << endl;
}
   
    return 0;


}