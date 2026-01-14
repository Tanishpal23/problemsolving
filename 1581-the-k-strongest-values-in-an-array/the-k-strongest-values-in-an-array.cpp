class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {

        int n = arr.size();
        sort(arr.begin(), arr.end());

        int m = arr[(n-1)/2];
        vector<pair<int,int>> temp;

        for(auto num: arr){
            temp.push_back({abs(num-m), num});
        }
        
        sort(temp.rbegin(), temp.rend());

        vector<int> ans;
        for(int i=0; i<k; i++){
            if( i < n ){
                ans.push_back(temp[i].second);
            }else break;
        }

        return ans;
    }
};