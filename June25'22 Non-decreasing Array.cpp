class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt=0;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]> nums[i+1]){
                cnt++;
                
                if(cnt> 1) return false;
                // if the prev element is smaller or equal, then make the greater value index small, otherwise make the smaller value element greater--> so as to keep the increasing sequence. 
                if(i==0 || nums[i-1]<= nums[i+1]) nums[i]= nums[i+1];
                else nums[i+1]= nums[i];
            }
        }
        return true;
    }
};
