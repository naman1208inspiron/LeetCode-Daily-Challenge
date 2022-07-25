class Solution {
public:
    void searchLeftOcc(int lo, int hi, vector<int> &nums, int target, int & first){
        while(lo <= hi){
            int mid= lo + (hi-lo)/2;
            if(nums[mid] > target) hi= mid-1;
            else if(nums[mid] < target) lo= mid+1;
            else{
                first= mid;
                hi= mid-1;
            }
        }
    }
    void searchRightOcc(int lo, int hi, vector<int> &nums, int target, int & last){
        while(lo <= hi){
            int mid= lo + (hi-lo)/2;
            if(nums[mid] > target) hi= mid-1;
            else if(nums[mid] < target) lo= mid+1;
            else{
                last= mid;
                lo= mid+1;
            }
        }
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int f=-1, l=-1, lo= 0, hi= nums.size()-1;
        
        searchLeftOcc(lo, hi, nums, target, f);
        searchRightOcc(lo, hi, nums, target, l);
        
//         while(lo <= hi){
//             int mid= lo + (hi-lo)/2;
//             if(nums[mid] > target) hi= mid-1;
//             else if(nums[mid] < target) lo= mid+1;
            
//             else{
//                 f= mid, l= mid;
//                 // searching left and right part
//                 int lo1= lo, hi1= mid-1, lo2= mid+1, hi2= hi;
                
//                 searchLeft(lo1, hi1, nums, target, f);
//                 searchRight(lo2, hi2, nums, target, l);
//                 break;
//             }
//         }
        return {f, l};
    }
};
