#include <iostream>
#include <queue>
using namespace std;


struct treeNode {
    int value;
    treeNode* left;
    treeNode* right;

    treeNode(int data) {
        value = data;
        right = NULL;
        left = NULL;
    }
};

treeNode* insert( treeNode * root, int key ){
    if(!root){
        return new treeNode( key );
    }
    treeNode* curr = root;

    while (true){   
        if (curr->value > key){
            if (!curr->left){
                curr->left = new treeNode( key );
                break;
            }
            else
                curr = curr->left;
        }
        else{
            if (!curr->right){
                curr->right = new treeNode( key );
                break;
            }
            else
                curr = curr->right;
                // cout << "right" <<key;
            }   
        }
    return root;

}

int findChildren(treeNode* root, int m) {
    if(!root)
        return 0;
    // cout << "n " << root->value << endl;
    int r = findChildren(root->right, m);
    int l = findChildren(root->left, m);
    return r + l + 1 ;
}

int solve(treeNode* root, int m) {
    treeNode* curr = root;
    while(curr->value != m) {
        if(curr->value > m)
            curr = curr->left;
        else
            curr = curr->right;
    }
    // cout << curr->value << endl;

    return findChildren(curr, m);
}

int main() {
    int n;  cin >> n;
    treeNode* root = NULL;
    for(int i = 0; i < n; i++) {
        int num;  cin >> num;
        root = insert(root, num);
    }

    int m;  cin >> m;
    cout << solve(root, m);

    
    return 0;
}