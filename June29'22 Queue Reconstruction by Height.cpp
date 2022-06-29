// place each person on its correct position
// correct position--> k denotes the person with height greater than that person in front of it. So leave that much 'empty' space in the front and insert that person in the array.

class Solution {
    static bool cmp(vector<int> a, vector<int> b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0] < b[0];
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> ans(people.size(), vector<int>() );
        
        for(int i=0; i<people.size(); i++){
            int h= people[i][0];
            int pos= people[i][1];
            
            for(int j=0; j<people.size(); j++){
                if(ans[j].empty()){
                    if(pos==0){
                        ans[j]= people[i];
                        break;
                    } 
                    pos--;
                } 
            }
        }
        return ans;
    }
};
