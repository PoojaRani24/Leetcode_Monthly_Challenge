class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        if (n1 > n2)
            return false;

        vector<int>m1(26,0), m2(26,0);
        for(int i=0;i<n1;i++)
            m1[s1[i]-'a']++;

        int left=0;
        for(int right=0;right<n2;right++){
            m2[s2[right]-'a']++;
            while(right-left+1 > n1){
                m2[s2[left]-'a']--;
                left++;
            }
            if(right-left+1 == n1 && m1==m2)
                return true;
        }
        return false;
    }
};