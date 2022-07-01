class Solution {
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1] > b[1];
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int maxUnit=0, i=0;
        
        while(truckSize > 0 && i < boxTypes.size() ){
            int boxTaken= min(truckSize, boxTypes[i][0]);
            maxUnit += boxTypes[i][1]* min(truckSize, boxTypes[i][0]);
            truckSize-= boxTaken;
            i++;
        }
        return maxUnit;
    }
};
