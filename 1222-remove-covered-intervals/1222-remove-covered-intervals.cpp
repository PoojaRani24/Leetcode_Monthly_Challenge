class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        auto cmp=[&](const vector<int>&a, const vector<int>&b){
            if(a[0]==b[0] && a[1]>b[1])
                return true;
            return a[0]<b[0];
        };
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),cmp);
        int cnt=n, end=intervals[0][1];
        for(auto it=intervals.begin()+1;it!=intervals.end();it++){
            if((*it)[1]<=end)cnt--;
            else end=(*it)[1];
        }
        return cnt;
    }
};