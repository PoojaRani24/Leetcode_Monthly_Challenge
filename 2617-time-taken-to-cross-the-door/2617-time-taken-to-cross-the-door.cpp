class Solution {
public:
    vector<int> timeTaken(vector<int>& arrival, vector<int>& state) {
        int sz = arrival.size(), t = 0, door = 0;
        vector<int> res(sz, 0);
        queue<pair<int,int>> enterQ, exitQ;

        for (int i = 0; i < sz; i++) {
            if (state[i])
                exitQ.push({arrival[i], i});
            else
                enterQ.push({arrival[i], i});                       
        }

        while (!exitQ.empty() || !enterQ.empty()) {
            if ((exitQ.empty() || exitQ.front().first > t) && (enterQ.empty() || enterQ.front().first > t))
                door = 0;
            else if (!exitQ.empty() && exitQ.front().first <= t && (enterQ.empty() || enterQ.front().first > t)) {
                res[exitQ.front().second] = t;
                door = 2;
                exitQ.pop();            
            }
            else if ((exitQ.empty() || exitQ.front().first > t) && !enterQ.empty() && enterQ.front().first <= t) {
                res[enterQ.front().second] = t;
                door = 1;
                enterQ.pop();                
            }
            else {
                if (door == 0 || door == 2) {
                    res[exitQ.front().second] = t;
                    door = 2;
                    exitQ.pop(); 
                } else {
                    res[enterQ.front().second] = t;
                    door = 1;
                    enterQ.pop();  
                }
            }
            t++;
        }
        return res;
    }
};