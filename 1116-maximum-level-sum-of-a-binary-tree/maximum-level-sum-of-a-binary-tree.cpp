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

 //Approach
 //Lvl order Traversal + maxSum + minLvl
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        
        //Starting lvl = 1 (given)
        int lvl = 1;

        //answer 
        int ans = INT_MAX;

        //queue for bfs -> level order Traversal 
        queue<TreeNode*> q;

        //initial starting node push
        q.push(root);

        //maxSum for ans update
        int maxSum = INT_MIN;

        while(!q.empty()){

            //level order traversal -> so loop till current size
            int sz = q.size();

            //sum for the level
            int sum = 0;

            //loop for all node at this level
            for(int i=0; i<sz; i++){
                
                //take front element
                auto it = q.front();
                q.pop();

                //add it to sum
                sum += it->val;
                
                //push left and right TreeNode if present
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);

            }

            //update maxSum and ans (lvl of maximum sum)
            if(sum > maxSum){
                maxSum = sum;
                ans = lvl;
            }

            //update level after every current lvl processition
            lvl++;

        }

        
        return ans;
    }
};