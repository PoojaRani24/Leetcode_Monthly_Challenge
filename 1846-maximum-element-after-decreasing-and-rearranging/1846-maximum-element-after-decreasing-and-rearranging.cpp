class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int curr=1;
        sort(arr.begin(),arr.end());
        for(int i=1;i<arr.size();i++){
            curr=min((curr+1),arr[i]);
        }
        return curr;
    }
};