class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n=quality.size();
        vector<pair<double,int>>ratio;
        for(int i=0;i<n;i++)
            ratio.push_back({(double)wage[i]/(double)quality[i],quality[i]});
        sort(ratio.begin(),ratio.end());
        priority_queue<int>maxHeap;
        int totalq=0;
        double cost=INT_MAX;
        for(int i=0;i<n;i++){
            double r=ratio[i].first;
            int q=ratio[i].second;
            totalq+=q;
            maxHeap.push(q);
            if(maxHeap.size()>k){
                totalq-=maxHeap.top();
                maxHeap.pop();
            }
            if(maxHeap.size()==k)
                cost=min(cost,r*totalq);
        }
        return cost;
    }
};