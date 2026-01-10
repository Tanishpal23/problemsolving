// Approach:
// Traverse from each unvisited node using array indexing.
// Use vis[] to mark global visits and step[] to track steps in current traversal.
// When a node is revisited in the same traversal, calculate cycle length.

class Solution {
public:
    
    int longestCycle(vector<int>& edges) {

        int n = edges.size();
        
        // mark visited nodes globally
        vector<bool> vis(n, false);

        // step when node is first visited in current path     
        vector<int> step(n, -1); 

        // store max cycle length       
        int maxCnt = -1;                

        for(int i = 0; i < n; i++){

            // skip if already visited
            if(vis[i]) continue;        

            int curr = i;

            // step counter for current traversal
            int cnt = 0;                

            // traverse along edges until dead end or visited node
            while(curr != -1 && !vis[curr]){
                vis[curr] = true;
                step[curr] = cnt;       // record step
                cnt++;
                curr = edges[curr];     // move to next node
            }

            // check if we found a cycle in this traversal
            if(curr != -1 && step[curr] != -1){
                // update max cycle length
                maxCnt = max(maxCnt, cnt - step[curr]); 
            }

            // reset step[] for nodes in this traversal
            curr = i;
            while(curr != -1 && step[curr] != -1){
                int next = edges[curr];
                step[curr] = -1;
                curr = next;
            }
        }

        return maxCnt;
    }
};
