class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int size1=s.length();
        int size2=t.length();

        if(size1!=size2)return false;
        else{
            int totalSum1 = 0;
            for(int i=0;i<size1;i++){
                totalSum1+=s[i]-'0';
            }

            int totalSum2 = 0;
            for(int i=0;i<size2;i++){
                totalSum2+=t[i]-'0';
            }

            if(totalSum1 != totalSum2)return false;
        }
        return true;
    }
};
