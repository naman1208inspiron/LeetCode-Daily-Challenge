class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum=0;
        for(int it: nums) totalSum += it;
        
        //we need to find==> longest subarray with sum as totalSum- x;
        int currSum=0, maxLen=-1;
        
        for(int l=0, r=0; r<nums.size(); r++){
            
            currSum += nums[r];
            
            //sliding the windom if the sum is greater than req
            while(l<=r && currSum> totalSum-x) 
                currSum-= nums[l++];
            
            if(currSum== totalSum-x)
                maxLen= max(maxLen, r-l+1);
        }
        return maxLen== -1 ? -1 : nums.size()-maxLen;
    }
};
