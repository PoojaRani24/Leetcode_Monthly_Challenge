class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
        auto cmp=[&](vector<int>&a,vector<int>&b){
            if(a[0]==b[0])
                return a[1]<b[1];
            return a[0]<b[0];
        };
        sort(events.begin(),events.end(),cmp);
        int cnt=0;
        int d=1;
        priority_queue<int,vector<int>,greater<int>>pq;
        int i=0;
        while(!pq.empty() || i<n){
            if(pq.empty())
                d=events[i][0];
            while(i<n && events[i][0]==d){
                pq.push(events[i][1]);
                i++;}
            pq.pop();
            cnt++;
            d++;
            while(!pq.empty() && pq.top()<d)
                pq.pop();
        }
        return cnt;
    }
};