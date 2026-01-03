// Approach
// Take alternative colours and keep different distance vector for both 

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {

        //Seperate adjList for both coloue Edges
        vector<vector<int>> adjListBlue(n);
        vector<vector<int>> adjListRed(n);

        //adjListRed
        for(auto edge: redEdges){
            int u=edge[0], v=edge[1];
            adjListRed[u].push_back(v);
        }

        //adjListBlue
        for(auto edge: blueEdges){
            int u=edge[0], v=edge[1];
            adjListBlue[u].push_back(v);
        }

        //Dist and visited array... bfs will always give minimum dist as we are traversing
        //level wise
        vector<int> blueDist(n, INT_MAX);
        vector<int> redDist(n, INT_MAX);

        //Starting node 
        blueDist[0]=0, redDist[0]=0;

        //queue to store node and colour by which it was reached
        //true->red, false->blue 
        queue<pair<int, bool>> q;

        //check for both at starting
        q.push({0, true});   // last edge was BLUE → next must be RED
        q.push({0, false});  // last edge was RED  → next must be BLUE

        while(!q.empty()){

            //front element
            auto it = q.front(); q.pop();

            //node
            int node = it.first;
            //colour by which that node reached
            bool col = it.second;

            for(auto neighbour: (col? adjListRed[node]: adjListBlue[node])){
                if(col) {
                    // last was BLUE → update RED distance
                    if(redDist[neighbour] == INT_MAX) {
                        redDist[neighbour] = blueDist[node] + 1;
                        q.push({neighbour, false});
                    }
                } else {
                    // last was RED → update BLUE distance
                    if(blueDist[neighbour] == INT_MAX) {
                        blueDist[neighbour] = redDist[node] + 1;
                        q.push({neighbour, true});
                    }
                }
            }
        }

        //take min of both red and blue node
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            int best = min(redDist[i], blueDist[i]);
            ans[i] = (best == INT_MAX ? -1 : best);
        }
        return ans;
    }
};