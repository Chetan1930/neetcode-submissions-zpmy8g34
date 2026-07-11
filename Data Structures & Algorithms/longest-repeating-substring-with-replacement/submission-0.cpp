class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int l=0,ans=0;
        set<char>s1;
        int rem=k;

        for(int r=0;r<n;r++){
           if(s1.size()==0)s1.insert(s[r]);

           if(*s1.begin()!=s[r]){
            if(rem>0) rem--; 
            else{
            l++;
            r=l;
            rem=k;
            s1.clear();
            s1.insert(s[r]);
            }
           }         

            ans=max(ans,r-l+1);
        }

        return ans;
    }
};
