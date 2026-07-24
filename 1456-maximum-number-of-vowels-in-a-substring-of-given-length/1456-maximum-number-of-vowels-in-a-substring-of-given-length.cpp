class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<int>st;
        st={'a','e','i','o','u'};
        int left=0;
        int n=s.size();
        int cnt=0;
        int tot=INT_MIN;
        for(int right=0;right<n;right++){
            if(st.count(s[right]))
                cnt++;
            if(right-left+1 > k){
                if(st.count(s[left]))
                    cnt--;
                left++;
            }
            if(right-left+1 == k)
                tot=max(tot,cnt);
        }
        return tot;
    }
};