/*
 * @Author: your name
 * @Date: 2022-05-02 22:20:51
 * @LastEditTime: 2022-05-02 23:22:46
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE#
 * @FilePath: \tree\二叉搜索树.cpp
 */
#include "bits/stdc++.h"

using namespace std;


vector<int> tree_node = {12, 4, 0, 7, 9, 5, 3, 8};

template<class T>
struct TreeNode {
    T val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() = default;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}

    ~TreeNode();
};


template<class T>
class DOTree {


public:
    // 二叉搜索树的创建

    TreeNode<int> *Binary_Search_Tree_Create(TreeNode<T> *root, const T &val) {
        if (root == nullptr) {
            root = new TreeNode<T>(val);
            return root;
        }

        if (root->val < val) {
            root->right = Binary_Search_Tree_Create(root->right, val);
        } else if (root->val > val) {
            root->left = Binary_Search_Tree_Create(root->left, val);

        }


        return root;

    }

    // 二叉树的zhong序遍历
    void postorder_traversal(const TreeNode<T> *root) {
        if (root == nullptr) return;
        postorder_traversal(root->left);
        printf("%d ", root->val);
        postorder_traversal(root->right);
    }


};


int main(void) {
    DOTree<int> Tree;
    TreeNode<int> *head = nullptr;

//    head = Tree.Binary_Search_Tree_Create(head, 2);

    for(auto &i : tree_node){
        head = Tree.Binary_Search_Tree_Create(head, i);

    }
//
    Tree.postorder_traversal(head);

    return 0;
}






