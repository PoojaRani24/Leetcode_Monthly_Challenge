class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int>year(101,0);
        for(int i=0;i<logs.size();i++){
            year[logs[i][0]%1950]+=1;
            year[logs[i][1]%1950]-=1;
        }
        int maxi=INT_MIN, curMax=0,maximumPopulationYear=1950;
        for(int i=0;i<101;i++){
            curMax+=year[i];
            if(maxi<curMax){
                maxi=curMax;
                maximumPopulationYear=i+1950;
            }
        }
        return maximumPopulationYear;
    }
};