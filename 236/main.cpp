#include <iostream>

/**
 * Definition for a binary tree node.*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr || root == q || root == p) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left == nullptr && right == nullptr) return nullptr;
        else if (left == nullptr) return right;
        else if (right == nullptr) return left;
        else return root; // left!=nullptr && right!=nullptr


    }
};

class Solution2 {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        return find(root,q,p);

    }

    TreeNode * find(TreeNode * root,TreeNode * node1,TreeNode * node2){
        if(root== nullptr){
            return root;
        }
        if(root->val== node1->val || root->val==node2->val){
            return root;
        }
        TreeNode * left= find(root->left,node1,node2);
        TreeNode * right= find(root->right,node1,node2);

        if(left!= nullptr && right!= nullptr){
            return root;
        }
        return left== nullptr ? right:left;




    }


};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
