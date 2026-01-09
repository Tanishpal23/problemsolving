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
public:
    
    // This function returns:
    // 1) maximum depth of subtree rooted at 'root'
    // 2) the node which is the answer for this subtree
    pair<int, TreeNode*> dfs(TreeNode* root) {
        
        // Base case: empty node
        if (!root)
            return {0, nullptr};
        
        // Get info from left and right subtrees
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        
        // If left and right subtree depths are equal
        // → deepest nodes exist on both sides
        // → current node is the LCA of deepest nodes
        if (left.first == right.first) {
            return {left.first + 1, root};
        }
        
        // If left subtree is deeper
        // → answer lies completely in left subtree
        if (left.first > right.first) {
            return {left.first + 1, left.second};
        }
        
        // If right subtree is deeper
        // → answer lies completely in right subtree
        return {right.first + 1, right.second};
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};
