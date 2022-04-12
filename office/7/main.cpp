#include <iostream>
#include <vector>
#include <bits/stdc++.h>


using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// 前序遍历性质 preorder ： 节点按照 [ 根节点 | 左子树 | 右子树 ] 排序。
// 中序遍历性质 inorder ： 节点按照 [ 左子树 | 根节点 | 右子树 ] 排序。


class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {

        this->preorder = preorder;

        // 将中序序列用哈希表存储，便于查找根节点

        for (int i = 0; i < inorder.size(); i++)
            dic[inorder[i]] = i;
        // 传入参数：前序序列根节点，中序序列左边界，中序序列右边界

        return recur(0, 0, inorder.size() - 1);
    }

private:

    vector<int> preorder;

    unordered_map<int, int> dic;

    TreeNode *recur(int root, int left, int right) {
        if (left > right) return nullptr;                        // 递归终止
        TreeNode *node = new TreeNode(preorder[root]);          // 建立根节点
        int i = dic[preorder[root]];                            // 划分根节点、左子树、右子树
        node->left = recur(root + 1, left, i - 1);              // 开启左子树递归
        node->right = recur(root + i - left + 1, i + 1, right); // 开启右子树递归
        return node;                                            // 回溯返回根节点
    }
};


class Solution2 {
private:
    vector<int> preorder;
    vector<int> inorder;

public:


    unordered_map<int,int> map;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         this->preorder=preorder;
         this->inorder=inorder;

        // 将中序序列用哈希表存储，便于查找根节点
        for(int i = 0;i < inorder.size();i++)
            map[inorder[i]] = i;

        // 传入参数：前序,中序，前序序列根节点，中序序列左边界，中序序列右边界

        return build(0,0,inorder.size()-1);
    }
    TreeNode* build(int pre_root,int in_left,int in_right){
        if(in_left > in_right)
            return NULL;

        TreeNode* root = new TreeNode(preorder[pre_root]);

        // 根节点在中序序列中的位置，用于划分左右子树的边界

        int in_root = map[preorder[pre_root]];

        // 左子树在前序中的根节点位于：pre_root+1,左子树在中序中的边界：[in_left,in_root-1]
        root->left = build(pre_root+1,in_left,in_root-1);
        // 右子树在前序中的根节点位于：根节点+左子树长度+1 = pre_root+in_root-in_left+1
        // 右子树在中序中的边界：[in_root+1,in_right]
        root->right = build(pre_root+in_root-in_left+1,in_root+1,in_right);
        return root;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
