class Solution {
        void dfs( vector<bool>& vis, vector<vector<int>>& rooms, int curr ){
            
            if( vis[curr] ) return;

            vis[curr] = true;

            for( auto neighbour: rooms[curr] ){
                dfs( vis, rooms, neighbour );
            }

        }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        cout << n << endl;
        vector<bool> vis(n, false);

        vis[0] = true;
        for(auto neighbour: rooms[0]){
            
            dfs( vis, rooms, neighbour );

        }

        for(auto b: vis){
            if(b==false) return false;
        }
        

        return true;
    }
};