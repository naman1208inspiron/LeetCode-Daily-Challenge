typedef pair<int, int> p;
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // space complexity ==> O(k) * 2
        priority_queue<p, vector<p>, greater<p>> pq, tmp;
        // N* log(k);
        for(int i=0; i<nums.size(); i++){
            pq.push({nums[i], i});
            if(pq.size()> k) pq.pop();
        }
        // for arranging the desired numbers acc to the index, we need to sort wrt index.
        while(!pq.empty()){
            int num= pq.top().first, index= pq.top().second;
            pq.pop();
            tmp.push({index, num});
        }
        vector<int> ans;
        while(!tmp.empty()){
            ans.push_back(tmp.top().second);
            tmp.pop();
        }
        return ans;
    }
};
