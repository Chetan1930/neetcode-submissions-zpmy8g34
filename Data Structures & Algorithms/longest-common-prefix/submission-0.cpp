class Solution {
public:
    string commanPrefix(string s, string t){
        int n=s.length();
        int m=t.length();

        int minLen =min(n,m);

        string ans = "";
        for(int i=0;i<n;i++){
            if(s[i]==t[i]){
                ans+=s[i];
            }
            else{
                return ans;
            }
        }
        return ans;
    }
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size()==1)return strs[0];

        string ans ="";

        for(int i=1;i<strs.size();i++){
            
            string temp = "";
            if(ans =="")temp = commanPrefix(strs[i],strs[i-1]);
            else temp = commanPrefix(strs[i],ans);
             
            if(temp == "")return temp;

            ans = temp;
        }

        return ans;
    }
};