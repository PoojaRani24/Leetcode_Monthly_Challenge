class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>pq;
        int cnt=0;
        for(auto it: nums){
            pq.push(it);
            cnt++;
            if(cnt>k){
                pq.pop();
                cnt--;
            }
        }
        return pq.top();
    }
};