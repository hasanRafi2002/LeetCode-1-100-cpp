#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};



void inorder(TreeNode* root, vector<int>& result){
    if(!root) return;
    inorder(root->left, result);
    result.push_back(root->val);
    inorder(root->right, result);
}

vector<int> inorderTraversal(TreeNode* root){
    vector<int> result;
    inorder(root, result);
    return result;
}



TreeNode* buildTree(const vector<string>& nodes){
    if(nodes.empty() || nodes[0] == "N") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i<nodes.size()){
        TreeNode* current = q.front(); q.pop();

        if(i<nodes.size() && nodes[i] != "N"){
            current->left = new TreeNode(stoi(nodes[i]));
            q.push(current->left);
        }
        i++;

        if (i<nodes.size() && nodes[i] != "N"){
            current->right = new TreeNode(stoi(nodes[i]));
            q.push(current->right);
        }
        i++;
    }
    return root;

}


int main(){
    cout<<"Enter three nodes in level-order (use N for null): ";
    string input;
    getline(cin, input);

    stringstream ss(input);
    string val;
    vector<string> nodes;

    while (ss>>val){
        nodes.push_back(val);
    }

    TreeNode* root = buildTree(nodes);
    vector<int> result = inorderTraversal(root);

    cout<<"Inorder Traversal: ";
    for(int v : result){
        cout<<v<<" ";
    }
    cout<<endl;

    return 0;

}