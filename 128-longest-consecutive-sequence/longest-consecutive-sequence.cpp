class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        unordered_set<int> stt( nums.begin(), nums.end() );
        int maxi = 0;

        for( int x: stt ){
            
            //start jab he kro jab wo first element ho
            if( stt.find( x-1 ) == stt.end() ){
                int cnt = 1;
                int curr = x;

                while( stt.find( curr+1 ) != stt.end() ){
                    cnt++;
                    curr++;
                }

                maxi = max( maxi, cnt );
            }

        }

        return maxi;
    }
};