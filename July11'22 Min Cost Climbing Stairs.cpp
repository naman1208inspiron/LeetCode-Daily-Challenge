class Solution {
public:
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        int dp[n+1];
        memset(dp, -1, sizeof(dp));
        
        return min(find(0, cost, dp), find(1, cost, dp));
    }
    //find step to reach at the top if you stand at the index - ind.
    int find(int ind, vector<int>&cost, int dp[]){
        if(ind >= cost.size() ) return 0;
        
        if(dp[ind]!= -1) return dp[ind];
        //taking the next step from curr index
        int nxt= cost[ind] + find(ind+1, cost, dp);
        
        //taking the next to next step from the curr index.
        int nxtToNxt= cost[ind] + find(ind+2, cost, dp);
        
        return dp[ind] = min(nxt, nxtToNxt);
    }
};
