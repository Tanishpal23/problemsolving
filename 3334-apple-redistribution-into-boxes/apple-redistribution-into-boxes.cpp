//Approach
//1. Find some of all apples
//2. Use greedy approach to fill apples in box.

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {

        int m = capacity.size();
        int sum = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.rbegin(), capacity.rend());

        for(int i=0; i<m; i++){

            // cout<<capacity[i]<<" ";
            sum-=capacity[i];
            if(sum<=0) return i+1;

        }

        return m;
    }
};