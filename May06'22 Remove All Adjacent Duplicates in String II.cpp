class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for(char c: s){
            // if not repeating --> count=1;
            if( st.empty() || st.top().first!= c){
                st.push({c, 1});
            }
            // if repeating --> increase count
            else{
                st.top().second++;
                // if the count == k, pop at that moment itself
                if(st.top().second==k){
                    st.pop();
                }
            }
        }
        
        string ans= "";
        while(!st.empty()){
            int occ= st.top().second;
            while(occ--){
                ans+= st.top().first;  
            }
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
