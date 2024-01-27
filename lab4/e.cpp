#include <iostream>
using namespace std;
struct treeNode{
    int value;
    treeNode* right;
    treeNode* left;

    treeNode(int data){
        value = data;
        left = NULL;
        right = NULL;
    }

};

treeNode* insert(treeNode* root,int data){
    if(!root) return new treeNode(data);
    treeNode* curr = root;
    while(true){
        if(curr->value > data){
            if(!curr->left){
                curr->left = new treeNode(data);
                break;
            }
            else curr = curr->left;
        }
        else{
            if(!curr->right){
                curr -> right = new treeNode(data);
                break;
            }
            else curr = curr->right;
        }
    }
    return root;
}

bool checkInBTS (treeNode* root,int x){
    treeNode * curr = root;
    while(curr->value != x){
        if ( curr->value < x)
            curr = curr->right;
        else
            curr = curr->left;
    }
    return true;
}

int check (int x, int y, int z,treeNode* root){
    if(z==0){
        if(x>y){
            if(!root){
                new treeNode(x);
                return 0;
            }

            if(checkInBTS(root,x)){
                insert(root,y);
            }
        }
        else return 0;
    }
    else{
        if(x<y){
            if(!root){
                new treeNode(x);
                return 0;
            }
            if(checkInBTS(root,x)){
                cout << "fd";
                insert(root,y);
            }
        }
        else return 0;
    }

}

void printInOrder(treeNode* root) {
    if (root == NULL) {
        cout << "dfd";
        return ;
    }

    printInOrder(root->left);      // Recursively traverse the left subtree
    cout << root->value << " "; // Print the value of the current node
    printInOrder(root->right);     // Recursively traverse the right subtree
}


int main(){
    int n; cin >> n;
    treeNode* root = NULL;
    for(int i=0;i<n-1;i++){
        int x,y,z; 
        cin >>x >>y >>z;
        check(x,y,z,root);
        
    }
    printInOrder(root);
}