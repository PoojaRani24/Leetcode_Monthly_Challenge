#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            auto it = m.find(nums[i]);
            if(it!=m.end() && i-it->second<= k){
                    return true;
            }
            m[nums[i]] = i;
        }
        return false;
    }
};