class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int pair= 0;
        for(int it: nums){
            if( mp.find(k-it)!= mp.end()){
                pair++;
                mp[k-it]==1 ? mp.erase(k-it) : mp[k-it]--;
            }
            else{
                mp[it]++;
            }
        }
        return pair;
    }
};
//``````````````````````````````````O(N log N) `````````````
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int lo= 0, hi= nums.size()-1, pair=0;
        while(lo<hi)
            if(nums[lo]+nums[hi] < k )lo++;
            else if(nums[lo] + nums[hi] > k) hi--;
            else{pair++; lo++; hi--;}
                
        return pair;
    }
};
