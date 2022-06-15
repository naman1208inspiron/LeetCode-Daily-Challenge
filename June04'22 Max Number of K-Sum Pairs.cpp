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
