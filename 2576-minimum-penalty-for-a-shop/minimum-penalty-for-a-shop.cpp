// Approach
// 1. Calculate penalty taking shop always closed. (total no of Y)
// 2. Move from left to right and calculate (new) penalty for every index.
// 3. If penalty becomes lesser than minpenalty. Update minpenalty and ans index.

// TC - O(n)+O(n) = O(n)
// SC - O(1);

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        //Calculating total no of Y -> penalty if shop never opens
        int penalty = 0;
        for(auto i: customers){
            if(i=='Y') penalty++;
        }

        //minpenalty for updating ans index
        int minpenalty = penalty;
        int ans = 0;

        //moving from left to right -> if 'Y' penalty reduce by 1, if 'N' penalty increase by 1
        //if penalty becomes lesser than minpenalty ... ans update.
        for(int i=0; i<n; i++){
            if(customers[i]=='Y') penalty--;
            else penalty++;

            if(penalty < minpenalty){
                minpenalty = penalty;
                ans = i+1;
            }
        }

        return ans;
    }
};