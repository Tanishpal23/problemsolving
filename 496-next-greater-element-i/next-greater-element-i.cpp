class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();

        stack<int> st; //min stack 
        unordered_map<int, int> mpp;
        vector<int> ans;

        for( int i=0; i<n; i++ ){

            int num = nums2[n-i-1];
            while( !st.empty() && st.top() < num ) st.pop();

            if( st.empty() )mpp[num] = -1;
            else mpp[num] = st.top();

            st.push( num );

        }

        for( auto num: nums1 ){
            ans.push_back( mpp[num] );
        }
        
        return ans;
    }
};