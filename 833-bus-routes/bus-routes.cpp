// Approach 
// level order Traversal.
// BFS on buses: first take all buses reachable with 1 bus,
// then all buses reachable with 2 buses, and so on


class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        //same source and target
        if(source==target) return 0;

        int n = routes.size();

        //buses that comes at that particular stop
        unordered_map<int, vector<int>> stopToBus;
        for (int i = 0; i < n; i++) {
            for (int stop : routes[i]) {
                stopToBus[stop].push_back(i);
            }
        }

        //queue for processing bfs traversal
        queue<int> q;

        //visBus to check if that bus visited previously or not
        vector<bool> visBus(n, false);

        //visStop to check if that stop processeed or not
        unordered_set<int> visStop;

        // push all buses that can be boarded directly from the source stop
        for(auto bus: stopToBus[source]){
            q.push(bus);
            visBus[bus]=true;
        }

        // number of buses taken so far (BFS level starts from 1)
        int busTaken = 1;

        while(!q.empty()){

            //process all buses at current level
            int sz = q.size();
            for(int i=0; i<sz; i++){
                

                int bus = q.front(); q.pop();

                //check all stops of particular bus 
                for(auto stop: routes[bus]){

                    //if this bus visited target return ans
                    if(stop==target) return busTaken;
                    
                    //if stop processed do not processed again
                    if(visStop.count(stop)) continue;
                    visStop.insert(stop);

                    //push all bus that comes at the stop, where current bus goes..
                    for(auto nextBus: stopToBus[stop]){
                        if(!visBus[nextBus]){
                            q.push(nextBus);
                            visBus[nextBus]=true;
                        }
                    }
                }
            }

            //bus processed -> target not found -> increase bus count
            busTaken++;
        }

        return -1;
    }
};