class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>mp;
        int start=0, end=0;
        int longest= 0;
        while(end<s.size()){
            mp[s[end]]++;
            while(mp[s[end]] > 1){
                mp[s[start]]--;
                start++;
            }
            longest= max(longest, end-start+1);
            end++;
        }
        return longest;
    }
};
// what we are doing is that we traverse the array and if we encounter a repeated character, we move our left pointer ahead of the last occ of that repeated character.
