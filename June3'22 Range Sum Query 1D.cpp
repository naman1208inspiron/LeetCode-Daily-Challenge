//``````````````naive approach ````````````````````````````````
class NumArray {
    vector<int> v;
public:
    NumArray(vector<int>& nums) {
        v=nums;
    }
    
    int sumRange(int left, int right) {
        int ans=0;
        for(int i=left; i<=right; i++){
            ans+= v[i];
        }
        return ans;
    }
};
//`````````````````````good approach using Prefix Sum````````````````````````
class NumArray {
    vector<int> preSum;
public:
    NumArray(vector<int>& nums) {
        int curr=0;
        for(int it: nums){
            curr+= it;
            preSum.push_back(curr);
        }
    }
    
    int sumRange(int left, int right) {
        return left==0 ? preSum[right]: preSum[right]-preSum[left-1];
    }
};
