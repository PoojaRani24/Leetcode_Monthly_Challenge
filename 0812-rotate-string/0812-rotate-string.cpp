class Solution {
public:
    bool rotateString(string s, string goal) {
       int l=s.length();
       while(l--){
        s=s.substr(1)+s[0];
        if(s==goal)
            return true;
       }
       return false;
    }
};