#include <iostream>
using namespace std;
struct treeNode{
    int value;
    treeNode* right;
    treeNode* left;
    treeNode(int data){
        value = data;
        right = NULL;
        left = NULL;
    }
};
treeNode* insert(treeNode* root,int data){
    if(!root) return new treeNode(data);

    while(true){
        if(root->value < data){
            if(!root->right){
                root->right = new treeNode(data);
                break;
            }
            else root = root -> right;
        }
        else{
            if(!root->left){
                root->left = new treeNode(data);
                break;
            }
            else root = root -> left;
        }
    }
    return root;
};

// int HeightOfTreeRoot(treeNode* root){
//     if(!root) return 0;

//     else{
//         int leftHeight = HeightOfTreeRoot( root-> left ) + 1 ;
//         int rightHeight = HeightOfTreeRoot( root-> right) +1 ;

//         if(leftHeight < rightHeight) return rightHeight;
//         else return leftHeight;
//     }

// };

// void distans(treeNode* root){

//     int leftHeight = HeightOfTreeRoot(root->left);
//     int rightHeight =HeightOfTreeRoot(root->right);

//     cout<< leftHeight + rightHeight + 1;
// }
int dfs(treeNode* root, int result);
int diameter(treeNode* root){
    int result = 0;
    return  dfs(root, result);
}

int dfs(treeNode* root, int result) {
    if (!root)
        return -1;

    int left = dfs(root->left, result);
    int right = dfs(root->right, result);
    result = std::max(left + right + 2, result); 
    return std::max(left, right) + 1;
}
int main(){
    int n ; cin >>n;
    treeNode* root = NULL;

    while(n--){
        int num; cin>>num;
        root = insert(root,num);
    }
    // distans(root);

    cout << diameter( root ) + 1;
}