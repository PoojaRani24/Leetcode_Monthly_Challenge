class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>m;
        int left=0;
        int n=fruits.size();
        int ans=INT_MIN;
        for(int right=0;right<n;right++){
            m[fruits[right]]++;
            while(m.size()>2){
                m[fruits[left]]--;
                if(m[fruits[left]]==0)
                    m.erase(fruits[left]);
                left++;
            }
            ans=max(ans, right-left+1);
        }
        return ans;
    }
};