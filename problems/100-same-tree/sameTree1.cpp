#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}


};

TreeNode* buildTree(){
    cout<<"Enter tree nodes in level order (use -1 for NULL): ";

    int val;
    cin>>val;

    if(val == -1) return nullptr;
}

