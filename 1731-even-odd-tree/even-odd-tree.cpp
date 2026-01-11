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
 //Do as statement says

//  TC O(n)
//  SC O(n)

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {

        //Level -> odd or even
        bool isOddLvl = false;

        //queue for traversal
        queue<TreeNode*> q;

        //push root node
        q.push(root);

        //level order traversal 
        while(!q.empty()){
            
            //size of current lvl
            int sz = q.size();

            //prev for increasing decreasing check
            int prev = 0;

            //loop all node of current level
            for(int i=0; i<sz; i++){
                
                //Take front element
                auto it = q.front();
                q.pop();
                
                //Statement condn
                if( !isOddLvl ){
                    if( it->val % 2 == 0 ) return false;
                    if( i!=0 && it->val <= prev ) return false;
                }else{
                    if( it->val % 2 == 1 ) return false;
                    if( i!=0 && it->val >= prev ) return false;
                }
                
                //push forward tree
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);

                //update prev for increasing decreasing check
                prev = it->val;

            }

            //Reversal odd even level
            isOddLvl = !isOddLvl;

        }

        //if traversal completes without any hindrance return true
        return true;
    }
};