class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> st;
        for(int it: nums){
            st.insert(it);
            if(st.size()> 3){
                st.erase(st.begin());
            }
        }
        
        // if(st.size()<3){
        //     while(st.size()!=1) st.erase(st.begin());
        // }
        
        return st.size()< 3 ? *st.rbegin() : *st.begin()  ;
    }
};
