// You are given a string s consisting only of letters 'a' and 'b'. In a single step you can remove one palindromic subsequence from s.
// Return the minimum number of steps to make the given string empty.
Return the minimum number of steps to make the given string empty.
class Solution {
public:
    int removePalindromeSub(string s) {
        if(isPalindrome(s)) return 1;
        return 2;
    }
    bool isPalindrome(string s){
        for(int i=0; i<s.size()/2; i++){
            if(s[i]!= s[s.size()-i-1]) return false;
        }
        return true;
    }
};
