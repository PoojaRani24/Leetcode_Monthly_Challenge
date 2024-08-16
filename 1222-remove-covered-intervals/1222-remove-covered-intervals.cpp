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
        int cnt=0;
        int i=0;
        while(i<n){
            cnt++;
            int start=intervals[i][0];
            int end=intervals[i][1];
            int j=i+1;
            while(j<n && intervals[j][0]>=start && intervals[j][1]<=end){
                j++;
            }
            i=j;
        }
        return cnt;
    }
};