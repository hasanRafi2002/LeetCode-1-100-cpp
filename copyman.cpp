#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Build tree from level order input
TreeNode* buildTree() {
    cout << "Enter tree nodes in level order (use -1 for NULL): ";

    int val;
    cin >> val;
    if (val == -1) return nullptr;

    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        int leftVal, rightVal;
        cin >> leftVal;
        if (leftVal != -1) {
            current->left = new TreeNode(leftVal);
            q.push(current->left);
        }

        cin >> rightVal;
        if (rightVal != -1) {
            current->right = new TreeNode(rightVal);
            q.push(current->right);
        }
    }

    return root;
}

// Recursive tree comparison
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (!p || !q) return false;
    if (p->val != q->val) return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
    cout << "Build Tree 1:\n";
    TreeNode* tree1 = buildTree();

    cout << "Build Tree 2:\n";
    TreeNode* tree2 = buildTree();

    if (isSameTree(tree1, tree2)) {
        cout << "The trees are the SAME.\n";
    } else {
        cout << "The trees are DIFFERENT.\n";
    }

    return 0;
}
