class Solution {
public:
    int minPartitions(string n) {
        int ans=0;
        for(char c: n){
            int digit= c-'0';
            ans= max(ans, digit);
        }
        return ans;
    }
};
