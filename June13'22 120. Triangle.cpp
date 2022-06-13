//``````````````````````dp tabulation`````````````````````
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n= triangle.size();
        vector<int> minpath= triangle.back();
        for(int i=n-2; i>=0; i--){
            for(int j= 0; j<triangle[i].size(); j++){
                minpath[j]= triangle[i][j]+ min(minpath[j], minpath[j+1]);
            }
        }
        return minpath[0];
    }
};
//`````````````````````the recursive code i wrote```````````````
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int sum=INT_MAX, currSum=0;
        find(triangle, sum, currSum, 0, 0);
        return sum;
    }
    void find(vector<vector<int>>& t, int &sum, int currSum, int row, int index){
        if(row== t.size()){
            sum= min(sum, currSum);
            return;
        }
        for(int i=index; i<t[row].size() && i<index+2; i++){
            currSum+= t[row][i];
            // cout<<it<<" "<<currSum<<endl;
            find(t, sum, currSum, row+1, i);
            currSum-=t[row][i];
        }
    }
};
// ````````````````````````much better than my recursive code + DP`````````````````````````````
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n= triangle.size();
        int m= triangle[n-1].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        return solve(0, 0, triangle, n, dp);
    }
    
    int solve(int row, int col, vector<vector<int>>&triangle, int n, vector<vector<int>>&dp){
        if(row== n-1) return dp[row][col]= triangle[row][col];
        
        if(dp[row][col]!= INT_MAX) return dp[row][col];
        
        int bottom=       triangle[row][col] + solve(row+1, col,   triangle, n, dp);
        int bottom_right= triangle[row][col] + solve(row+1, col+1, triangle, n, dp);
        
        return dp[row][col] = min(bottom, bottom_right);
    }
};
