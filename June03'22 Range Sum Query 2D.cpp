//`````````````````````O(n) time ``````````````````````
class NumMatrix {
    vector<vector<int>> preSum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        for(int i=0; i<matrix.size(); i++){
            vector<int> temp;
            int curr= 0; 
            for(int j=0; j<matrix[0].size(); j++){
                curr+= matrix[i][j];
                temp.push_back(curr);
            }
            preSum.push_back(temp);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=0;
        for(int i=row1; i<=row2; i++){
            if(col1==0) ans+= preSum[i][col2];
            else ans+= preSum[i][col2]- preSum[i][col1-1];
        }
        return ans;
    }
};
//``````````````````````O(1) solution ````````````````````````````````
class NumMatrix {
public:
    int dp[201][201]={0};
    NumMatrix(vector<vector<int>>& matrix) {
        int n= matrix.size(), m= matrix[0].size();
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                dp[i][j]= dp[i-1][j] + dp[i][j-1] + matrix[i-1][j-1] - dp[i-1][j-1];
            }
        }
        // dp[i][j] contains the sum of all elements from matrix[0][0] to matrix[i-1][j-1];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans= dp[row2+1][col2+1] - dp[row1][col2+1] - dp[row2+1][col1] + dp[row1][col1];
        return ans;
    }
};
