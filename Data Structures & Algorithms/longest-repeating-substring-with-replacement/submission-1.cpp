class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int l=0,ans=0;
        int maxf=0;
        unordered_map<char,int>mp;
    
        for(int r=0;r<n;r++){
            mp[s[r]]++;
            maxf = max(maxf,mp[s[r]]);

            while( (r-l+1)-maxf > k){
                mp[s[l]]--;
                l++;
            }

             ans=max(ans,r-l+1);
           
        }

        return ans;
    }
};
