class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n==0)
            return true;
        auto cmp=[&](const vector<int>&a, const vector<int>& b){
            return a[1]<b[1];
        };
        sort(intervals.begin(),intervals.end(),cmp);
        int end=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<end)
                return false;
            end=intervals[i][1];
        }
        return true;
    }
};