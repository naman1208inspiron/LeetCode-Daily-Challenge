//
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> ans;
        int n= security.size();
        if(time > n) return ans;
        // calculating the no. of non dec days ahead of each day 
        vector<int> nondec(n, 0);
        for(int i= n-2; i>=0; i--){
            if(security[i]<= security[i+1]) nondec[i]= 1+ nondec[i+1];
        }
        //calculating the no. of non inc days before each day 
        vector<int> noninc(n, 0);
        for(int i= 1; i<n; i++){
             if(security[i]<= security[i-1]) noninc[i]= 1+ noninc[i-1];
        }
        for(int i=time; i<n-time; i++){
            if(noninc[i]>=time && nondec[i]>=time) ans.push_back(i);
        }
        return ans;
    }
};
// ```````````````````````naive solution````````````````````````
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int k) {
        vector<int> ans;
        if(k > security.size()) return ans;
        
        for(int i= k; i<security.size()-k; i++){
            bool leftOk= true, rightOk = true;
            for(int left=i-1; left>= i-k; left--){
                if(security[left] < security[left+1]){
                    leftOk = false;
                    break;
                }
            }
            for(int right=i+1; right<= i+k; right++){
                if(security[right] < security[right-1]){
                    rightOk = false;
                    break;
                }
            }
            if(leftOk && rightOk) ans.push_back(i);
        }
        return ans;
    }
};
