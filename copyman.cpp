#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

// --- TreeNode structure ---
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// --- Solution class (same as LeetCode) ---




    void inorder(TreeNode* root, vector<int>& result) {
        if (!root) return;
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }








// --- Function to build tree from level-order input ---
TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "N") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front(); q.pop();

        // Left child
        if (i < nodes.size() && nodes[i] != "N") {
            current->left = new TreeNode(stoi(nodes[i]));
            q.push(current->left);
        }
        i++;

        // Right child
        if (i < nodes.size() && nodes[i] != "N") {
            current->right = new TreeNode(stoi(nodes[i]));
            q.push(current->right);
        }
        i++;
    }

    return root;
}

int main() {
    cout << "Enter tree nodes in level-order (use N for null): ";
    string input;
    getline(cin, input);

    // Parse input string
    stringstream ss(input);
    string val;
    vector<string> nodes;

    while (ss >> val) {
        nodes.push_back(val);
    }

    // Build tree
    TreeNode* root = buildTree(nodes);

    // Solve using LeetCode-style function

    vector<int> result = inorderTraversal(root);

    // Output result
    cout << "Inorder Traversal: ";
    for (int v : result) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
