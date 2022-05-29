class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n= words.size();
        vector<int> word_int;
        
        for(int i=0; i<n; i++){
            string w= words[i];
            int w_int =0;
            // here we are converting each stirng to a equivalent binary form by taking or in a for loop. a-> 1, b-> 10, c-> 100, d-> 1000 and so on.....
            for(int j=0; j<w.length(); j++){
                w_int |= 1<<(w[j]-'a');
            }
            word_int.push_back(w_int);
        }
        int maxi=0;
        for(int i=0; i<n; i++){
            for(int j= i+1; j<n; j++){
                if((word_int[i] & word_int[j]) == 0){\
                    // if bitwise and operator is 0, it means that the binary numbers have all the corresponding bits different, so the strings would be different. 
                    int l= words[i].size() * words[j].size();
                    maxi= max (maxi, l);
                    // maxi= max(maxi, words[i].size() * words[j].size());
                }
            }
        }
        cout<<word_int[0];
        return maxi;
    }
};
