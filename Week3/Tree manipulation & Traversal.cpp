#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int id;
    vector<TreeNode*> children;

    TreeNode(int _id) : id(_id) {}
};

class Tree {
public:
    TreeNode* root;
    map<int, TreeNode*> nodeMap;

    Tree() : root(nullptr) {}

    void MakeRoot(int u) {
        if (nodeMap.find(u) == nodeMap.end()) {
            root = new TreeNode(u);
            nodeMap[u] = root;
        }
    }

    void Insert(int u, int v) {
        if (nodeMap.find(u) != nodeMap.end() || nodeMap.find(v) == nodeMap.end())
            return;

        TreeNode* newNode = new TreeNode(u);
        nodeMap[u] = newNode;
        nodeMap[v]->children.push_back(newNode);
    }

    void PreOrder(TreeNode* node) {
        if (node) {
            cout << node->id << " ";
            for (TreeNode* child : node->children) {
                PreOrder(child);
            }
        }
    }

    void InOrder(TreeNode* node) {
        if (node) {
            if (node->children.size() > 0) {
                InOrder(node->children[0]);
            }
            cout << node->id << " ";
            for (int i = 1; i < node->children.size(); i++) {
                InOrder(node->children[i]);
            }
        }
    }

    void PostOrder(TreeNode* node) {
        if (node) {
            for (TreeNode* child : node->children) {
                PostOrder(child);
            }
            cout << node->id << " ";
        }
    }
};

int main() {
    Tree tree;
    string action;

    while (cin >> action) {
        if (action == "MakeRoot") {
            int u;
            cin >> u;
            tree.MakeRoot(u);
        } else if (action == "Insert") {
            int u, v;
            cin >> u >> v;
            tree.Insert(u, v);
        } else if (action == "PreOrder") {
            tree.PreOrder(tree.root);
            cout << endl;
        } else if (action == "InOrder") {
            tree.InOrder(tree.root);
            cout << endl;
        } else if (action == "PostOrder") {
            tree.PostOrder(tree.root);
            cout << endl;
        } else if (action == "*") {
            break;
        }
    }

    return 0;
}
