// ``````````````````simple method`````````````````````
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int currSum=0;
        vector<int> ans;
        for(int it: nums){
            currSum+= it;
            ans.push_back(currSum);
        }
        return ans;
    }
};
// ```````````````````better approach ==> prefix sum`````````````````````````````
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i=1; i<nums.size(); i++){
            nums[i]+= nums[i-1];
        }
        return nums;
    }
};
