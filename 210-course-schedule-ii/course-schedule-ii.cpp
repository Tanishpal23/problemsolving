// Approach
// TopoSort -> if there exist edge from u to v -> then u comes before v in topoSort
// Find topo Sort -> if cycle detected -> return {} vector.

// Topo Sort - stack approach
// Do normal dfs traversal while returning back put to stack.

// TC - O(V+E)
// SC - O(V+E)

class Solution {
    
    //declared globally
    int n;
    vector<int> topoSort;
    vector<vector<int>> adjList;
    vector<bool> vis;
    vector<bool> pathVis;
    stack<int> st;

    //dfs for cycle detection
    bool dfs(int node){

        //if pathVis return true -> cycle detected
        if(pathVis[node]) return true;

        //if already visited return false -> No cycle detected
        if(vis[node]) return false;

        //vis and pathVis updation
        vis[node] = true;
        pathVis[node] = true;

        //dfs traversal for all adjacent nodes
        for(auto neighbour: adjList[node]){

            //if true -> cycle detected
            if(dfs(neighbour)) return true;
        }

        //while returning back put to stack -> this will give valid topoSort
        st.push(node);
        pathVis[node] = false;

        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        n = numCourses;
        adjList.assign(n, vector<int>());
        vis.assign(n, false);
        pathVis.assign(n, false);

        //make adjList
        for(auto course: prerequisites){

            int u = course[1];
            int v = course[0];

            adjList[u].push_back(v);

        }

        //connected component in graph
        for(int i=0; i<n; i++){
            if(dfs(i)) return {};
        }

        //remove from stack put to vector.
        while(!st.empty()){
            topoSort.push_back(st.top());
            st.pop();
        }

        //return ans
        return topoSort;

    }
};