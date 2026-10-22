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

int solve(node* root,int &i, int k){
    //base case 
    if(root == NULL){
        return -1;
    }
    //left
    int left = solve(root -> left, i, k);

    if(left != -1){
        return left;
    }

    //noode
    i++;
    if(i == k){
        return root -> data;
    }

    //right
    return solve(root -> right, i ,k); 

}

int kthSmallest(node* root, int &i , int k){
    int m = 0;
    return solve(root, m , k);
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
    

    //printing the inorder
    inorder(root);
    cout << endl;

    int k;
    cout << "Enter k: ";
    cin >> k;
    int i = 0;
    
    int ans = kthSmallest(root,i, k);

    if (ans == -1) {
        cout << "Invalid k or element not found" << endl;
    } else {
        cout << "Kth smallest element: " << ans << endl;
    }


}