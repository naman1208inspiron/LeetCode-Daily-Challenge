class Solution {
public:
    static bool cmp(string a, string b){
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) {
        // map will store the stirng and the longest string chain length with that stirng as the largest word.
        unordered_map<string, int> mp;
        int maxi= INT_MIN;
        //sorting the vector acc to the len of words
        sort(words.begin(), words.end(), cmp);
        
        for(string word: words){
            //inserting the default value of len of string chain.
            mp[word]= 1;
            for(int i=0; i<word.size(); i++){
                string curr= word;
                //deleting each char in that word using for loop
                curr.erase(i, 1);
                //checking if that deleted char present in map or not.
                if(mp.find(curr)!= mp.end()){
                    // if present -> update the len of longest string chain as
                    // len->that word= max(already present val, 1+ prev string value)
                    mp[word]= max(mp[word], 1+mp[curr] );
                }
            }
            // taking the ans as the max of all the values present in the map
            maxi= max(maxi, mp[word]);
        }
        return maxi;
    }
};
