#include <bits/stdc++.h>


using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 层序遍历
class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {\
        TreeNode * ans=root;
        while (true){
            if(p->val< ans->val && q->val<ans->val ){

                ans=ans->left;
            }else if(ans->val>)


        }



    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
