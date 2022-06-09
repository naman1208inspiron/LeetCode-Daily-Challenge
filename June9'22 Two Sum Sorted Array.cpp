class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<int> v;
        int i=0, j= nums.size()-1;
        while(i<j){
            if(nums[i]+nums[j]<target) i++;
            else if(nums[i]+ nums[j]>target) j--;
            else{
                // v.push_back(i+1); v.push_back(j+1);
                break;
            }
        }
        return {i+1, j+1};
    }
};
