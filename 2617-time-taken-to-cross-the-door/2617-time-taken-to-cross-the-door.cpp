class Solution {
public:
    vector<int> timeTaken(vector<int>& arrival, vector<int>& state) {
        queue<pair<int,int>>enter,exit;
        int n=arrival.size();
        for(int i=0;i<n;i++){
            if(state[i]==1)
                exit.push({arrival[i],i});
            else
                enter.push({arrival[i],i});
        }

        int time=0, s=0;
        vector<int>ans(n,0);
        while(!enter.empty() || !exit.empty()){
            if((enter.empty() || enter.front().first>time) && (exit.empty() || exit.front().first>time)){
                time = min(enter.empty() ? INT_MAX : enter.front().first, exit.empty() ? INT_MAX : exit.front().first);
                s=0;
                // time++;
            }
            else if(!enter.empty() && enter.front().first<=time && (exit.empty() || exit.front().first>time)){
                ans[enter.front().second]=time;
                s=1;
                enter.pop();
                time++;
            }
            else if(!exit.empty() && exit.front().first<=time && (enter.empty() || enter.front().first>time)){
                ans[exit.front().second]=time;
                s=2;
                exit.pop();
                time++;
            }
            else{
                if(s==1){
                    ans[enter.front().second]=time;
                    enter.pop();
                    s=1;
                }
                else{
                    ans[exit.front().second]=time;
                    exit.pop();
                    s=2;
                }
                time++;
            }
        }
        return ans;
    }
};