class Solution {
    static bool cmp(int a, int b){
        return a>b;
    }
public:
    int minDeletions(string s) {
      // storing the character's freq
        unordered_map<char, int> mp, tmp;
        for(char c: s){
            mp[c]++;
        }
      //stroing the freq in a vector.
        vector<int> a;
        for(auto it: mp){
            a.push_back(it.second);
        }
        int ans=0;
        // sort(a.begin(), a.end(), cmp);
        for(int it: a){
          // if that freq is already present --> keep decreasing it until it becomes unique.
            if(tmp.count(it)){
                while( it> 0 && tmp.count(it)){
                  // ans variable is increased whenever we decrease the value.
                    it--;
                    ans++;
                }
            }
          // after becoming unique or if it was already unique --> push it into the map.
            tmp[it]++;
        }
        return ans;
    }
};
//```````````````````````````````better looking``````````````````````````````````````````````
class Solution {
    static bool cmp(int a, int b){
        return a>b;
    }
public:
    int minDeletions(string s) {
        unordered_map<char, int> mp, tmp;
        //storing the character freq;
        for(char c: s){
            mp[c]++;
        }
        int ans=0;
        // sort(a.begin(), a.end(), cmp);
        
        for(auto it: mp){
            if(tmp.count(it.second)){
                while( it.second> 0 && tmp.count(it.second)){
                    it.second--;
                    ans++;
                }
            }
            tmp[it.second]++;
        }
        return ans;
    }
};
//````````````````````see better approach in leetcode discuss```````````````````
