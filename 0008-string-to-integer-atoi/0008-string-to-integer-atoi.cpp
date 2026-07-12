class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n=s.size();

        while(i<n && s[i]==' ')
            i++;
        
        int sign=1;
        if(i<n && (s[i]=='+' || s[i]=='-')){
            if(s[i]=='-')
                sign=-1;
            i++;
        }

        int ans=0;
        while(i<n && isdigit(s[i])){
            int dig = s[i] -  '0';
            if(ans>(INT_MAX-dig)/10){
                if(sign==1)
                    return INT_MAX;
                return INT_MIN;
            }
            ans=ans*10+dig;
            i++;
        }
        return sign*ans;
    }
};