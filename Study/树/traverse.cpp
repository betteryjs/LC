//
// Created by yjs on 2022/4/23.
//
#include <bits/stdc++.h>


using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class DOTree {

public:
    // 二叉树遍历框架
    void traverse(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        // 前序位置
        traverse(root->left);
        // 中序位置
        traverse(root->right);
        // 后序位置
    }

    /* 递归遍历数组 */
    void traverse(const vector<int> &arr, int i) {
        if (i == arr.size()) {
            cout << endl;
            return;
        }
        // 前序位置
//        cout << arr[i] << " ";
        traverse(arr, i + 1);
        // 后序位置
        cout << arr[i] << " ";

    }

    /* 递归遍历单链表，倒序打印链表元素 */
    void traverse(ListNode *head) {
        if (head == nullptr) {
            return;
        }
        // 前序位置

        traverse(head->next);
        // 后序位置
//        print(head->val);
    }
    // 定义：输入一棵二叉树，返回这棵二叉树的节点总数
    int count(TreeNode*  root) {
        if (root == nullptr) {
            return 0;
        }
        int leftCount = count(root->left);
        int rightCount = count(root->right);
        // 后序位置
        printf("节点 %s 的左子树有 %d 个节点，右子树有 %d 个节点",
               *root, leftCount, rightCount);

        return leftCount + rightCount + 1;
    }


    // 输入一棵二叉树的根节点，层序遍历这棵二叉树
    void levelTraverse(TreeNode* root) {

        if (root == nullptr) return;
        queue<TreeNode* > queueTree;
        queueTree.push(root);

        // 从上到下遍历二叉树的每一层
        while (!queueTree.empty()) {
            int sz = queueTree.size();
            // 从左到右遍历每一层的每个节点
            for (int i = 0; i < sz; i++) {
                TreeNode* cur = queueTree.front();
                queueTree.pop();
                // 将下一层节点放入队列
                if (cur->left != nullptr) {
                    queueTree.push(cur->left);
                }
                if (cur->right != nullptr) {
                    queueTree.push(cur->right);
                }
            }
        }
    }





};

int main() {

    vector<int> nums{1, 22, 26, 36};
    DOTree *doTree = new DOTree();
    doTree->traverse(nums, 0);


    return 0;

}