class Solution {
public:
    int minDistance(string word1, string word2) {
        int n= word1.size(), m= word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
        int len= LCS(word1, word2, n, m, dp);
        
        return n+ m -2*len;
    }
    int LCS(string a, string b, int n, int m, vector<vector<int>>&dp){
        if(n<=0 || m<=0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        
        if(a[n-1]== b[m-1]) return dp[n][m]= 1+ LCS(a, b, n-1, m-1, dp);
        else return dp[n][m]= max(LCS(a, b, n, m-1, dp), LCS(a, b, n-1, m, dp));
    }
};
