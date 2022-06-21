class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int i=0, n= heights.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        
        // while(i < n-1 && ladders){
        //     int jumpH= heights[i+1]-heights[i];
        //     if(jumpH > 0) pq.push(jumpH), ladders--;
        //     i++;
        // }
        
        // use ladder for bigger jump, and bricks for smaller jump
        // we need to store the first L difference in pq.
        while(i < n-1 && size(pq)<ladders){
            int jumpH= heights[i+1]-heights[i];
            if(jumpH > 0) pq.push(jumpH);
            i++;
        }
        while(i<n-1){
            int jumpH= heights[i+1]-heights[i];
            if(jumpH > 0){
                if(!pq.empty() && jumpH > pq.top()){
                    // using brick for that smaller jump and consider using ladder for current jump
                    bricks-= pq.top();
                    pq.pop();
                    pq.push(jumpH);
                }
                else{
                    bricks-= jumpH;
                }
            }
            if(bricks<0) return i;
            i++;
        }
        return i;
    }
};
// ```````````````````````````````````small`````````````````````````````````
class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int i;
        for(i=0; i<h.size()-1; i++){
            int diff= h[i+1]-h[i];
            if(diff>0)
                pq.push(diff);
            
            if(pq.size()> ladders){
                    bricks-= pq.top();
                    pq.pop();
            }
            if(bricks<0) return i;
        }
        return i;
    }
};
