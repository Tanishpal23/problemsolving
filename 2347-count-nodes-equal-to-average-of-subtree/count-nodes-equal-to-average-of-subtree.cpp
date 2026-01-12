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
// find avg and height for each subtree.
// if equal add to ans/cnt;


class Solution {

    //ans count
    int cnt = 0;

    //pair -> total no of children nodes, sum of children nodes
    pair<int, int> findAns(TreeNode* root){

        //if not root -> return 0, 0
        if(!root) return {0, 0};

        //children nodes while returning
        auto it1 = findAns(root->left);
        auto it2 = findAns(root->right);

        //Children Height
        int leftTreeH = it1.first;
        int rightTreeH = it2.first;

        //Children Sum
        int leftSum = it1.second;
        int rightSum = it2.second;
        
        //Sum including Curr Node
        int currSum = root->val + leftSum + rightSum;

        //Total Nodes including Curr Node 
        int currHeight = 1 + leftTreeH + rightTreeH;

        //If equal increase cnt
        if( root->val == (currSum/currHeight) ) cnt++;

        //return currHeight, currSum
        return {currHeight, currSum};

    }
public:
    int averageOfSubtree(TreeNode* root) {
        
        //function call
        findAns(root);

        //return ans
        return cnt;

    }
};