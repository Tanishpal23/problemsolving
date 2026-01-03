// Approach
// Bipartitiate graph
// dislikes -> should have different colours.
// Make graph of dislikes -> assign different colours (group) to adjacent nodes

// TC O(n + m) -> n nodes , m -> edges
// SC O(n + m)

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        //Graph inititalisation in form of adjList 
        vector<vector<int>> adjList(n+1);
        for(auto edge: dislikes){
            int u = edge[0], v=edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        //group will be assigned here
        vector<int> grp(n+1, -1);

        //queue for bfs traversal
        queue<int> q;

        //check for connected components of graph
        for(int i=1; i<=n; i++){

            //if not grouped yet
            if(grp[i]==-1){
                
                //assign 0th group initially
                q.push(i);
                grp[i]=0;

                //bfs starts
                while(!q.empty()){

                    int node = q.front();
                    q.pop();

                    //check and assign neighbours of curr node
                    for(auto neighbour: adjList[node]){
                        
                        //if neighbour already assigned grp check if grp same as node 
                        if(grp[neighbour] != -1 && grp[neighbour]==grp[node]) return false;
                        
                        //if neighbour not visited yet assign different grp than curr node grp
                        if(grp[neighbour]==-1){
                            grp[neighbour] = !grp[node];
                            q.push(neighbour);
                        }

                    }
                }
            }
        }
        
        //if all nodes provided grp return true
        return true;

    }
};