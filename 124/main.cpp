#include <iostream>
#include <limits>
#include <climits>


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int res=INT_MIN;
public:
    int maxPathSum(TreeNode* root) {

        oneSideMax(root);
        return res;





    }
    int oneSideMax(TreeNode * root){

        if(root== nullptr){

            return 0;
        }
        int left=max(0, oneSideMax(root->left));
        int right=max(0, oneSideMax(root->right));
        this->res=max(this->res,left+right+root->val);

        return max(left,right)+root->val;




    }


};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
