class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();


        if(n>m)return false;


       vector<int> s11(26,0);
        vector<int> s22(26,0);

        
        for(auto &i:s1){
            s11[i-'a']++;
        }

        int l=0;
        int r=n-1;

        for(int i=0;i<n;i++){
            s22[s2[i]-'a']++;
        }


        while(r<m){
            if(s11==s22)return true;
            s22[s2[l]-'a']--;

            l++;
            r++;
            if(r < m)
                s22[s2[r]-'a']++;

        }
        
        
        return false;

    }
};
