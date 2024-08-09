class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int>r(52,0);
        for(int i=0;i<ranges.size();i++){
            r[ranges[i][0]]++;
            r[ranges[i][1]+1]--;
        }

        int sum=0;
        for(int i=1;i<=50;i++){
            sum+=r[i];
            if(i>=left && i<=right && sum<=0)return false;
        }
        return true;
    }
};