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
// Convert Tree to graph.
// Do level order Traversal
// Return lvl-1.

// TC - O(n)
// SC - O(n)

class Solution {

    //Graph and visited
    vector<vector<int>> adjList;
    vector<bool> visited;
    int n = 0;
    
    //Finding val of n
    void findn(TreeNode* root){
        if(!root) return;
        n = max(n, root->val);
        findn(root->left);
        findn(root->right);
    }

    //AdjList 
    void findAdjList(TreeNode* root, int par){
        if(!root) return;

        if(par!=-1){
            int u = par;
            int v = root->val;

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        findAdjList(root->left, root->val);
        findAdjList(root->right, root->val);
        
        return;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        findn(root);

        adjList.assign(n+1, vector<int>());
        visited.assign(n+1, false);

        findAdjList(root, -1);

        int ans = 0;
        queue<int> q;

        q.push(start);
        visited[start] = true;

        //Traversal- level order Traversal
        while(!q.empty()){

            int sz = q.size();

            for(int i=0; i<sz; i++){
                
                int curr = q.front();
                q.pop();

                for(auto neighbour: adjList[curr]){
                    if(!visited[neighbour]){
                        q.push(neighbour);
                        visited[neighbour] = true;
                    }
                }

            }
            ans++;
        }

        return ans-1;
    }
};