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
    int maxlvl = 0;
    int ans = 0;
    void findans(TreeNode* root, int lvl){
        if(!root)return;

        if(lvl > maxlvl){
            ans = root->val;
            maxlvl = lvl;
        }

        findans(root->left, lvl+1);
        findans(root->right, lvl+1);

        return;

    }
public:
    int findBottomLeftValue(TreeNode* root) {
        ans = root->val; int lvl = 0;
        findans(root, lvl);
        return ans;
    }
};