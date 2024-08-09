class Solution {
public:
    int meetRequirement(int n, vector<vector<int>>& lights, vector<int>& requirement) {
        vector<int>brightness(n,0);
        for(int i=0;i<lights.size();i++){
            int start=max(0,lights[i][0]-lights[i][1]);
            int end=min(n,lights[i][0]+lights[i][1]+1);
            brightness[start]++;
            if(end<n)
                brightness[end]--;
        }

        int cnt=0;
        int bright=0;
        for(int i=0;i<n;i++){
            bright+=brightness[i];
            cout<<i<<" "<<bright<<endl;
            if(bright>=requirement[i])
                cnt++;
        }
        return cnt;
    }
};