class Solution {
public:
    bool chk(string &a, string &b){
        unordered_map<char, char> mp;
        for(int i=0; i<a.size(); i++){
            if(mp.find(a[i])!= mp.end()){
                if(b[i]!= mp[a[i]]) return false;
            }
            else mp[a[i]]= b[i];
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto it: words){
            if(chk(it, pattern) && chk(pattern, it)) ans.push_back(it);
        }
        return ans;
    }
};
