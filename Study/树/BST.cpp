//
// Created by yjs on 2022/5/1.
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


class DoBst {
private:
    vector<int> res;

public:
    // 正序
    vector<int> positiveSequence(TreeNode *root) {
        positiveSequenceTraverse(root);
        return res;

    }

    void positiveSequenceTraverse(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        positiveSequence(root->left);
        res.push_back(root->val);
        positiveSequence(root->right);

    }

    // 逆序
    vector<int> reverseOrder(TreeNode *root) {
        reverseOrderTraverse(root);
        return res;


    }

    void reverseOrderTraverse(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        reverseOrderTraverse(root->right);
        res.push_back(root->val);
        reverseOrderTraverse(root->left);

    }


    // find target
    TreeNode *searchBST(TreeNode *root, int target) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val == target) {
            return root;
        } else if (root->val < target) {
            return searchBST(root->right, target);
        } else if (root->val > target) {
            return searchBST(root->left, target);
        }
        return nullptr;
    }


    bool isValidBST(TreeNode *root) {
        return isValidBST(root, nullptr, nullptr);

    }


    bool isValidBST(TreeNode *root, TreeNode *min, TreeNode *max) {

        if (root == nullptr) {
            return true;
        }
        // 若 root.val 不符合 max 和 min 的限制，说明不是合法 BST
        if (min != nullptr && root->val <= min->val) return false;
        if (max != nullptr && root->val >= max->val) return false;
        // 限定左子树的最大值是 root.val，右子树的最小值是 root.val
        return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);


    }

    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        if (root->val < val) {
            root->right = insertIntoBST(root->right, val);
        } else if (root->val > val) {
            root->left = insertIntoBST(root->left, val);

        }
        return root;


    }


    TreeNode *getMin(TreeNode *node) {
        // BST 最左边的就是最小的
        while (node->left != nullptr) node = node->left;
        return node;
    }

    TreeNode *deleteNode(TreeNode *root, int key) {

        if (root == nullptr) return nullptr;

        if (root->val == key) {
            // delete
            if (root->left == nullptr) return root->right;
            if (root->right == nullptr) return root->left;

            // 处理情况 3
            // 获得右子树最小的节点
            TreeNode *minNode = getMin(root->right);
            // 删除右子树最小的节点
            root->right = deleteNode(root->right, minNode->val);

            // 用右子树最小的节点替换 root 节点
            minNode->left = root->left;
            minNode->right = root->right;
            root = minNode;


        } else if (root->val > key) {
            // 去左子树找
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            // 去右子树找
            root->right = deleteNode(root->right, key);
        }
        return root;


    }


};


int main() {

    return 0;
}
