class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        bool pushed=false;
        int n=intervals.size();
        if(n==0)
            return {newInterval};
        int i=0;
        vector<vector<int>>ans;
        while(i<n){
            if(pushed){
                ans.push_back(intervals[i]);
                i++;
            }
            else if(newInterval[1]<intervals[i][0]){
                ans.push_back(newInterval);
                ans.push_back(intervals[i]);
                pushed=true;
                i++;
            }
            else if(intervals[i][1]<newInterval[0]){
                ans.push_back(intervals[i]);
                i++;
            }
            else{
                newInterval[0]=min(newInterval[0], intervals[i][0]);
                newInterval[1]=max(newInterval[1], intervals[i][1]);
                i++;
            }
        }
        if(!pushed)
            ans.push_back(newInterval);
        return ans;
    }
};