#include <iostream>
using namespace std;
struct Node{
    int value;
    Node* right;
    Node* left;
    Node(int data){
        value = data;
        right = NULL;
        left = NULL;
    };
};

Node* insert(Node* root,int data){
    if(!root) return new Node(data);

    Node* curr = root;

    while(true){

        if(curr->value<data){
            if(!curr->right){
                curr->right = new Node(data);
                break;
            }
            else curr = curr->right;
        }
        else{
            if(!curr->left){
                curr->left = new Node(data);
                break;
            }
            else curr = curr->left;
        }
    }
    return root;
} 
int a=0,b=8;
void transformTreeUtil(struct Node *root, int *sum)
{
   if (root == NULL)  return;
//    cout<<root->value<<a<<" ";
//    a++;

   transformTreeUtil(root->right, sum);
 
//   cout<<b<<"_"<<root->value<<" ";
//    b--;
   
   *sum = *sum + root->value;
   root->value = *sum ;
   cout << root->value<<" ";
 
   transformTreeUtil(root->left, sum);
}
 
// A wrapper over transformTreeUtil()
void transformTree(struct Node *root)
{
    int sum = 0; // Initialize sum
    transformTreeUtil(root, &sum);
}
// A utility function to print indorder traversal of a
// binary tree
// void printInorder(struct Node *root)
// {
//     if (root == NULL) return;
//     printInorder(root->left);
//     cout << root->value << " ";
//     printInorder(root->right);
// }


int main(){
    int n; cin>>n;
    Node* root = NULL;
    for(int i=0; i<n; i++){
        int num; cin>>num;
        root = insert(root,num);
    }

    transformTree(root);
    // printInorder(root);
   

    
}