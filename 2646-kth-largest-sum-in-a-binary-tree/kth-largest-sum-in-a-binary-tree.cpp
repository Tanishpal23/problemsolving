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
// Level order traversal with sum. Kth largest -> PQ
// Error -> Not handled edge case for k lesser than no of level.

class Solution {
    using ll = long long;
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        //minPQ to have kth largest element at top
        priority_queue<ll, vector<ll>, greater<ll>> pq;

        //queue for traversal
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){

            int sz = q.size();
            long long sum = 0;

            //current level traversal for sum 
            for(int i=0; i<sz; i++){

                auto it = q.front();
                q.pop();

                sum += (it->val);

                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);

            }
            
            //PQ logic to handle kth largest at top -> have PQ of size k
            if(pq.size() < k){
                pq.push(sum);
            }else{
                if(sum>pq.top()){
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
        
        //Return -1 if not sufficient level.
        return pq.size()<k ? -1: pq.top();
    }
};