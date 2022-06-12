class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int maxi=0;
        int n= nums.size();
        vector<int> pre(n,0);
        pre[0]= nums[0];
        for(int i=1; i<n; i++){
            pre[i]= pre[i-1]+nums[i];
        }
        unordered_map<int,int>mp;
        for(int i=0, j=0; i<n; i++){
            mp[nums[i]]++;
            while(mp[nums[i]]> 1){
                mp[nums[j]]--;
                j++;
            }
            maxi= j>0 ? max(maxi, pre[i]-pre[j-1] ) : max(maxi, pre[i]);
        }
        return maxi;
    }
};
