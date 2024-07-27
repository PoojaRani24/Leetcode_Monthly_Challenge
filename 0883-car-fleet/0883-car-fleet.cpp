class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>ps;
        int n=position.size();
        for(int i=0;i<n;i++)
            ps.push_back({position[i],speed[i]});
        sort(ps.begin(),ps.end(),greater<pair<int,int>>());
        int fleet=0;
        for(int i=0;i<n;i++){
            fleet++;
            auto p=ps[i];
            double time=double(target-p.first)/double (p.second);
            while(i+1 < n && time>=double(target-ps[i+1].first)/double (ps[i+1].second)){
                i++;
            }
        }
        return fleet;
    }
};