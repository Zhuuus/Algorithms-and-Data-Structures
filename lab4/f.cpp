// F-106735. Triangle Binary Search Tree

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* insert_node(TreeNode* root, int x) {
    if(!root)
        return new TreeNode(x);

    TreeNode* curr = root;
    while(true) {
        if(curr->val > x)
            if(!curr->left) {
                curr->left = new TreeNode(x);
                break;
            }
            else
                curr = curr->left;
        else if(!curr->right) {
            curr->right = new TreeNode(x);
            break;
        }   
        else
            curr = curr->right;
    }

    return root;
}

int count_triangles(TreeNode* root) {
    if(!root)
        return 0;
    if(root->left != NULL && root->right != NULL)
        return 1 + count_triangles(root->left) + count_triangles(root->right);
    return count_triangles(root->left) + count_triangles(root->right);
}

int main() {
    int n;  cin >> n;
    TreeNode* root = NULL;
    for(int i = 0; i < n; i++) {
        int num;  cin >> num;
        root = insert_node(root, num);
    }

    cout << count_triangles(root);

    system("pause");
    return 0;
}