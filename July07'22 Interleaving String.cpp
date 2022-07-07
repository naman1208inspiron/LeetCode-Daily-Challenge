// approach --> make all the interleaving strings possible. 

class Solution {
    int dp[101][101];
    bool solve(string s1, int a, string s2, int b, string temp, string s3, int k){
        if(a== s1.size()) return s2.substr(b)== s3.substr(k);
        if(b== s2.size()) return s1.substr(a)== s3.substr(k);
        
        if(dp[a][b]!= -1){
            return dp[a][b]==1 ? true : false;
        }
        
        // including char at index a from s1 only if it is equal to the corresponding char at s3.
        if(s1[a] == s3[k] && solve(s1, a+1, s2, b, temp+s1[a], s3, k+1)){
            dp[a][b]= 1;
            return true;
        }
        
        // including char at index b from s2
        if(s2[b]== s3[k] && solve(s1, a, s2, b+1, temp+s2[b], s3, k+1)){
                dp[a][b]= 1;
                return true;
        }

        dp[a][b]= 0;
        return false;
    }
public:
    
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size()) {
            return false;
        }
        memset(dp, -1, sizeof(dp));
        string temp= "";
        return solve(s1, 0, s2, 0, temp, s3, 0);
    }
    
};
