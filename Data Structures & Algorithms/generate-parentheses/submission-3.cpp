class Solution {
public:
    void solve(int n,vector<string>&ans,string &str,int open, int close){
        if(str.length()==2*n){
            ans.push_back(str);
            return ;
        }

        if(open < n){
            str.push_back('(');
            solve(n,ans,str,open+1,close);  
            str.pop_back();
        }
        if(close<open){
            str.push_back(')');
            solve(n,ans,str,open,close+1);
            str.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string str;
        solve(n,ans,str,0,0);

        return ans;

    }
};
