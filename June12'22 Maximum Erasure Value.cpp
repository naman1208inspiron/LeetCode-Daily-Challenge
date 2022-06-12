class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int maxi=0;
        int n= nums.size();
        vector<int> pre(n,0);
        pre[0]= nums[0];
        for(int i=1; i<n; i++){
            pre[i]= pre[i-1]+nums[i];
        }
        unordered_map<int,int>mp;
        for(int i=0, j=0; i<n; i++){
            mp[nums[i]]++;
            while(mp[nums[i]]> 1){
                mp[nums[j]]--;
                j++;
            }
            maxi= j>0 ? max(maxi, pre[i]-pre[j-1] ) : max(maxi, pre[i]);
        }
        return maxi;
    }
};
//`````````````````````````````````using frequecy array ````````````````````````````````````
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int maxi=0;
        int n= nums.size();
        int currSum=0;
        
        bool freq[100001]= {false};
        
        for(int i=0, j=0; i<n; i++){
            //first check if the num is already present or not
            while(freq[nums[i]]){
                freq[nums[j]]= false;
                currSum-= nums[j];
                j++;
            }
            freq[nums[i]]= true; 
            currSum+= nums[i];
            maxi= max(maxi, currSum);
        }
        return maxi;
    }
};
