class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(),slots1.end());
        sort(slots2.begin(),slots2.end());
        int i=0,j=0,n=slots1.size(),m=slots2.size();
        while(i<n && j<m){
            int start=max(slots1[i][0],slots2[j][0]);
            int end=min(slots1[i][1],slots2[j][1]);
            if(start<end && (end-start)>=duration)return {start, start+duration};
            if(slots1[i][1]<slots2[j][1])i++;
            else j++;
        }
        return {};
    }
};