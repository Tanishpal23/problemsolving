class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {

        int n = plants.size();

        int ans = 0;

        int currWater = capacity;

        for(int i=0; i<n; i++){
            int currReq = plants[i];

            if( currWater < currReq ){
                ans += (i+i+1);
                currWater = capacity;
            }else{
                ans += 1;
            }

            currWater -= currReq;
        }

        return ans;
    }
};