class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        // bool removed=false;
        int n=intervals.size();
        if(n==0)
            return {{}};
        int i=0;
        vector<vector<int>>ans;
        while(i<n){
            if(intervals[i][1]<toBeRemoved[0] || intervals[i][0]>toBeRemoved[1]){
                ans.push_back(intervals[i]);
            }
            else{
                if(intervals[i][0]<toBeRemoved[0])
                    ans.push_back({intervals[i][0],toBeRemoved[0]});
                if(intervals[i][1]>toBeRemoved[1])
                    ans.push_back({toBeRemoved[1],intervals[i][1]});
            }
            i++;
        }
        return ans;
    }
};