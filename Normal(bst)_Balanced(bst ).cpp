#include<iostream>
#include<vector>
using namespace std;
/*converting the N-node BST into The Balance BST
wehere the hight differnec  between the subtree is not more then one*/
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

// Step 1: Store inorder values in sorted order
void inorder(node<int>* root, vector<int> &in) {
    if (root == NULL) {
        return;
    }

    inorder(root->left, inorderVal);
    inorderVal.push_back(root->data);
    inorder(root->right, inorderVal);
}

node<int>* InorderToBst(int s, int e, vector<int> &in){
    //Base Case
    if(s>e){
        return NULL;
    }

    int mid = (s+e)/2;
    node<int>* root = new node<int>(int[mid]); // new node and point on the mide
    root ->left = InorderToBst(s, mid - 1, in);
    root -> right = InorderToBst(mid + 1, e, in);
    return root;
}

node<int>* BalanceBST(node<int>* root){
    vector<int> InorderVal;
    //stored inorder -> Store values
    inorder(root ,InorderVal);

    return InorderToBst(0 , inorderVal.size() - 1, inorderVal);
}

