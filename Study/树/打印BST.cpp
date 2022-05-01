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


class DoBst{
private:
    vector<int> res;

public:
    // 正序
    vector<int>  positiveSequence(TreeNode * root){
        positiveSequenceTraverse(root);
        return res;

    }
    void  positiveSequenceTraverse(TreeNode*  root){
        if(root== nullptr){
            return;
        }
        positiveSequence(root->left);
        res.push_back(root->val);
        positiveSequence(root->right);

    }

    // 逆序
    vector<int> reverseOrder(TreeNode * root){
        reverseOrderTraverse(root);
        return res;


    }
    void  reverseOrderTraverse(TreeNode * root){
        if(root== nullptr){
            return;
        }
        reverseOrderTraverse(root->right);
        res.push_back(root->val);
        reverseOrderTraverse(root->left);

    }






};



int main(){

    return 0;
}
