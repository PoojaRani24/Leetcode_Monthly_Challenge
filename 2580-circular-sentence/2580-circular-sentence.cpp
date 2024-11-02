class Solution {
public:
    bool isCircularSentence(string sentence) {
        if(sentence.length()==0)
            return true;
        char begining=sentence[0];
        int i=0;
        for(i=0;i<sentence.length();i++){
            char ch=sentence[i];
            if(ch==' ' && sentence[i-1]!=sentence[i+1])
                return false;
        }
        return sentence[i-1]==begining;
    }
};