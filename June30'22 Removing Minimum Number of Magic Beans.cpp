class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n= beans.size();
        long long ans= LLONG_MAX, sum=0, curr;
        
        for(int it: beans) sum+= it;
        
        sort(beans.begin(), beans.end());
        // checking for which element we will need to remove minimum beans.
        for(int i=0; i<n; i++){
            // number of beans after making the beans in all bags equal to beans[i]
            curr= (long long) (n-i)*beans[i];
            ans= min( ans, sum-curr );
        }
        return ans;
    }
};
