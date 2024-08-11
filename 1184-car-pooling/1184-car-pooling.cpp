class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>r(1002,0);
        for(int i=0;i<trips.size();i++){
            r[trips[i][1]]+=trips[i][0];
            r[trips[i][2]]-=trips[i][0];
        }

        int passengerCnt=0;
        for(int i=0;i<=1000;i++){
            passengerCnt+=r[i];
            if(passengerCnt>capacity)
                return false;
        }
        return true;
    }
};