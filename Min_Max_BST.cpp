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

//Finding the Minimum Of The BST
node* Minimum_BST(node* root){
    if (root == NULL)
        return NULL;  

    node* temp = root;
    if(temp -> left  != NULL){
        temp = temp -> left;
    }
    return temp;
}

node* Maximum_BST(node* root){
    if(root == NULL){
        return NULL;
    }
    node* temp = root;
    if(temp -> right  != NULL){
        temp = temp -> right;
    }
    return temp;
}

//Taking Input for finding the minimum and maximum
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

    node* min_val =  Minimum_BST(root);
    node* max_val = Maximum_BST(root);

    if(min_val != NULL){
        cout << "Minimum val of BST :" << min_val -> data << endl;
    }
    if(max_val != NULL){
        cout << "Maximun val of BST " << max_val -> data << endl;
    }

    return 0;
}