//
// Created by yjs on 2022/4/28.
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
    vector<int> res;

public:





    // 非递归先序遍历二叉树 [根 左 右]
    // https://leetcode-cn.com/problems/binary-tree-preorder-traversal/solution/er-cha-shu-de-qian-xu-bian-li-by-leetcode-solution/
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        stack<TreeNode*> stk;
        TreeNode* node = root;
        while (!stk.empty() || node != nullptr) {
            while (node != nullptr) {
                res.emplace_back(node->val);
                stk.emplace(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            node = node->right;
        }
        return res;
    }




    vector<int> inorderTraversal(TreeNode *root) {

        stack<TreeNode *> stackToken;
        while (!stackToken.empty() || root != nullptr) {
            while (root != nullptr) {
                stackToken.push(root);
                root = root->left;
            }

            root = stackToken.top();
            stackToken.pop();
            res.push_back(root->val);
            root = root->right;

        }
        return res;


    }


    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;

        if (root == nullptr) {
            return res;
        }

        stack<TreeNode *> stackToken;
        TreeNode *prev = nullptr;

        while (!stackToken.empty() || root != nullptr) {

            while (root != nullptr) {

                stackToken.push(root);
                root = root->left;
            }

            root = stackToken.top();
            stackToken.pop();
            if (root->right == nullptr || root->right == prev) {
                res.push_back(root->val);
                prev = root;
                root = nullptr;
            } else {
                stackToken.push(root);
                root = root->right;

            }


        }
        return res;
    }





};