/*Approch - 1
 : we select the one root and then search for the other to sum with them to get 
the target Value 
for Example  : target = (node1 + node2)
we select/fix the node1 and the search for node2 while Traversing in the leftSubtree and 
RightSubtree As  if(target - node ) == node2 then add them together   */

/*Approch 2:
make the Inorder ex 1 2 3 4 5 6 7 8 9
Use the Two Pointer Approach --  
if a[i] + a[j] == sum 
sum == target the
if a[i] + a[j] > target the 
*/

#include<iostream>
#include<vector>
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

void Inorder(node* root, vector<int> &in){
    if(root == NULL){
        return ;
    }
    Inorder(root -> left,in);
    in.push_back(root-> data);
    Inorder(root -> right, in);
}

bool twoSumBST(node* root, int Target){

    vector<int> InorderVal;

    //store Inorder -> sorted value
    Inorder(root, InorderVal);
    //two pointer approch if there pair exist

    int i = 0;
    int j = InorderVal.size() - 1;
    while(i < j){
        int sum = InorderVal[i] + InorderVal[j];
        if(sum == Target){
            return true;
        }
        else if(sum > Target){
            j--;
        }
        else{
            i++;
        }

    }
    return false;
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

    cout << "Enter the Target Sum to Find :" << endl;
    int Target;
    cin >> Target;

    if (twoSumBST(root, Target)) {
        cout << "Pair found! Two nodes sum to the target." << endl;
    }
    else {
        cout << "No pair found." << endl;
    }
    return 0;

}