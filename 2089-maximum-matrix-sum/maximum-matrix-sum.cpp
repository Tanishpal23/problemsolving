// Appraoch
// we can make (any element) negative
// so we will try to make all element positive
// but if one element remains negative it cannot to made positive, but its value can be reduced
// for than we can either reduce by positive to negative

// TC - O(n*n)
// SC - O(1)
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();

        // ans
        long long ans = 0;
        
        //mini -> minimum element -> (will try to make other postive except this)
        int mini = INT_MAX;

        //negCount -> no of negative elements -> if even -> all can be made positive 
        //if odd -> we subtract mini from ans twice.
        //twice because -> think....
        int negCount = 0;

        //loop
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){

                //ans -> total 
                ans+=abs(matrix[i][j]);

                //negCount condn
                if(matrix[i][j]<=0){
                    negCount++;
                }

                //mini update
                mini = min(abs(matrix[i][j]), mini);
            }
        }

        //if negCount == odd....
        if(negCount%2){
            ans -= (2*mini);
        }

        return ans;
    }
};