class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int inc= 1, dec= 1;
        // inc means the max len of subseq if the last element contributed in the increasing graph. dec means the max len of the subseq if the last element contributed in the decreasing graph.
        for(int i=1; i<nums.size(); i++){
            if(nums[i] < nums[i-1]){
                // if this is the case, it means graph down, then the previous element must have contributed to wiggle up (graph up).
                dec= inc + 1;
            }
            else if(nums[i] > nums[i-1]){
                inc= dec + 1;
            }
        }
        return max(inc, dec);
    }
};
