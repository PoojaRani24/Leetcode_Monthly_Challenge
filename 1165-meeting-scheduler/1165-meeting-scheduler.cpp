class Solution {
public:
    void preprocessAvailability(vector<vector<int>>& slots,map<int,int>&m){
        for(auto it:slots){
            m[it[0]]++;
            m[it[1]+1]--;
        }
    }

    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        map<int,int>m;
        preprocessAvailability(slots1,m);
        preprocessAvailability(slots2,m);
        int currentAvailabilityCnt=0, prevAvailabilityCnt=0,currentStartTime=-1,prevStartTime=-1;
        for(auto it:m){
            currentStartTime=it.first;
            currentAvailabilityCnt+=it.second;
            if(prevStartTime!=-1 && currentAvailabilityCnt<2 && prevAvailabilityCnt==2 && currentStartTime-prevStartTime-1>=duration)
                return {prevStartTime, prevStartTime+duration};
            prevStartTime=currentStartTime;
            prevAvailabilityCnt=currentAvailabilityCnt;
        }
        return {};
    }
};