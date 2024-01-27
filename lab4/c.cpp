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
    };

};

treeNode* insert(treeNode* root, int number){
    if(!root){
        return new treeNode(number);
    }
    treeNode* curr = root;

    while(true){
        if(curr->value > number){
            if(!curr->left){
                curr->left = new treeNode( number );
                break;
            }
            else
                curr = curr->left;

        }
        else
            if(!curr->right){
                curr->right = new treeNode( number );
                break;
            }
            else
                curr = curr -> right;
    };
    return root;
}
void printPreorder(treeNode* root){
    treeNode* curr = root;
    if (curr == NULL)
        return;

    // Deal with the curr
    cout << curr->value << " ";

    // Recur on left subtree
    printPreorder(curr->left);

    // Recur on right subtree
    printPreorder(curr->right);
}

void solve(treeNode* root, int m){
    treeNode* curr = root;
    while(curr->value != m){
        if ( curr->value < m)
            curr = curr->right;
        else
            curr = curr->left;
    }
    printPreorder(curr);
}

int main(){
    int n; cin>>n;
    treeNode* root =NULL;
    while(n--){
        int num; cin>>num;
        root = insert( root, num );
    }
    int m; cin >>m;
    solve(root,m);

}