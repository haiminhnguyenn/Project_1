#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insert(TreeNode* root, int key) {
    if (root == NULL) {
        return new TreeNode(key);
    }
    if (key < root->val) {
        root->left = insert(root->left, key);
    } else if (key > root->val) {
        root->right = insert(root->right, key);
    }
    return root;
}

void preOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    cout << root->val << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main() {
    TreeNode* root = NULL;

    string line;
    while (getline(cin, line) && line != "#") {
        if (line.find("insert") == 0) {
            int key = stoi(line.substr(7));
            root = insert(root, key);
        }
    }

    preOrderTraversal(root);
    return 0;
}
