#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct treeNode {
    int value;
    treeNode* right;
    treeNode* left ;

    treeNode(int data){
        this->value = data;
        left = NULL;
        right = NULL;
    }
};

treeNode* insert (treeNode * root , int data ){
    if (root == NULL ) return new treeNode(data);
     treeNode * curr = root ;
    
    while(true){
        if ( curr->value > data ){
            if( !curr->left){
                curr->left = new treeNode(data);
                break ;
            }
            else
                curr = curr->left;
        }
        else {
            if(!curr->right ){
                curr->right = new treeNode(data);
                break;
            }
            else
                curr = curr->right;
        }
    } 
    return root;
}
int levels(treeNode* root){
    if(root == NULL) return 0;
    int rightSind = levels(root->right);
    int leftSind = levels(root->left);

    return 1+max(rightSind, leftSind);
}


vector <int> findLevelSum(treeNode * root){
    vector <int> v;
    queue <treeNode*> q;

    if(root == NULL) return v;
    q.push(root);

    while(!q.empty()){
        int levelSum = 0;
        int levelSize = q.size();

        for(int i=0 ; i < levelSize ; i++){
            levelSum += q.front()->value;

            if(q.front()->left) q.push(q.front()->left);
            if(q.front()->right) q.push(q.front()->right);
            q.pop();

        }
        v.push_back(levelSum);
    }
    return v;
}





int main (){
    int n;   cin >> n;
    treeNode* root = NULL;

    for ( int i=0; i<n ; i++ ){
        int m; cin >>m;
        root = insert(root,m);
    }

    int size = levels(root);
    cout << size << endl;

    vector<int> vec = findLevelSum(root);
    
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << ' ';
    }

}