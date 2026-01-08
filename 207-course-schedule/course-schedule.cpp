class Solution {

    int n;
    vector<bool> visited;
    vector<bool> pathVis;

    bool dfs(int node, vector<vector<int>>& adjList){
        
        if(visited[node]){
            if(pathVis[node]) return true;
            return false;
        }

        visited[node]=true;
        pathVis[node]=true;

        for(auto neighbour: adjList[node]){
            if(dfs(neighbour, adjList)) return true;
        }

        pathVis[node]=false;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        n = numCourses;
        vector<vector<int>> adjList(n);
        visited.assign(n, false);
        pathVis.assign(n, false);

        for(auto course: prerequisites){

            int u = course[1];
            int v = course[0];

            adjList[u].push_back(v);

        }

        for(int i=0; i<n; i++){
            if(!visited[i]){
                if(dfs(i, adjList)) return false;
            }
        }

        return true;

    }
};