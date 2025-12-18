//Approach
//1. start for every element
//2. take other remaining element in temp
//3. when temp.size() becomes k, put in ans
//4. remove element for temp

class Solution {
public:

    void findAns(int n, int k, vector<vector<int>>& ans,
                 vector<int>& temp, int ind) {

        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        // pruning: ensure enough numbers left
        for (int i = ind; i <= n - (k - temp.size()) + 1; i++) {
            temp.push_back(i);
            findAns(n, k, ans, temp, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;

        findAns(n, k, ans, temp, 1);
        return ans;
    }
};
