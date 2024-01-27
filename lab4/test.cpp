#include <iostream>
using namespace std;

struct treeNode {
    int value;
    treeNode* right;
    treeNode* left;

    treeNode(int data) {
        value = data;
        left = NULL;
        right = NULL;
    }
};

treeNode* insert(treeNode* root, int data) {
    if (!root) {
        return new treeNode(data);
    }
    treeNode* curr = root;
    while (true) {
        if (curr->value > data) {
            if (!curr->left) {
                curr->left = new treeNode(data);
                break;
            }
            else {
                curr = curr->left;
            }
        }
        else {
            if (!curr->right) {
                curr->right = new treeNode(data);
                break;
            }
            else {
                curr = curr->right;
            }
        }
    }
    return root;
}

bool checkInBST(treeNode* root, int x) {
    treeNode* curr = root;
    while (curr) {
        if (curr->value == x) {
            return true;
        }
        else if (curr->value < x) {
            curr = curr->right;
        }
        else {
            curr = curr->left;
        }
    }
    return false;
}

treeNode* constructBST(int n) {
    treeNode* root = NULL;
    for (int i = 0; i < n - 1; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if (z == 0 && x > y) {
            if (!checkInBST(root, x)) {
                root = insert(root, x);
            }
            insert(root, y);
        }
        else if (z == 1 && x < y) {
            if (!checkInBST(root, x)) {
                root = insert(root, x);
            }
            insert(root, y);
        }
    }
    return root;
}

void printInOrder(treeNode* root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    cout << root->value << " ";
    printInOrder(root->right);
}

int main() {
    int n;
    cin >> n;
    treeNode* root = constructBST(n);
    printInOrder(root);
    return 0;
}
