//the median minimizes the the sum of absolute deviations
// bringing the elements to median will minimize the operations. (and not avg)
// consider example
// 0, 0, 0, 0, 0, 600
// median--> 0 , therefore--> moves = 600.
// mean--> 100 , therefore--> moves = 100 + 100 + 100 + 100 + 100 + 500 = 1000.

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n= nums.size();
        int median, ans=0;
        if(n%2==0){
            median= (nums[n/2] + nums[n/2 -1])/2;
        }
        else median= nums[n/2];
        for(int it: nums){
            ans+= abs(it-median);
        }
        return ans;
    }
};
