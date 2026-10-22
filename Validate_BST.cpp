#include<iostream>
#include<climits>
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

bool isBST(node* root, int min, int max){
    if(root == NULL){
        return true;
    }

    if(root -> data >= min && root -> data <= max){
        bool left = isBST(root -> left, min, root ->  data);
        bool right = isBST(root -> right, root -> data , max);
        return left && right;
    }
    else{
        return false;
    }

}
// iNSERT into the BST
bool validateBST(node* root){
    return isBST(root, INT_MIN, INT_MAX);

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
    node* root = NULL;
    //10 8 21 7 27 5 4 3 -1
    cout << "Enter the data create BST" << endl;
    root = TakeInput(root);

    
    if(validateBST(root)){
        cout <<"IS BST" << endl;
    }
    else{
        cout << "NOT BST" << endl;
    }

    return 0;
}