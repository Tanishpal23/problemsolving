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

// Approach
// Left wali node ko right wali node se replace krnege
// only values swap krni hai

// TC - O(n)
// SC - O(n)

class Solution {

    void reverseTreeNode(TreeNode* root1, TreeNode* root2, bool flg){
        
        //base case
        if(!root1||!root2) return;

        //only for odd levels
        if(flg){
            int temp = root1->val;
            root1->val = root2->val;
            root2->val = temp;
        }

        //call for children
        if(root1->left) reverseTreeNode(root1->left, root2->right, !flg);
        if(root1->right) reverseTreeNode(root1->right, root2->left, !flg);

        return;
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {

        //function call
        reverseTreeNode(root->left, root->right, true);
        return root;
    }
};