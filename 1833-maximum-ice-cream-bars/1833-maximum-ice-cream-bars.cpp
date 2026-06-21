class Solution {
public:
    int maxIceCreamII(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int maxIceCreamCnt=0;
        for(int i=0;i<costs.size();i++){
            if(coins-costs[i]>=0){
                coins-=costs[i];
                maxIceCreamCnt++;
            }
        }
        return maxIceCreamCnt;
    }

    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        int range = 0;
        for(int i=0;i<n;i++)
            range = max(range, costs[i]);
        vector<int>freq(range+1,0);
        for(int i=0;i<n;i++)
            freq[costs[i]]++;
        int ans=0;
        for(int i=1;i<=range && coins>0;i++){
            int pick = min(coins/i, freq[i]);
            ans = ans + pick;
            coins-=(pick*i);
        }
        return ans;

    }
};