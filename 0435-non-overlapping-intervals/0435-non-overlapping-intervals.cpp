class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), 
            [](auto &a, auto &b){
                return a[1]<b[1];
            });
        
        int prev_end=intervals[0][1];
        int remove=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<prev_end)
                remove++;
            else
                prev_end=intervals[i][1];
        }
        return remove;
    }
};