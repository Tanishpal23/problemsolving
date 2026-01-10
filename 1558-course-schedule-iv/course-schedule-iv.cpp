// Approach
// we need something that can tell in O(1) if nodeA is reachable through nodeB (directly or indirectly)
// Now Floyd warshall algo -> gives shortest dist between every two nodes in graph.
// Modify it to bool -> if reachable or not.

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        int n = numCourses;

        //dist(vector) modified to Reachable vector.
        vector<vector<bool>> isReachable(n, vector<bool>(n, false));

        // direct prerequisite relationships
        for(auto course: prerequisites){
            int u = course[1], v = course[0];
            isReachable[v][u] = true;
        }

        //Floyd Warshall algorithm
        for(int via=0; via<n; via++){
            for(int i=0; i<n; i++){
                
                if(!isReachable[i][via]) continue;

                for(int j=0; j<n; j++){
                    if(isReachable[via][j]){
                        isReachable[i][j] = true;
                    }
                }
            }
        }

        vector<bool> ans;
        
        //Process the queries.
        for(auto query: queries){
            int u = query[0], v = query[1];
            ans.push_back(isReachable[u][v]);
        }

        return ans;
    }
};