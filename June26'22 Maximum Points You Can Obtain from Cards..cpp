class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
        int score=0, n= v.size(), totalpts=0;
        //finding prefix sum
        vector<int> preSum(n, 0);
        for(int i=0; i< n; i++){
            totalpts+= v[i];
            if(i==0){
                preSum[i]= v[i]; 
                continue;
            }
            preSum[i]= preSum[i-1]+ v[i];
        }
        
        // totalpts= takenSum + remSum --> minimize remSum to maximize takenSum
        // n-k elements would be remaining.
        
        int curr= n-k;
        int remSum= curr? preSum[curr-1] : 0;
        int lo= 0, hi= curr;
        while(curr < n){
            remSum= min(remSum , preSum[curr]-preSum[lo++]);
            curr++;
        }
        return totalpts-remSum;
    }
    
};
