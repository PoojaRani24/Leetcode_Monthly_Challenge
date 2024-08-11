class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        auto cmp=[&](const vector<int>&a, const vector<int>&b){
            return a[1]<b[1];
        };
        int cnt=0;
        sort(intervals.begin(),intervals.end(),cmp);
        int end=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=end)
                end=intervals[i][1];
            else
                cnt++;
        }
        return cnt;
    }
};