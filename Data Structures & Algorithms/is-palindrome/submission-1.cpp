class Solution {
public:

    bool ispal(string s){
        int n= s.length();
        int i=0,j=n-1;

        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }

        return true;
        
    }
    bool isPalindrome(string s) {
        string temp="";
        for(auto &i:s){
            if(isalnum(i)){
                char ch=tolower(i);
                temp+=ch;
            }
        }

        return ispal(temp);
        
    }
};
