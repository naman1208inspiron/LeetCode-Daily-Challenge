class Solution {
public:
    bool isPossible(vector<int>& target) {
        if (target.size() == 1) return target[0] == 1;
        
        priority_queue<int> pq;
        long long totalsum=0;
        for(int it: target){
            pq.push(it);
            totalsum+= it;
        }
        while(totalsum!= target.size()){
        // while(pq.top()!= 1){
            /*
            9 3 5 came from --> 1 3 5
            how can we get 1 ???
            we can see the array [9, 3, 5] as [ (1+3+5), 3, 5] 
            1 = maxElement - sum of all the remaining elements. 
            */
            int top= pq.top(); pq.pop();
            int restSum= totalsum- top; // sum of all the remaining elements
            
            if(restSum== 1) return true;
            // the above line handles the case of [1, 2], [1, 1000], etc 
            
            int prev=   top % restSum;// the prev element which we replaced 
            // see above as prev= top - restSum. if we subtact the same sum again and again, we are basically findng the remeiander when top is smaller than restSum
            totalsum= totalsum - top + prev;
            
            if(prev == 0 || prev == top) return false;
            // prev==0 when restSum == top
            // prev== top will happen when top< restSum--> top element should always be greaer then the restSum cuz top element was a result of restSum + prev 

            pq.push(prev);
            
        }
        return true;
    }
};
