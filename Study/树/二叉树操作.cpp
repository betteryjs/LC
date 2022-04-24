//
// Created by yjs on 2022/4/24.
//
#include <bits/stdc++.h>


using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class DoTree {
private:
    void visit(TreeNode *node) {
        cout << node->val << " ";
    }

public:

    // 递归遍历二叉树
    void preOrder(TreeNode *root) {

        if (root != nullptr) {
            visit(root);
            preOrder(root->left);
            preOrder(root->right);

        }
    }

    void inOrder(TreeNode *root) {

        if (root != nullptr) {
            preOrder(root->left);
            visit(root);
            preOrder(root->right);

        }
    }

    void postOrder(TreeNode *root) {

        if (root != nullptr) {
            preOrder(root->left);
            preOrder(root->right);
            visit(root);
        }
    }

    // 层次遍历
    void levelTraverse(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        queue<TreeNode *> queueTreeNodes;
        queueTreeNodes.push(root);
        while (!queueTreeNodes.empty()) {
            int sz = queueTreeNodes.size();
            for (int i = 0; i < sz; ++i) {
                TreeNode *node = queueTreeNodes.front();
                visit(node);
                queueTreeNodes.pop();
                if (node->left != nullptr) {
                    queueTreeNodes.push(node->left);
                }
                if (node->right != nullptr) {
                    queueTreeNodes.push(node->right);
                }
            }
        }
    }

    // 求树的最大高度
    int maxDeep(TreeNode * root){
        if(root== nullptr){
            return 0;
        }
        int leftMax= maxDeep(root->left);
        int rightMax= maxDeep(root->right);
        return 1+max(leftMax,rightMax);
    }





};