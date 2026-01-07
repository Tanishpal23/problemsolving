// Approach
// Sort -> for lexicographical order
// check all combination -> Brute force

// TC O(n^4)
// SC O(1)

class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        int n = words.size();

        sort(words.begin(), words.end());
        vector<vector<string>> ans;


        for(int i=0; i<n; i++){

            for(int j=0; j<n; j++){

                for(int k=0; k<n; k++){

                    for(int l=0; l<n; l++){

                        if(i==j || j==k || k==l || i==k || i==l || j==l) continue;

                        string top = words[i];
                        string left = words[j];
                        string right = words[k];
                        string bottom = words[l];

                        if( (top[0] == left[0]) && (top[3]==right[0]) && (bottom[0]==left[3]) 
                            && (bottom[3]==right[3]) ){
                                ans.push_back({top, left, right, bottom});
                            }
                    }
                }
            }
        }

        return ans;
    }
};