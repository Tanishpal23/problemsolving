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
// for every node go left and go right -> find ans

// TC O(idk)
// SC O(idk)

class Solution {

    //defined globally
    int maxAns = 0;

    void findAns(TreeNode* root, bool isleft, int lvl){
        //base case
        if(!root) return;
        
        //update if curr lvl > maxAns
        if( lvl > maxAns ) maxAns = lvl;

        //isleft -> if true -> coming from left -> go right for curr lvl
        //                                      -> start new from same lvl
        if(isleft){
            findAns(root->right, !isleft, lvl+1);
            findAns(root->left, isleft, 1);
        }
        //isleft -> if false -> coming from right -> go left for curr lvl
        //                                      -> start new from same lvl 
        else{
            findAns(root->left, !isleft, lvl+1);
            findAns(root->right, isleft, 1);
        }

        return;
        
    }

public:
    int longestZigZag(TreeNode* root) {
        
        //go right
        findAns(root, false, 0);

        //go left
        findAns(root, true, 0);

        //return maxLeft
        return maxAns;

    }
};