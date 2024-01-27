#include <iostream>
#include <vector>
#include <stack>
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
            }   
        }
    return root;

}

bool isPossible( treeNode* root, string s){
    treeNode* curr = root;
    for (int i = 0; i < s.length(); ++i) {
        char c = s[i];
        if(c == 'L') curr = curr->left;
        if(c == 'R') curr = curr->right;
        if(!curr) return false;
    }
    return true;
};

int main(){
    int n,m;
    cin >>n>>m;
    treeNode* root = NULL;
    while (n--){
        int num;
        cin >> num;
        root = insert( root, num);
    }

    while (m--){
        string q;
        cin >> q;
        if ( isPossible( root, q) ) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
