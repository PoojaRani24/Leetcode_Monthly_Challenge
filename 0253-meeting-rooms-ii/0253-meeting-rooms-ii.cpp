class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int,int>m;
        for(int i=0;i<intervals.size();i++){
            m[intervals[i][0]]++;
            m[intervals[i][1]]--;
        }

        int curSum=0, maxSum=INT_MIN;
        for(auto it:m){
            curSum+=it.second;
            maxSum=max(maxSum,curSum);
        }
        return maxSum;
    }
};