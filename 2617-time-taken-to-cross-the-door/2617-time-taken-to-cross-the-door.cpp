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

        int time=0, s=1;
        vector<int>ans(n,0);
        while(!enter.empty() || !exit.empty()){
            if((enter.empty() || enter.front().first>time) && (exit.empty() || exit.front().first>time)){
                time = min(enter.empty() ? INT_MAX : enter.front().first, exit.empty() ? INT_MAX : exit.front().first);
                s=1;
            }
            else if(!enter.empty() && enter.front().first<=time && (exit.empty() || exit.front().first>time)){
                ans[enter.front().second]=time;
                s=0;
                enter.pop();
                time++;
            }
            else if(!exit.empty() && exit.front().first<=time && (enter.empty() || enter.front().first>time)){
                ans[exit.front().second]=time;
                s=1;
                exit.pop();
                time++;
            }
            else{
                if(s==0){
                    ans[enter.front().second]=time;
                    enter.pop();
                }
                else{
                    ans[exit.front().second]=time;
                    exit.pop();
                }
                time++;
            }
        }
        return ans;
    }
};