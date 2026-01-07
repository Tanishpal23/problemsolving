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
    long long totalSum = 0;
    long long maxProd = 0;
    const int MOD = 1e9 + 7;

    //total sum of tree
    void getTotalSum(TreeNode* root) {
        if (!root) return;
        totalSum += root->val;
        getTotalSum(root->left);
        getTotalSum(root->right);
    }

    //postorder to compute subtree sums and maximize product
    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long leftSum  = dfs(root->left);
        long long rightSum = dfs(root->right);

        long long subTreeSum = leftSum + rightSum + root->val;

        // consider cutting edge above this subtree
        long long product = subTreeSum * (totalSum - subTreeSum);
        maxProd = max(maxProd, product);

        return subTreeSum;
    }

    int maxProduct(TreeNode* root) {
        getTotalSum(root);
        dfs(root);
        return maxProd % MOD;
    }
};
