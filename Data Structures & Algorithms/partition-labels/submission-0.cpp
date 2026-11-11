class Solution {
public:

    int countfr(unordered_set<char>& s,unordered_map<char,int>&mp){
        int total =0;

        for(auto &i:s){
            total+=mp[i];
        }

        return total;
    }
    vector<int> partitionLabels(string s) {
        vector<int>ans;

        unordered_map<char,int>mp;

        int n=0;
        for(auto &i:s){
            n++;
            mp[i]++;
        }

        int l=0,r=0;

        unordered_set<char>st;

        while(r<n){
            
            st.insert(s[r]);

            mp[s[r]]--;
            
            if(!countfr(st,mp)){
                st.clear();
                ans.push_back(r-l+1);
                l=r+1;
            }
            r++;

        }


        return ans;
    }
};
