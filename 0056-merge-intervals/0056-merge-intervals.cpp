class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>ans;
        for(int i=0;i<intervals.size();i++){
            if(ans.empty() || ans.back()[1]<intervals[i][0])
                ans.push_back(intervals[i]);
            else
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
        }
        return ans;
    }
};