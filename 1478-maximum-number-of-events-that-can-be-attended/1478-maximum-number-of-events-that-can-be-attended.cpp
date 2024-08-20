class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int n=events.size(), d=1, i=0, cnt=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        while(!pq.empty() || i<n){
            if(pq.empty())
                d=events[i][0];
            while(i<n && events[i][0]==d){
                pq.push(events[i][1]);
                i++;
            }
            d++;
            cnt++;
            pq.pop();
            while(!pq.empty() && pq.top()<d)
                pq.pop();
        }
        return cnt;
    }
};