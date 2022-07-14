class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        for(int i=0; i<heights.size()-1; i++){
            int diff = heights[i+1]-heights[i];
            if(diff>0){
                pq.push(-diff);
            }
            if(pq.size()>ladders){
                bricks += pq.top(); //using bricks, getting rid of the smallest with bricks
                pq.pop();
            }
            if(bricks<0){
                return i;
            }
        }
        return heights.size()-1;
    }
};