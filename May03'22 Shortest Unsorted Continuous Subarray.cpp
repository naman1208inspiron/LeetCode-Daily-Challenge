class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> arr= nums;
        sort(nums.begin(), nums.end());
        int n= nums.size();
        int i=0, j= n-1;
        while(i<n && nums[i]== arr[i]){
            i++;
        }
        while(j>i && nums[j]== arr[j]){
            j--;
        }
        return j-i+1;
    }
};
