class Solution {

    using pii = pair<int, int>;
public:
    vector<int> getStrongest(vector<int>& arr, int k) {

        int n = arr.size();
        sort(arr.begin(), arr.end());

        int m = arr[(n-1)/2];
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        for(auto num: arr){
            int dif = abs(num-m);

            if(pq.size() < k){
                pq.push( {dif, num} );
            }else if(pq.top().first <= dif){
                pq.pop();
                pq.push( {dif, num} );
            }

        }

        vector<int> ans;
        for(int i=0; i<k; i++){
            if( !pq.empty() ){
                ans.push_back(pq.top().second);
                pq.pop();
            }else break;
        }

        return ans;
    }
};