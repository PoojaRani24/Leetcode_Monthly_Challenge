class Solution {
public:
    bool isPossible(int mid, vector<int>& tasks, vector<int>& workers, int pills, int strength){
        multiset<int>ms(workers.end()-mid,workers.end());
        for(int i=mid-1;i>=0;i--){
            int task=tasks[i];
            auto worker=--ms.end();
            if(*worker<task){
                if(pills<=0)
                    return false;
                int newStrength=task-strength;
                auto requiredworker=ms.lower_bound(newStrength);
                if(requiredworker==ms.end())
                    return false;
                pills--;
                ms.erase(requiredworker);
            }
            else{
                ms.erase(worker);
            }
        }
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        // sort tasks and workersu
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end());
        int n=min(tasks.size(),tasks.size());
        int m=min(workers.size(),workers.size());
        int l=0, h=min(n,m);
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(isPossible(mid, tasks, workers, pills, strength)){
                ans=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return ans;
    }
};